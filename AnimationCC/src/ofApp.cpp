#include "ofApp.h"


void drawFace(int myX, int myY) {
	ofSetColor(150, 255, 20);
	ofDrawCircle(myX, myY, 100);
	ofSetColor(255, 255, 255);
	ofDrawCircle(myX - 50, myY - 25, 25);
	ofDrawCircle(myX + 50, myY - 25, 25);
	ofSetColor(0, 0, 0);
	ofDrawCircle(myX - 55, myY - 30, 10);
	ofDrawCircle(myX + 55, myY - 18, 10);
	ofDrawCircle(myX, myY + 40, 50);
	ofSetColor(200, 20, 20);
	ofDrawEllipse(myX, myY + 70, 75, 37);
	ofSetColor(0, 0, 0);
	ofDrawRectangle(myX - 75, myY - 50, 50, 10);
	ofDrawRectangle(myX + 25, myY - 50, 50, 10);
	ofSetColor(0, 0, 255);
	ofSetLineWidth(8);
	ofDrawLine(myX - 50, myY - 150, myX, myY - 75);
	ofDrawLine(myX + 20, myY - 150, myX, myY - 75);
	ofDrawLine(myX - 10, myY - 175, myX, myY - 75);
}

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetCircleResolution(50);
	x = 50;
	y = ofGetHeight()/2;

	velocityX = 10;
	velocityY = 0;

	ex = ofGetWidth() / 2;
	ey = ofGetHeight() / 2;
	easing = .05;

}

//--------------------------------------------------------------
void ofApp::update(){
	x += velocityX;
	y += velocityY;
	if (x > ofGetWidth() + 50) {
		x = -50;
	}
	if (x < -50) {
		x = ofGetWidth() + 50;
	}
	if (y > ofGetHeight() + 50) {
		y = -50;
	}
	if (ofDist(x, y, ex, ey) < 75) {
		velocityX *= -1;
	}

	ex = ex + (ofGetMouseX() - ex) *easing;
	ey = ey + (ofGetMouseY() - ey) *easing;
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(200, 100, 100);
	ofDrawCircle(x, y, 50);

	ofSetColor(ofColor::darkBlue);
	ofDrawCircle(ex, ey, 25);
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
