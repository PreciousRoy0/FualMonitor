#pragma once

#include "Walnut/Layer.h"
#include "SerialPort.hpp"

class MainWindow : public Walnut::Layer
{
public:
	char* portName = "\\\\.\\COM7";
	SerialPort* port;

	bool ShowChannel1 = true;
	bool ShowChannel2 = false;
	bool ShowChannel3 = false;
	bool ShowChannel4 = false;
	bool ShowSettings = false;

#define MAX_DATA_LENGTH 255

	std::string data;
	char incomingData[MAX_DATA_LENGTH];

	void exampleReceiveData(void);
	void exampleWriteData(unsigned int delayTime);


	virtual void OnUIRender() override;
};