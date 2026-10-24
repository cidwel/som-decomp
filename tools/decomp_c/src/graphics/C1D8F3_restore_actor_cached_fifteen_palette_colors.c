#include "som_c.h"

/* C1D8F3 restore_actor_cached_fifteen_palette_colors   [class A, 26 bytes, 12 instructions]
 * Source: src/rom/restore_actor_cached_fifteen_palette_colors.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void restore_actor_cached_fifteen_palette_colors(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0x000A, 0x0F);
    RAM16_SET(0xE100 + x, 0);
    uint16_t value = RAM16(0xE0F8 + x);
    uint8_t a1 = 0x0F;
    uint8_t a_hi1 = 0;
    uint16_t y1 = value;
    do {
        uint16_t value2 = RAM16(0xDF00 + y1);
        RAM16_SET(0x0700 + y1, value2);
        RAM16_SET(0x000A, (uint16_t)(RAM16(0x000A) - 1));
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        y1 = (uint16_t)(y1 + 2);
    } while (RAM16(0x000A) != 0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x;
    r->y = y1;
    r->c = carry;
    r->v = overflow;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1D8F3, SOM_RTS, "gen", restore_actor_cached_fifteen_palette_colors, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 26, 12)
