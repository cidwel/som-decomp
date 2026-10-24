#include "som_c.h"

/* C0695A wait_vblank_and_poll_menu_through_native_long_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/wait_vblank_and_poll_menu_through_native_long_wrapper.s
 * Documented in docs/event-menu-vblank.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void wait_vblank_and_poll_menu_through_native_long_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x695C, 0xC0695E); GUARD_JSR(c, sp_call, 0x695C); } /* wait_vblank_before_polling_native_menu_input */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0695A, SOM_RTL, "hand", wait_vblank_and_poll_menu_through_native_long_wrapper, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
