#include "som_c.h"

/* C0000F jump_public_native_name_menu   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/jump_public_native_name_menu.s
 * Documented in docs/event-party-name-command.md
 * Entry: M=8 bit X=any DB=any D=$0000.  Callers read: BXYCZNV.
 */
static void jump_public_native_name_menu(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC0008F, SOM_RTL); /* jump_internal_native_name_menu */
}
SOM_REGISTER(0xC0000F, SOM_RTL, "gen", jump_public_native_name_menu, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, -1, 3, 1)
