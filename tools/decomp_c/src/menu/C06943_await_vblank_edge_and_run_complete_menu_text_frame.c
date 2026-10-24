#include "som_c.h"

/* C06943 await_vblank_edge_and_run_complete_menu_text_frame   [class D, 23 bytes, 10 instructions]
 * Source: src/rom/await_vblank_edge_and_run_complete_menu_text_frame.s
 * Documented in docs/event-menu-vblank.md
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void await_vblank_edge_and_run_complete_menu_text_frame(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi1 = a >> 8;
    for (;;) {
        uint8_t value = BUS8(c, 0x004212);
        if (!(value & 0x80)) break;
    }
    uint8_t a_hi2 = a_hi1;
    for (;;) {
        uint8_t value2 = BUS8(c, 0x004212);
        if (!(!(value2 & 0x80))) break;
    }
    uint8_t value3 = RAM8(0x00EC);
    RAM8(0x00EC) |= 8;
    r->a = (a_hi2 << 8) | 8;
    r->x = x;
    r->y = y;
    r->c = carry;
    r->z = (value3 & 8) == 0;
    r->n = 0;
    r->v = overflow;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6956, 0xD0D397); GUARD_JSL(c, sp_call, 0x6956); } /* prepare_and_run_complete_native_menu_dialogue_frame */
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06943, SOM_RTS, "gen", await_vblank_edge_and_run_complete_menu_text_frame, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, 0, 23, 10)
