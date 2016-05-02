#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetFrameRate(30);

	// First we load credentials from a file. These can also be loaded manually
	// using the ofxTwitter::Credentials constructor.
	//
	// Developers must get their credentials after creating an app at https://apps.twitter.com
	auto credentials = ofxHTTP::OAuth10Credentials::fromFile("credentials.json");

	// Next we add our credentials to our ofxTwitter::RESTClient.
	client.setCredentials(credentials);

	// Finally, we submit our search query and get the result. This can be run
	// in a thread to avoid blocking the program flow.
	//
	// Search results contain information, like the maximum Tweet id that can
	// be used to create the next search query.
	auto result = client.search("love");

	if (result->isSuccess())
	{
		// We can cycle through the tweets to output their data.
		for (auto& status : result->statuses())
		{
			// Sometimes the user information is not included.
			if (status.user() != nullptr)
			{
				std::cout << ">>" << status.user()->name() << "<< (" << status.user()->screenName() << ")" << std::endl;

			}

			std::cout << status.text() << std::endl << std::endl;

			tweets.push_back(status.text());
		}

		// We can look through the errors to see if there are any.
		std::cout << "-------------" << std::endl;
		std::cout << "query: " << result->metadata().query() << std::endl;
		std::cout << "count: " << result->metadata().count() << std::endl;
		std::cout << "completed_in: " << result->metadata().completedIn() << std::endl;
		std::cout << "maxId: " << result->metadata().maxId() << std::endl;
		std::cout << "sinceId: " << result->metadata().sinceId() << std::endl;

	}
	else
	{
		for (auto& error : result->errors())
		{
			std::cout << error.code() << " / " << error.message() << std::endl;
		}

		std::cout << result->error() << std::endl;
	}

	
	//load font
	myFont.load("Simonetta-Italic.ttf", 46);
	timer = 0;
	switcher = 1;
	otherSwitch = 1;
	
	//set positions for the tweets
	positionsX = { 200,400,600,800,1000,200,400,600,800,1000,200,400,600,800,1000,200,400,600,800,1000, };
	positionsY = { 132,372,572,772,972,132,372,572,772,972,132,372,572,772,972,132,372,572,772,972 };
	
	//search for the word love and make uppercase CHANGE TO A VECTOR OF THESE THINGS
	refinedTweets = Compare(tweets);

	ofSetFullscreen(true);
	
}

