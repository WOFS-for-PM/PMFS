#ifndef NVM_TRACER
#define NVM_TRACER

#include <linux/types.h>

#define TRACE_NVM_READ(fmt, ...) \
    trace_printk("NVM_READ: " fmt, ##__VA_ARGS__)

#define TRACE_NVM_WRITE(fmt, ...) \
    trace_printk("NVM_WRITE: " fmt, ##__VA_ARGS__)

enum nvm_access_type
{
    NVM_READ,
    NVM_WRITE
};

#ifdef TRACER_ENABLE
static __always_inline void trace_nvm_access(enum nvm_access_type access_type, const char * msg, uint64_t nvm_start, uint64_t addr, uint64_t len)
{
    switch (access_type)
    {
        case NVM_READ:
            TRACE_NVM_READ("%s: @0x%llx, %ld\n", msg, (addr - nvm_start), len);
            break;
        case NVM_WRITE:
            TRACE_NVM_WRITE("%s: @0x%llx, %ld\n", msg, (addr - nvm_start), len);
            break;
    }
    return;
}
#else
static __always_inline void trace_nvm_access(enum nvm_access_type access_type, const char * msg, uint64_t nvm_start, uint64_t addr, uint64_t len)
{
    return;
}
#endif 


#endif