#pragma once
#include <d3d12.h>
#include <d3d9.h>

namespace gui
{
	//Is menu open? (yes retard, fuckin dumbass)
	inline bool open = true;

	// is menu setup
	inline bool setup = false;

	// winapi related
	inline HWND window = nullptr;
	inline WNDCLASSEX windowClass = { };
	inline WNDPROC originalWindowProcess = nullptr;


	//hijacking dx9
	inline LPDIRECT3DDEVICE9 device = nullptr;
	inline LPDIRECT3D9 d3d9 = nullptr;


	bool SetupWindowClass(const char* windowClassName) noexcept;
	void DestroyWindowClass() noexcept;


	bool SetupWindow(const char* windowName) noexcept;
	void DestroyWindow() noexcept;

	bool SetupDirectX() noexcept;
	void DestroyDirectX() noexcept;

	//Setup device
	void Setup();


	void SetupMenu(LPDIRECT3DDEVICE9 device) noexcept;
	void Destroy() noexcept;

	void Render() noexcept;

}