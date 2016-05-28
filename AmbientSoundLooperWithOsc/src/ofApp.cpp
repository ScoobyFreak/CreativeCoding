#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);

	reciever1.setup(9001);

	sender1.setup("10.5.37.10", 9002);

	SendGui.setup("Press to Send");
	SendGui.add(send.setup("Send Info"));
	SendGui.setPosition(20, 125);

	ArpGui.setup("Arpeggiators");
	ArpGui.add(AngelArpButton.setup("Angel Arp", false));
	ArpGui.add(CatchyArpButton.setup("Catchy Arp", false));
	ArpGui.add(DivaArpButton.setup("Diva Arp", false));
	ArpGui.add(GlitchArpButton.setup("Glitch Arp", false));
	ArpGui.add(MoonArpButton.setup("Moon Arp", false));
	ArpGui.setPosition(20, 10);

	NatureGui.setup("Nature Sounds");
	NatureGui.add(BirdsButton.setup("Birds", false));
	NatureGui.add(ChimesButton.setup("Chimes", false));
	NatureGui.add(CicadaButton.setup("Cicadas", false));
	NatureGui.add(CityCenterButton.setup("City Center", false));
	NatureGui.add(FireplaceButton.setup("Fireplace", false));
	NatureGui.add(FrogsButton.setup("Frogs", false));
	NatureGui.add(StormButton.setup("Storm", false));
	NatureGui.add(WavesButton.setup("Waves", false));
	NatureGui.setPosition(230, 10);

	SpaceGui.setup("Space Sounds");
	SpaceGui.add(Space1Button.setup("Space 1", false));
	SpaceGui.add(Space2Button.setup("Space 2", false));
	SpaceGui.add(Space3Button.setup("Space 3", false));
	SpaceGui.add(Space4Button.setup("Space 4", false));
	SpaceGui.setPosition(440, 10);

	AngelArp.load("AngelArp.wav");
	Birds.load("Birds.wav");
	Birds.setVolume(.6);
	CatchyArp.load("CatchyArp.wav");
	CatchyArp.setVolume(.7);
	Chimes.load("Chimes.mp3");
	Chimes.setVolume(.6);
	Cicada.load("Cicada.mp3");
	Cicada.setVolume(.6);
	CityCenter.load("CityCenter.mp3");
	DivaArp.load("DivaArp.wav");
	DivaArp.setVolume(.7);
	Fireplace.load("Fireplace.mp3");
	Frogs.load("Frogs.mp3");
	Frogs.setVolume(.7);
	GlitchArp.load("GlitchArp.wav");
	GlitchArp.setVolume(.7);
	MoonArp.load("MoonArp.wav");
	MoonArp.setVolume(.7);
	Space1.load("Space1.mp3");
	Space1.setVolume(.6);
	Space2.load("Space2.mp3");
	Space2.setVolume(.6);
	Space3.load("Space3.mp3");
	Space3.setVolume(.6);
	Space4.load("Space4.mp3");
	Space4.setVolume(.6);
	Storm.load("Storm.mp3");
	Waves.load("Waves.mp3");
	Waves.setVolume(.25);

	AngelArp.setLoop(true);
	Birds.setLoop(true);
	CatchyArp.setLoop(true);
	Chimes.setLoop(true);
	Cicada.setLoop(true);
	CityCenter.setLoop(true);
	DivaArp.setLoop(true);
	Fireplace.setLoop(true);
	GlitchArp.setLoop(true);
	MoonArp.setLoop(true);
	Space1.setLoop(true);
	Space2.setLoop(true);
	Space3.setLoop(true);
	Space4.setLoop(true);
	Frogs.setLoop(true);
	Storm.setLoop(true);
	Waves.setLoop(true);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (send)
		sendMessage();
	if (reciever1.hasWaitingMessages()) {
		ofxOscMessage message;
		if (reciever1.getNextMessage(message)) {
			if (message.getAddress() == "/button/check") {
				if (AngelArp.isPlaying() == false)
					AngelArpButton = message.getArgAsBool(0);
				if (Birds.isPlaying() == false)
					BirdsButton = message.getArgAsBool(1);
				if (CatchyArp.isPlaying() == false)
					CatchyArpButton = message.getArgAsBool(2);
				if (Chimes.isPlaying() == false)
					ChimesButton = message.getArgAsBool(3);
				if (Cicada.isPlaying() == false)
					CicadaButton = message.getArgAsBool(4);
				if (CityCenter.isPlaying() == false)
					CityCenterButton = message.getArgAsBool(5);
				if (DivaArp.isPlaying() == false)
					DivaArpButton = message.getArgAsBool(6);
				if (Fireplace.isPlaying() == false)
					FireplaceButton = message.getArgAsBool(7);
				if (GlitchArp.isPlaying() == false)
					GlitchArpButton = message.getArgAsBool(8);
				if (MoonArp.isPlaying() == false)
					MoonArpButton = message.getArgAsBool(9);
				if (Space1.isPlaying() == false)
					Space1Button = message.getArgAsBool(10);
				if (Space2.isPlaying() == false)
					Space2Button = message.getArgAsBool(11);
				if (Space3.isPlaying() == false)
					Space3Button = message.getArgAsBool(12);
				if (Space4.isPlaying() == false)
					Space4Button = message.getArgAsBool(13);
				if (Frogs.isPlaying() == false)
					FrogsButton = message.getArgAsBool(14);
				if (Storm.isPlaying() == false)
					StormButton = message.getArgAsBool(15);
				if (Waves.isPlaying() == false)
					WavesButton = message.getArgAsBool(16);
			}
		}
	}
	checkButtonPlayer(AngelArpButton, AngelArp);
	checkButtonPlayer(BirdsButton, Birds);
	checkButtonPlayer(CatchyArpButton, CatchyArp);
	checkButtonPlayer(ChimesButton, Chimes);
	checkButtonPlayer(CicadaButton, Cicada);
	checkButtonPlayer(CityCenterButton, CityCenter);
	checkButtonPlayer(DivaArpButton, DivaArp);
	checkButtonPlayer(FireplaceButton, Fireplace);
	checkButtonPlayer(GlitchArpButton, GlitchArp);
	checkButtonPlayer(MoonArpButton, MoonArp);
	checkButtonPlayer(Space1Button, Space1);
	checkButtonPlayer(Space2Button, Space2);
	checkButtonPlayer(Space3Button, Space3);
	checkButtonPlayer(Space4Button, Space4);
	checkButtonPlayer(FrogsButton, Frogs);
	checkButtonPlayer(StormButton, Storm);
	checkButtonPlayer(WavesButton, Waves);
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ArpGui.draw();
	NatureGui.draw();
	SpaceGui.draw();
	SendGui.draw();
}

