#include "MainWindow.h"

#include "Walnut/Application.h"
#include "imgui_internal.h"
#include "Walnut/Image.h"

void MainWindow::OnUIRender()
{
	//if (port->isConnected())
	//	exampleReceiveData();

	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));

	if (ShowChannel1)
	{
		ImGui::Begin("Channel1", &ShowChannel1, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse);

		ImVec2 graphWindowSize = ImGui::GetContentRegionAvail();
		ImVec2 size = ImGui::GetWindowSize();
		if (ImPlot::BeginPlot("Channel 1##Plot", graphWindowSize))
		{
			//ImPlot::PlotBars("My Bar Plot", bar_data, 11);
			//ImPlot::PlotLine("My Line Plot", x_data, y_data, 1000);
			//...
			ImPlot::EndPlot();
		}
		ImGui::End();
	}

	ImGui::PopStyleVar(1);
}

void MainWindow::exampleReceiveData(void)
{
	int readResult = port->readSerialPort(incomingData, MAX_DATA_LENGTH);
	//printf("%s", incomingData);
	//Sleep(10);
	if (readResult > 0)
		data += incomingData;
}

void MainWindow::exampleWriteData(unsigned int delayTime)
{
	port->writeSerialPort("ledON", MAX_DATA_LENGTH);
	Sleep(delayTime);
	port->writeSerialPort("ledOFF", MAX_DATA_LENGTH);
	Sleep(delayTime);
}