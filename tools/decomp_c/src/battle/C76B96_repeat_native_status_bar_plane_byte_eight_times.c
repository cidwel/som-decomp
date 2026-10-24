#include "som_c.h"

/* C76B96 repeat_native_status_bar_plane_byte_eight_times   [class A, 15 bytes, 8 instructions]
 * Source: src/rom/repeat_native_status_bar_plane_byte_eight_times.s
 * Documented in docs/ui-native-party-status-art.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYV.
 */
static void repeat_native_status_bar_plane_byte_eight_times(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool overflow = r->v;
    uint16_t x1 = x;
    uint16_t y1 = 4;
    for (;;) {
        RAM8(0x9400 + x1) = a;
        RAM8(0x9400 + (uint16_t)(x1 + 1)) = a;
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 - 1);
        if (!(y1 != 0)) break;
    }
    r->a = (a_hi << 8) | a;
    r->x = x1;
    r->y = y1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76B96, SOM_RTS, "gen", repeat_native_status_bar_plane_byte_eight_times, 0, L_A | L_B | L_X | L_Y | L_V, 1, 1, 0, 15, 8)
