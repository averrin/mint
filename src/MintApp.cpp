#include "cinder/Rand.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "CinderPango.h"
#include "mint/steps.hpp"
#include "mint/state.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

int HOffset = 4;
int VOffset = 4;

class MintApp : public App {
public:
	void setup() override;
	void mouseDown(MouseEvent event) override;
	void update() override;
	void keyDown(KeyEvent event) override;
	void draw() override;

	kp::pango::CinderPangoRef mPango;
    std::shared_ptr<Steps> steps;
};

void MintApp::setup() {
	kp::pango::CinderPango::setTextRenderer(kp::pango::TextRenderer::FREETYPE);
	mPango = kp::pango::CinderPango::create();
	mPango->setMinSize(100, 100);
	mPango->setMaxSize(getWindowWidth(), getWindowHeight());

    steps = std::make_shared<Steps>();
    steps->start();
}

void MintApp::mouseDown(MouseEvent event) {
	// mPango->setMaxSize(event.getPos());
}

void MintApp::keyDown(KeyEvent event) {

	switch (event.getCode()) {
		case KeyEvent::KEY_ESCAPE:
            exit(0);
			break;
		case KeyEvent::KEY_UP:
			mPango->setSpacing(mPango->getSpacing() + 1.0);
			break;
		case KeyEvent::KEY_DOWN:
			mPango->setSpacing(mPango->getSpacing() - 1.0);
			break;
		case KeyEvent::KEY_i:
			mPango->setDefaultTextItalicsEnabled(!mPango->getDefaultTextItalicsEnabled());
			break;
		default:
			break;
	}
}

void MintApp::update() {
	if (mPango != nullptr) {

		mPango->setText(
            steps->state->text
        );

		// Only renders if it needs to
        mPango->setDefaultTextColor(Color(0.9, 0.9, 0.9));
        mPango->setDefaultTextFont("Iosevka 14");
		mPango->render();
	}
}

void MintApp::draw() {
	// float bgColor = (0.5 + 0.5 * sin(0.5 * getElapsedSeconds()));
	gl::clear(Color(0.1, 0.1, 0.1));
	gl::enableAlphaBlendingPremult();

	if (mPango != nullptr) {
		gl::draw(mPango->getTexture(), vec2(HOffset, VOffset));
	}
}

CINDER_APP(MintApp, RendererGl)