//--------------------------------------------------------------
void ofApp::update() {
	timer++;
		if (timer % 105 == 0) {
			otherSwitch++;
			if (otherSwitch >= 16) {
				tweets.clear();
				auto credentials = ofxHTTP::OAuth10Credentials::fromFile("credentials.json");

				// Next we add our credentials to our ofxTwitter::RESTClient.
				client.setCredentials(credentials);

				// Finally, we submit our search query and get the result. This can be run
				// in a thread to avoid blocking the program flow.
				//
				// Search results contain information, like the maximum Tweet id that can
				// be used to create the next search query.
				auto result = client.search("love");

				if (result->isSuccess())
				{
					// We can cycle through the tweets to output their data.
					for (auto& status : result->statuses())
					{
						// Sometimes the user information is not included.
						if (status.user() != nullptr)
						{
							std::cout << ">>" << status.user()->name() << "<< (" << status.user()->screenName() << ")" << std::endl;

						}

						std::cout << status.text() << std::endl << std::endl;

						tweets.push_back(status.text());
					}

					// We can look through the errors to see if there are any.
					std::cout << "-------------" << std::endl;
					std::cout << "query: " << result->metadata().query() << std::endl;
					std::cout << "count: " << result->metadata().count() << std::endl;
					std::cout << "completed_in: " << result->metadata().completedIn() << std::endl;
					std::cout << "maxId: " << result->metadata().maxId() << std::endl;
					std::cout << "sinceId: " << result->metadata().sinceId() << std::endl;

				}
				else
				{
					for (auto& error : result->errors())
					{
						std::cout << error.code() << " / " << error.message() << std::endl;
					}

					std::cout << result->error() << std::endl;
				}
				refinedTweets = Compare(tweets);
				otherSwitch = 1;
			}
		}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(255);
	ofSetColor(0);

		switch (otherSwitch) {

		case(1) :
			if (otherSwitch > refinedTweets.size()) {
				otherSwitch = 16;
			}
			if (refinedTweets[otherSwitch - 1].length() > 40) {
				otherSwitch++;
			}
			else {
				myFont.drawString(refinedTweets[0], positionsX[0], positionsY[0]);
			}
				break;

		case(2) :
			if (otherSwitch > refinedTweets.size()) {
				otherSwitch = 16;
			}
			if (refinedTweets[otherSwitch - 1].length() > 40) {
				otherSwitch++;
			}
			else {
				myFont.drawString(refinedTweets[1], positionsX[1], positionsY[1]);
			}
				break;

		case(3) :
			if (otherSwitch > refinedTweets.size()) {
				otherSwitch = 16;
			}
			if (refinedTweets[otherSwitch - 1].length() > 40) {
				otherSwitch++;
			}
			else {
				myFont.drawString(refinedTweets[2], positionsX[2], positionsY[2]);
			}
				break;

		case(4) :
			if (otherSwitch > refinedTweets.size()) {
				otherSwitch = 16;
			}
			if (refinedTweets[otherSwitch - 1].length() > 40) {
				otherSwitch++;
			}
			else {
				myFont.drawString(refinedTweets[3], positionsX[3], positionsY[3]);
			}
				break;

		case(5) :
			if (otherSwitch > refinedTweets.size()) {
				otherSwitch = 16;
			}
			if (refinedTweets[otherSwitch - 1].length() > 40) {
				otherSwitch++;
			}
			else {
				myFont.drawString(refinedTweets[4], positionsX[4], positionsY[4]);
			}
				break;

		case(6) :
			if (otherSwitch > refinedTweets.size()) {
				otherSwitch = 16;
			}
			if (refinedTweets[otherSwitch - 1].length() > 40) {
				otherSwitch++;
			}
			else {
				myFont.drawString(refinedTweets[5], positionsX[0], positionsY[0]);
			}
				break;

		case(7) :
			if (otherSwitch > refinedTweets.size()) {
				otherSwitch = 16;
			}
			if (refinedTweets[otherSwitch - 1].length() > 40) {
				otherSwitch++;
			}
			else {
				myFont.drawString(refinedTweets[6], positionsX[1], positionsY[1]);
			}
				break;

		case(8) :
			if (otherSwitch > refinedTweets.size()) {
				otherSwitch = 16;
			}
			if (refinedTweets[otherSwitch - 1].length() > 40) {
				otherSwitch++;
			}
			else {
				myFont.drawString(refinedTweets[7], positionsX[2], positionsY[2]);
			}
				break;

		case(9) :
			if (otherSwitch > refinedTweets.size()) {
				otherSwitch = 16;
			}
			if (refinedTweets[otherSwitch - 1].length() > 40) {
				otherSwitch++;
			}
			else {
				myFont.drawString(refinedTweets[8], positionsX[3], positionsY[3]);
			}
				break;

		case(10) :
			if (otherSwitch > refinedTweets.size()) {
				otherSwitch = 16;
			}
			if (refinedTweets[otherSwitch - 1].length() > 40) {
				otherSwitch++;
			}
			else {
				myFont.drawString(refinedTweets[9], positionsX[4], positionsY[4]);
			}
				 break;

		case(11) :
			if (otherSwitch > refinedTweets.size()) {
				otherSwitch = 16;
			}
			if (refinedTweets[otherSwitch - 1].length() > 40) {
				otherSwitch++;
			}
			else {
				myFont.drawString(refinedTweets[10], positionsX[0], positionsY[0]);
			}
				 break;


		case(12) :
			if (otherSwitch > refinedTweets.size()) {
				otherSwitch = 16;
			}
			if (refinedTweets[otherSwitch - 1].length() > 40) {
				otherSwitch++;
			}
			else {
				myFont.drawString(refinedTweets[11], positionsX[1], positionsY[1]);
			}
				 break;

		case(13) :
			if (otherSwitch > refinedTweets.size()) {
				otherSwitch = 16;
			}
			if (refinedTweets[otherSwitch - 1].length() > 40) {
				otherSwitch++;
			}
			else {
				myFont.drawString(refinedTweets[12], positionsX[2], positionsY[2]);
			}
				 break;

		case(14) :
			if (otherSwitch > refinedTweets.size()) {
				otherSwitch = 16;
			}
			if (refinedTweets[otherSwitch - 1].length() > 40) {
				otherSwitch++;
			}
			else {
				myFont.drawString(refinedTweets[13], positionsX[3], positionsY[3]);
			}
				 break;

		case(15) :
			if (otherSwitch > refinedTweets.size()) {
				otherSwitch = 16;
			}
			if (refinedTweets[otherSwitch - 1].length() > 40) {
				otherSwitch++;
			}
			else {
				myFont.drawString(refinedTweets[14], positionsX[4], positionsY[4]);
			}
				 break;

		}
	
}

