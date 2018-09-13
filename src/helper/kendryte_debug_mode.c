#include "kendryte_debug_mode.h"

debug_info_t debug_info = { 0, 0 };

void set_debug_info(int mode, int hartid)
{
	debug_info.debug_mode = mode;
	debug_info.debug_hartid = hartid;
}