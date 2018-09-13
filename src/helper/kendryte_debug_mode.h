#ifndef KENDRYTE_DEBUG_MODE_H
#define KENDRYTE_DEBUG_MODE_H

typedef struct debuginfo
{
	int debug_mode;
	int debug_hartid;
}debug_info_t;

void set_debug_info(int mode, int hartid);


#endif // !KENDRYTE_DEBUG_MODE_H
