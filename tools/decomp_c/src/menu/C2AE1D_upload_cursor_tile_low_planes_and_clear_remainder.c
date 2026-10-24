#include "som_c.h"

/* C2AE1D upload_cursor_tile_low_planes_and_clear_remainder   [class D, 28 bytes, 13 instructions]
 * Source: src/rom/upload_cursor_tile_low_planes_and_clear_remainder.s
 * Documented in docs/ui-native-world-map-picker-scene.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: XYCV.
 */
static void upload_cursor_tile_low_planes_and_clear_remainder(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi1 = a_hi;
    uint8_t x1 = x;
    uint8_t y1 = 0;
    bool carry1 = carry;
    for (;;) {
        uint8_t value = BUS8(c, 0x02AECC + x1);
        BUS8_SET(c, 0x002118, value);
        BUS8_SET(c, 0x002119, 0);
        uint8_t x1_next = (uint8_t)(x1 + 1);
        uint8_t y1_next = (uint8_t)(y1 + 1);
        bool carry1_next = (uint8_t)(y1 + 1) >= 8;
        x1 = x1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        if (!(y1 < 8)) break;
    }
    uint8_t y2 = y1;
    for (;;) {
        BUS8_SET(c, 0x002118, 0);
        BUS8_SET(c, 0x002119, 0);
        y2 = (uint8_t)(y2 - 1);
        if (!(y2 != 0)) break;
    }
    r->x = x1;
    r->y = y2;
    r->c = carry1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2AE1D, SOM_RTS, "gen", upload_cursor_tile_low_planes_and_clear_remainder, 0, L_X | L_Y | L_C | L_V, 1, 1, 1, 28, 13)
