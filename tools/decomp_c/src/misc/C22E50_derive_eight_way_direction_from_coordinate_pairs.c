#include "som_c.h"

/* C22E50 derive_eight_way_direction_from_coordinate_pairs   [class B, 39 bytes, 19 instructions]
 * Source: src/rom/derive_eight_way_direction_from_coordinate_pairs.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void derive_eight_way_direction_from_coordinate_pairs(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x2E52, 0xC22EA0); /* subtract_boss_direction_coordinate_pairs */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x2E55, 0xC22EAF); /* derive_boss_direction_quadrant_from_signed_differences */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x2E58, 0xC22ECC); /* make_boss_direction_differences_absolute_using_c5 */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x2E5B, 0xC22EF4); /* classify_boss_direction_by_half_axis_thresholds */
    uint16_t value = RAM16(0x026A);
    uint8_t a_hi1;
    if (value & 0x01) {
        a_hi1 = value >> 1 >> 8;
    } else {
        uint16_t value2 = RAM16(0x026C);
        RAM16_SET(0x026C, (uint16_t)(2 - value2));
        a_hi1 = (uint16_t)(2 - value2) >> 8;
    }
    uint16_t value3 = RAM16(0x026C);
    uint8_t a1;
    uint8_t a_hi2;
    if ((uint16_t)((uint16_t)(value << 1) + value3) != 8) {
        a1 = (uint8_t)((uint16_t)(value << 1) + value3);
        a_hi2 = (uint16_t)((uint16_t)(value << 1) + value3) >> 8;
    } else {
        uint16_t value4 = RAM16(0x02C5);
        a1 = (uint8_t)value4;
        a_hi2 = value4 >> 8;
    }
    r->a = (a_hi2 << 8) | a1;
    r->c = (uint16_t)((uint16_t)(value << 1) + value3) >= 8;
    r->v = (((uint16_t)(value << 1) ^ (uint16_t)((uint16_t)(value << 1) + value3)) & (value3 ^ (uint16_t)((uint16_t)(value << 1) + value3)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22E50, SOM_RTS, "gen", derive_eight_way_direction_from_coordinate_pairs, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 39, 19)
