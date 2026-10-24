#include "som_c.h"

/* 7EAF0B initialize_cold_boot_resources_and_spawn_main_task   [class C, 29 bytes, 9 instructions]
 * Source: src/boot/initialize_cold_boot_resources_and_spawn_main_task.s
 * Documented in docs/boot-native-startup-prefix.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void initialize_cold_boot_resources_and_spawn_main_task(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xAF0D, 0x7EAD75); GUARD_JSR(c, sp_call, 0xAF0D); } /* initialize_boot_resources */
    uint16_t a_all = r->a;
    r->a = (a_all >> 8 << 8) | 0x7E;
    r->x = 0x6488;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAF15, 0x7EAB88); GUARD_JSR(c, sp_call, 0xAF15); } /* create_and_enqueue_task */
    { const uint16_t sp_call = r->sp; JSR(c, 0xAF18, 0x7EA88F); GUARD_JSR(c, sp_call, 0xAF18); } /* enter_native_scheduler_and_launch_default_idle_task */
    { const uint16_t sp_call = r->sp; JSR(c, 0xAF1B, 0x7EAE28); GUARD_JSR(c, sp_call, 0xAF1B); } /* reserved_native_bank_7f_near_api */
    { const uint16_t sp_call = r->sp; JSL(c, 0xAF1F, 0xC00000); GUARD_JSL(c, sp_call, 0xAF1F); } /* jump_public_native_boot_menu_workspace_initializer */
    { const uint16_t sp_call = r->sp; JSL(c, 0xAF23, 0xC00012); GUARD_JSL(c, sp_call, 0xAF23); } /* public_native_menu_state_initialization_alias */
    TAIL_CALL(c, 0xC00009, SOM_RTS); /* public_boot_menu_caller_alias */
}
SOM_REGISTER(0x7EAF0B, SOM_RTS, "gen", initialize_cold_boot_resources_and_spawn_main_task, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 29, 9)
