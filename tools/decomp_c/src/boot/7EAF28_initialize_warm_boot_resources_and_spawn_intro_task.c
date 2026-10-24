#include "som_c.h"

/* 7EAF28 initialize_warm_boot_resources_and_spawn_intro_task   [class C, 20 bytes, 7 instructions]
 * Source: src/boot/initialize_warm_boot_resources_and_spawn_intro_task.s
 * Documented in docs/boot-native-startup-prefix.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void initialize_warm_boot_resources_and_spawn_intro_task(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xAF2A, 0x7EAD75); GUARD_JSR(c, sp_call, 0xAF2A); } /* initialize_boot_resources */
    uint16_t a_all = r->a;
    r->a = (a_all >> 8 << 8) | 0x7E;
    r->x = 0x5EC3;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAF32, 0x7EAB88); GUARD_JSR(c, sp_call, 0xAF32); } /* create_and_enqueue_task */
    { const uint16_t sp_call = r->sp; JSR(c, 0xAF35, 0x7EA88F); GUARD_JSR(c, sp_call, 0xAF35); } /* enter_native_scheduler_and_launch_default_idle_task */
    { const uint16_t sp_call = r->sp; JSR(c, 0xAF38, 0x7EAE28); GUARD_JSR(c, sp_call, 0xAF38); } /* reserved_native_bank_7f_near_api */
    TAIL_CALL(c, 0x7EAF0B, SOM_RTS); /* initialize_cold_boot_resources_and_spawn_main_task */
}
SOM_REGISTER(0x7EAF28, SOM_RTS, "gen", initialize_warm_boot_resources_and_spawn_intro_task, 0, 0, 1, 1, 0, 20, 7)
