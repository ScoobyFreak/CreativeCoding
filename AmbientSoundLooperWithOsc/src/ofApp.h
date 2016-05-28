#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxOsc.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void checkButtonPlayer(ofxToggle button, ofSoundPlayer player);
		void sendMessage();

		ofxToggle AngelArpButton;
		ofxToggle BirdsButton;
		ofxToggle CatchyArpButton;
		ofxToggle ChimesButton;
		ofxToggle CicadaButton;
		ofxToggle CityCenterButton;
		ofxToggle DivaArpButton;
		ofxToggle FireplaceButton;
		ofxToggle FrogsButton;
		ofxToggle GlitchArpButton;
		ofxToggle MoonArpButton;
		ofxToggle Space1Button;
		ofxToggle Space2Button;
		ofxToggle Space3Button;
		ofxToggle Space4Button;
		ofxToggle StormButton;
		ofxToggle WavesButton;
		
		ofxPanel ArpGui;
		ofxPanel NatureGui;
		ofxPanel SpaceGui;

		ofSoundPlayer AngelArp;
		ofSoundPlayer Birds;
		ofSoundPlayer CatchyArp;
		ofSoundPlayer Chimes;
		ofSoundPlayer Cicada;
		ofSoundPlayer CityCenter;
		ofSoundPlayer DivaArp;
		ofSoundPlayer Fireplace;
		ofSoundPlayer Frogs;
		ofSoundPlayer GlitchArp;
		ofSoundPlayer MoonArp;
		ofSoundPlayer Space1;
		ofSoundPlayer Space2;
		ofSoundPlayer Space3;
		ofSoundPlayer Space4;
		ofSoundPlayer Storm;
		ofSoundPlayer Waves;

		ofxOscReceiver reciever1;

		ofxOscSender sender1;

		ofxPanel SendGui;
		ofxButton send;
};
