#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	gui.setup();
	gui.add(size.setup("size", 25, 10, 100));

	ofSetVerticalSync(true);
	ofBackgroundHex(0xfdefc2);
	ofSetLogLevel(OF_LOG_NOTICE);

	box2d.init();
	box2d.setGravity(0, 10);
	//box2d.createGround();
	box2d.createBounds();
	box2d.setFPS(60.0);
	box2d.registerGrabbing();

	edgeLine.setPhysics(0.0, 0.5, 0.5);
	edgeLine.create(box2d.getWorld());
	
	mp = false;
}

//--------------------------------------------------------------
void ofApp::update() {
	ofRemove(circles, ofxBox2dBaseShape::shouldRemoveOffScreen);
	box2d.update();

	if(mp){
	circles.push_back(shared_ptr<ofxBox2dCircle>(new ofxBox2dCircle));
	circles.back().get()->setPhysics(3.0, 0.53, 0.1);
	circles.back().get()->setup(box2d.getWorld(), mouseX, mouseY, size);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i<circles.size(); i++) {
		ofFill();
		ofSetHexColor(0x90d4e3);
		circles[i].get()->draw();
	}
	gui.draw();

	ofSetColor(0);
	ofDrawBitmapString("Entities: " + ofToString(circles.size()), 20, 75);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	circles.clear();
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
	mp = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	mp = false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	box2d.createBounds();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