//--------------------------------------------------------------
void ofApp::checkButtonPlayer(ofxToggle button, ofSoundPlayer player) {
	if (button && !player.isPlaying()) {
		player.play();
	}
	else if (!button && player.isPlaying()) {
		player.stop();
	}


}

void ofApp::sendMessage() {
	ofxOscMessage message;
	message.setAddress("/button/check");
	message.addBoolArg(AngelArp.isPlaying());
	message.addBoolArg(Birds.isPlaying());
	message.addBoolArg(CatchyArp.isPlaying());
	message.addBoolArg(Chimes.isPlaying());
	message.addBoolArg(Cicada.isPlaying());
	message.addBoolArg(CityCenter.isPlaying());
	message.addBoolArg(DivaArp.isPlaying());
	message.addBoolArg(Fireplace.isPlaying());
	message.addBoolArg(GlitchArp.isPlaying());
	message.addBoolArg(MoonArp.isPlaying());
	message.addBoolArg(Space1.isPlaying());
	message.addBoolArg(Space2.isPlaying());
	message.addBoolArg(Space3.isPlaying());
	message.addBoolArg(Space4.isPlaying());
	message.addBoolArg(Frogs.isPlaying());
	message.addBoolArg(Storm.isPlaying());
	message.addBoolArg(Waves.isPlaying());
	sender1.sendMessage(message);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
