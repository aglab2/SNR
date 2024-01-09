#include "config/config_memory.h"

#ifndef USE_EXT_RAM
// In 4MB mode, it is not possible to have each fb be it is own bank so use only 2 banks
#if MEMORY_FRAGMENTATION_LEVEL > MEMORY_FRAGMENTATION_ZBUFFER_AND_FRAMEBUFFERS
#warning "Memory fragmentation level is too high for 4MB mode. Setting to MEMORY_FRAGMENTATION_ZBUFFER_AND_FRAMEBUFFERS"
#undef MEMORY_FRAGMENTATION_LEVEL
#define MEMORY_FRAGMENTATION_LEVEL MEMORY_FRAGMENTATION_ZBUFFER_AND_FRAMEBUFFERS
#endif
#endif

// Either size of zbuffer or size of framebuffer
#define RENDER_BUFFER_BUFFER_SIZE 0x25800

#if MEMORY_FRAGMENTATION_ZBUFFER_AND_FRAMEBUFFERS == MEMORY_FRAGMENTATION_LEVEL
#ifndef USE_EXT_RAM
#define RENDER_BUFFER_MEMORY_PIVOT 0x80300000
#else
#define RENDER_BUFFER_MEMORY_PIVOT 0x80700000
#endif
#define ZBUFFER_START RENDER_BUFFER_MEMORY_PIVOT - RENDER_BUFFER_BUFFER_SIZE
#define FRAMEBUFFER0_START RENDER_BUFFER_MEMORY_PIVOT
#define FRAMEBUFFER1_START RENDER_BUFFER_MEMORY_PIVOT + RENDER_BUFFER_BUFFER_SIZE
#define FRAMEBUFFER2_START RENDER_BUFFER_MEMORY_PIVOT + 2 * RENDER_BUFFER_BUFFER_SIZE
#endif

// Anything above 1 is using the ext ram so do not bother checking for 'USE_EXT_RAM'
#if MEMORY_FRAGMENTATION_ZBUFFER_AND_FRAMEBUFFERS_SPLIT == MEMORY_FRAGMENTATION_LEVEL
#define ZBUFFER_START 0x80500000 - RENDER_BUFFER_BUFFER_SIZE
#define FRAMEBUFFER0_START 0x80500000
#define FRAMEBUFFER1_START 0x80500000 + RENDER_BUFFER_BUFFER_SIZE
#define FRAMEBUFFER2_START 0x80500000 + 2 * RENDER_BUFFER_BUFFER_SIZE
#endif

#if MEMORY_FRAGMENTATION_ZBUFFER_AND_EACH_FRAMEBUFFER == MEMORY_FRAGMENTATION_LEVEL
#define ZBUFFER_START 0x80500000 - RENDER_BUFFER_BUFFER_SIZE
#define FRAMEBUFFER0_START 0x80500000
#define FRAMEBUFFER1_START 0x80700000 - RENDER_BUFFER_BUFFER_SIZE
#define FRAMEBUFFER2_START 0x80700000
#endif

// Small alloc is optimization that will use the latest region to allow inlining implementation
#define MAIN_POOL_SMALL_ALLOC_LIMIT 0x80

#if MEMORY_FRAGMENTATION_NO_FRAGMENTATION == MEMORY_FRAGMENTATION_LEVEL
// Consider memory to be contiguous instead of consisting of multiple regions (single region) effectively removing any size checks
#define MAIN_POOL_SINGLE_REGION
#endif
