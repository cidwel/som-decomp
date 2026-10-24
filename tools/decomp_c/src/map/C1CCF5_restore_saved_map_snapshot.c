#include "som_c.h"

/* C1CCF5 restore_saved_map_snapshot   [class A, 34 bytes, 18 instructions]
 * Source: src/rom/restore_saved_map_snapshot.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void restore_saved_map_snapshot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0xFE;
    for (;;) {
        uint16_t value = RAM16(0xCE00 + x1);
        RAM16_SET(0xCD00 + x1, value);
        a_hi1 = value >> 8;
        x1 = (uint16_t)(x1 - 2);
        if (!(!(x1 & 0x8000))) break;
    }
    RAM16_SET(0x00DC, RAM16(0xCD08));
    RAM16_SET(0x00DF, 0);
    r->a = 0;
    r->x = x1;
    r->y = y;
    r->c = carry;
    r->v = overflow;
    r->mf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1CCF5, SOM_RTL, "gen", restore_saved_map_snapshot, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 34, 18)
