#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "Walnut/Image.h"
#include "imgui_internal.h"

#include "MainWindow.h"

Walnut::Application* app;
const std::shared_ptr<MainWindow> slayer (new MainWindow);

void MenubarCallback()
{
	if (ImGui::BeginMenu("File"))
	{
		if (ImGui::MenuItem("Settings"))
		{
			slayer->ShowSettings = true;
		}

		if (ImGui::MenuItem("Exit"))
		{
			app->Close();
		}
		ImGui::EndMenu();
	}

	if (ImGui::BeginMenu("View"))
	{
		if (ImGui::MenuItem("Reset View"))
		{
			ImGuiID dockspace_idd = ImGui::GetID("VulkanAppDockspace");
			ImGuiID left = ImGui::DockBuilderSplitNode(dockspace_idd, ImGuiDir_Left, 0.25f, nullptr, nullptr);
			ImGui::DockBuilderDockWindow("Channel1", left);
		}
		ImGui::EndMenu();
	}

	if (ImGui::BeginMenu("Help"))
	{
		ImGui::EndMenu();
	}
}

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "FuelMonitor";

	app = new Walnut::Application(spec);
	app->PushLayer(slayer);
	app->SetMenubarCallback(&MenubarCallback);

	return app;
}