vector<string> ofApp::Compare(vector<string> input) {
	for (int i = 0; i < input.size(); i++) {
		ofStringReplace(input[i], "love", "LOVE");
		ofStringReplace(input[i], "Love", "LOVE");
		ofStringReplace(input[i], "lOve", "LOVE");
		ofStringReplace(input[i], "loVe", "LOVE");
		ofStringReplace(input[i], "lovE", "LOVE");
		ofStringReplace(input[i], "LOve", "LOVE");
		ofStringReplace(input[i], "LoVe", "LOVE");
		ofStringReplace(input[i], "LovE", "LOVE");
		ofStringReplace(input[i], "lOVe", "LOVE");
		ofStringReplace(input[i], "lOvE", "LOVE");
		ofStringReplace(input[i], "loVE", "LOVE");
		ofStringReplace(input[i], "LOVe", "LOVE");
		ofStringReplace(input[i], "LOvE", "LOVE");
		ofStringReplace(input[i], "LoVE", "LOVE");
		ofStringReplace(input[i], "lOVE", "LOVE");
		ofStringReplace(input[i], "#love", "#LOVE");
		ofStringReplace(input[i], "#Love", "#LOVE");
		ofStringReplace(input[i], "#lOve", "#LOVE");
		ofStringReplace(input[i], "#loVe", "#LOVE");
		ofStringReplace(input[i], "#lovE", "#LOVE");
		ofStringReplace(input[i], "#LOve", "#LOVE");
		ofStringReplace(input[i], "#LoVe", "#LOVE");
		ofStringReplace(input[i], "#LovE", "#LOVE");
		ofStringReplace(input[i], "#lOVe", "#LOVE");
		ofStringReplace(input[i], "#lOvE", "#LOVE");
		ofStringReplace(input[i], "#loVE", "#LOVE");
		ofStringReplace(input[i], "#LOVe", "#LOVE");
		ofStringReplace(input[i], "#LOvE", "#LOVE");
		ofStringReplace(input[i], "#LoVE", "#LOVE");
		ofStringReplace(input[i], "#lOVE", "#LOVE");
		
		string buf;
		stringstream ss(input[i]); // Insert the string into a stream

		vector<string> tokens; // Create vector to hold our words

		tokens = ofSplitString(input[i], " ", false, true);


		//while (ss >> buf)
		//	tokens.push_back(buf);

		int position = searchStringVector(tokens);

		if (position > 0 && position < tokens.size())
			input[i] = tokens[position - 1] + " " + tokens[position] + " " + tokens[position + 1];

		if (position == 0 && position < tokens.size())
			input[i] = tokens[position] + " " + tokens[position + 1];

		if (position > 0 && position == tokens.size())
			input[i] = tokens[position - 1] + " " + tokens[position];
	}

	return input;
}

int ofApp::searchStringVector(vector<string> input) {
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == "LOVE" || input[i] == "#LOVE") {
			return i;
		}
	}
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
