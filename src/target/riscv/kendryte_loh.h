#ifndef OPENOCD_KENDRYTE_LOG_H
#define OPENOCD_KENDRYTE_LOG_H

#include "log.h"

#define KENDRYTE_LOG 0

// log function call
#define KENDRYTE_LOG_FC() do { \
  if (KENDRYTE_LOG) LOG_INFO("@@@@@ %s in %s", __FUNCTION__, __FILE__); \
} while (0)

// log details
#define KENDRYTE_LOG_D(fmt, ...) do { \
  if (KENDRYTE_LOG) LOG_INFO("@=@=@ %s: " fmt, __FUNCTION__, __VA_ARGS__); \
} while (0)

// log important information
#define KENDRYTE_LOG_I(fmt, ...) do { \
  if (KENDRYTE_LOG) LOG_INFO("!!!!! %s: " fmt, __FUNCTION__, __VA_ARGS__); \
} while (0)

#endif // !OPENOCD_KENDRYTE_LOG_H
