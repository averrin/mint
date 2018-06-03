#include <regex>
#include <string>
#include <iostream>

#include "cinder/Rand.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "CinderPango.h"
#include "mint/steps.hpp"
#include "mint/state.hpp"
#include "mint/modes.hpp"

#include "mint/ui/statusLine.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

int HOffset = 24;
int VOffset = 24;
// std::string DEFAULT_FONT = "Iosevka 14";
std::string DEFAULT_FONT = "FiraCode 12";

class MintApp : public App {
public:
	void setup() override;
	void mouseDown(MouseEvent event) override;
	void update() override;
	void keyDown(KeyEvent event) override;
	void draw() override;

	kp::pango::CinderPangoRef mPango;
	kp::pango::CinderPangoRef statusFrame;
    std::shared_ptr<Steps> steps;
    ModeManager modeManager = ModeManager();
    std::shared_ptr<HintsMode> hints;
    std::shared_ptr<StatusLine> statusLine;
};

void MintApp::setup() {
	kp::pango::CinderPango::setTextRenderer(kp::pango::TextRenderer::FREETYPE);
	mPango = kp::pango::CinderPango::create();
	mPango->setMinSize(100, 100);
	mPango->setMaxSize(getWindowWidth(), getWindowHeight());

	statusFrame = kp::pango::CinderPango::create();
	statusFrame->setMinSize(getWindowWidth(), StatusLine::HEIGHT);
	statusFrame->setMaxSize(getWindowWidth(), StatusLine::HEIGHT);

    steps = std::make_shared<Steps>();
    steps->state->currentPalette = palettes::DARK;

    hints = std::make_shared<HintsMode>(steps);

    statusLine = std::make_shared<StatusLine>(steps->state);
    statusLine->setContent(State::normal_mode);

    steps->start();
}

void MintApp::mouseDown(MouseEvent event) {
    steps->processMouse(event);
}

void MintApp::keyDown(KeyEvent event) {


    if (modeManager.modeFlags->isHints) {
        auto handled = hints->processKey(event);
        if (handled) {
            if (!hints->activated) {
                modeManager.toNormal();
                statusLine->setContent(State::normal_mode);
            }
            return;
        }
    }

    modeManager.processKey(event);
    steps->processKey(event);

    if (modeManager.modeFlags->isNormal) {
        statusLine->setContent(State::normal_mode);
    } else if (modeManager.modeFlags->isHints) {
        hints->activated = true;
        statusLine->setContent(State::hints_mode);
    } else if (modeManager.modeFlags->isLeader) {
        statusLine->setContent(State::leader_mode);
    }

	switch (event.getCode()) {
		case KeyEvent::KEY_q:
            exit(0);
			break;
		case KeyEvent::KEY_r:
            // State::greeting[0]->template_str = "!!!";
			break;
		case KeyEvent::KEY_t:
            steps->state->currentPalette = steps->state->currentPalette.name == palettes::DARK.name ?
                palettes::LIGHT : palettes::DARK;
			break;
		default:
			break;
	}
}

void MintApp::update() {
	if (mPango != nullptr) {

        steps->state->render(mPango);

	}

    //TODO: hide into statusBar. Implement padding
	if (statusFrame != nullptr) {

		statusFrame->setText(steps->state->renderStatus());

        statusFrame->setDefaultTextColor(Color(steps->state->currentPalette.fgColor));
        statusFrame->setDefaultTextFont(DEFAULT_FONT);
        statusFrame->setBackgroundColor(Color(steps->state->currentPalette.bgColorAlt));
		statusFrame->render();
    }
}

void MintApp::draw() {
	gl::clear(steps->state->currentPalette.bgColor);
	gl::enableAlphaBlendingPremult();

	if (mPango != nullptr) {
		gl::draw(mPango->getTexture(), vec2(HOffset, VOffset));
	}
	if (statusFrame != nullptr) {
		gl::draw(statusFrame->getTexture(), vec2(0, getWindowHeight()-StatusLine::HEIGHT));
	}

    if (modeManager.modeFlags->isHints) {
            for (auto [key, f] : hints->getLinks()) {
                auto x = f->rect.x + f->rect.width + HOffset - 12;
                auto y = f->rect.y + f->rect.height + VOffset - 6;

                //TODO: cache hints surfaces 
                //TODO: use palette color for hints
                auto hint = kp::pango::CinderPango::create();
                hint->setMinSize(20, 20);
                hint->setText("<b>["+key+"]</b>");
                hint->setDefaultTextColor(steps->state->currentPalette.fgColor);
                hint->setDefaultTextFont(DEFAULT_FONT);
                hint->setBackgroundColor(Color(steps->state->currentPalette.bgColor));
                hint->render();

                gl::draw(hint->getTexture(), vec2(x, y));
            }
        }
}

CINDER_APP(MintApp, RendererGl)
