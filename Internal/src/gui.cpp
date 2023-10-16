#include "gui.h"
#include "../ext/imgui/imgui.h"
#include "../ext/imgui/imgui_impl_win32.h"
#include "../ext/imgui/imgui_impl_win32.h"


#include <stdexcept>

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler
(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// window process
LRESULT CALLBACK WindowProcess(
	HWND window,
	UINT message,
	WPARAM wideParam,
	LPARAM longParam

	);


bool gui::SetupWindowClass(const char* windowClassName) noexcept
{
	// popuate window class
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style - CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = DefWindowProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = GetModuleHandle(NULL);
	windowClass.hIcon = NULL;
	windowClass.hCursor = NULL;
	windowClass.hbrBackground = NULL;
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = windowClassName;
	windowClass.hIconSm = NULL;
};


void gui::DestroyWindowClass() noexcept
{

};


bool gui::SetupWindow(const char* windowName) noexcept
{

};


void gui::DestroyWindow() noexcept
{

};


bool gui::SetupDirectX() noexcept
{

};

void gui::DestroyDirectX() noexcept
{

};


//Setup device
void gui::Setup()
{

};

void gui::SetupMenu(LPDIRECT3DDEVICE9 device) noexcept
{

};

void gui::Destroy() noexcept
{

};


void gui::Render() noexcept
{

};

LRESULT CALLBACK WindowProcess(
	HWND window,
	UINT message,
	WPARAM wideParam,
	LPARAM longParam

)
{
	// toggle menu
	if (GetAsyncKeyState(VK_INSERT) & 1)
		gui::open = !gui::open;

	//pass messages to imgui
	if (gui::open && ImGui_ImplWin32_WndProcHandler(
		window,
		message,
		wideParam,
		longParam

	)) return 1L;


	return CallWindowProc(
		gui::originalWindowProcess,
		window,
		message,
		wideParam,
		longParam

	);

}
