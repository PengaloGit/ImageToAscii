// SMFLtest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

string grayString = "@%#*+=-:. ";

void colorChar(string& line, Color color) {
	line += "<span style = \"color:rgba(" + to_string(color.r) + "," + to_string(color.g) + "," + to_string(color.b) + "," + to_string(color.a) + ");\">" + grayString.at(2) + "</span>";
}
void grayCharScale(string& line,float scale) {
	
	if (scale <= 10)
		line += grayString.at(0);
	else if (scale <= 20)
		line += grayString.at(1);
	else if (scale <= 30)
		line += grayString.at(2);
	else if (scale <= 40)
		line += grayString.at(3); 
	else if (scale <= 50)
		line += grayString.at(4); 
	else if (scale <= 60)
		line += grayString.at(5); 
	else if (scale <= 70)
		line += grayString.at(6); 
	else if (scale <= 80)
		line += grayString.at(7); 
	else if (scale <= 90)
		line += grayString.at(8); 
	else if (scale <= 100)
		line += grayString.at(9);
}

int main(int argc, char *argv[])
{
	string path;
	int precision,mode;
	Texture texture;

	cout << "Enter the image path : " << endl;
	cin >> path;
	
	cout << "Enter the precision : " << endl;
	cin >> precision;

	cout << "Enter:\n 1 for black and white version \n 2 for color version\n";
	cin >> mode;


	texture.loadFromFile(path);
	auto img = texture.copyToImage();
	
	ofstream myfile;
	myfile.open("result.html");
	
	myfile << "<pre>\n";
	
	Vector2u corr;
	corr = img.getSize();
	
	unsigned int w = corr.x/precision;
	unsigned int h = corr.y/(2*precision);

	for (unsigned int i = 0; i < h; i++) {
		string line = "";
		for (unsigned int j = 0; j < w; j++) {
			Color color = img.getPixel(precision*j, 2*precision*i);
			float scale = (color.r + color.b + color.g) *100/ 768;
			if (mode == 1)
				grayCharScale(line, scale);
			else if (mode == 2)
				colorChar(line, color);
		}
		myfile << line + "\n";
	}
	myfile << "</pre>";
	myfile.close();

	cout << "File html generated with success !!" << endl;
	cout << "Press any button to continue !!" << endl;
	getchar();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
