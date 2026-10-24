#include "som_c.h"

/* C00080 jump_internal_native_boot_menu_workspace_initializer   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/jump_internal_native_boot_menu_workspace_initializer.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void jump_internal_native_boot_menu_workspace_initializer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC00E40, SOM_RTL); /* initialize_native_boot_menu_workspace_and_settings */
}
SOM_REGISTER(0xC00080, SOM_RTL, "gen", jump_internal_native_boot_menu_workspace_initializer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 3, 1)
