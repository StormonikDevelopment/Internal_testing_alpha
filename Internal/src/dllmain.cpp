#define WIN32_lEAN_AND_MEAN
#include <Windows.h>

#include <thread>
#include <cstdint>

//setup funct
void Setup(const HMODULE instance)
{

}


//entry
BOOL WINAPI DLLMain(
	const HMODULE instance,
	const std::uintptr_t reason,
	const void* reserved
)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(instance);

		const auto threat = CreateThread(
			nullptr,
			0,
			reinterpret_cast<LPTHREAD_START_ROUTINE>(Setup),
			instance,
			0,
			nullptr

		);

		if (thread)
			CloseHandle(thread);
	}

	return TRUE;


}
