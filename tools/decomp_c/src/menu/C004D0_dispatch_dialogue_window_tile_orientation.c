#include "som_c.h"

/* C004D0 dispatch_dialogue_window_tile_orientation   [class C, 18 bytes, 11 instructions]
 * Source: src/rom/dispatch_dialogue_window_tile_orientation.s
 * Documented in docs/event-dialogue-render-core.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYV.
 */
static void dispatch_dialogue_window_tile_orientation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    uint8_t value = RAM8(0xA16D);
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    r->a = x;
    r->x = (uint8_t)(value << 1);
    r->c = value & 0x80;
    r->z = x == 0;
    r->n = x & 0x8000;
    { const uint16_t sp_call = r->sp;
    switch ((uint8_t)(value << 1)) {
    case 0x0000: JSR(c, 0x04E0, 0xC004E2); GUARD_JSR(c, sp_call, 0x04E0); break; /* expand_dialogue_window_tile_forward_with_plane_mask */
    case 0x0002: JSR(c, 0x04E0, 0xC0054D); GUARD_JSR(c, sp_call, 0x04E0); break; /* expand_dialogue_window_tile_forward_with_reversed_bits */
    case 0x0004: JSR(c, 0x04E0, 0xC00515); GUARD_JSR(c, sp_call, 0x04E0); break; /* expand_dialogue_window_tile_backward */
    case 0x0006: JSR(c, 0x04E0, 0xC00583); GUARD_JSR(c, sp_call, 0x04E0); break; /* expand_dialogue_window_tile_backward_with_reversed_bits */
    default: JSR(c, 0x04E0, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x10FA + ((uint8_t)(value << 1))))); GUARD_JSR(c, sp_call, 0x04E0);
    }
    }
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC004D0, SOM_RTS, "gen", dispatch_dialogue_window_tile_orientation, 0, L_B | L_Y | L_V, 2, 1, 0, 18, 11)
