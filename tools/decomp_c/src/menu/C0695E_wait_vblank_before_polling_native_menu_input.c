#include "som_c.h"

/* C0695E wait_vblank_before_polling_native_menu_input   [class A, 25 bytes, 10 instructions]
 * Source: src/rom/wait_vblank_before_polling_native_menu_input.s
 * Documented in docs/event-menu-vblank.md
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void wait_vblank_before_polling_native_menu_input(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x6960, 0xC06943); /* await_vblank_edge_and_run_complete_menu_text_frame */
    r->mf = 0; /* rep */
    r->xf = 0;
    r->mf = 0;
    r->xf = 0;
    JSL(c, 0x6966, 0x008000); /* public_controller_poll_long: the operand bank is $00, not the C0 mirror */
    uint16_t value = RAM16(0x1836);
    uint16_t value2 = RAM16(0x0042 + ((value & 0xFF) << 1));
    RAM16_SET(0x1800, value2);
    r->a = value2;
    r->x = (value & 0xFF) << 1;
    r->c = value & 0xFF & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0695E, SOM_RTS, "hand", wait_vblank_before_polling_native_menu_input, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, -1, 0, 25, 10)
