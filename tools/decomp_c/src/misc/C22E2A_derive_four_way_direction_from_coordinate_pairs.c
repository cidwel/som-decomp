#include "som_c.h"

/* C22E2A derive_four_way_direction_from_coordinate_pairs   [class B, 38 bytes, 18 instructions]
 * Source: src/rom/derive_four_way_direction_from_coordinate_pairs.s
 * Documented in docs/boss-descriptor-four.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void derive_four_way_direction_from_coordinate_pairs(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x2E2C, 0xC22EA0); /* subtract_boss_direction_coordinate_pairs */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x2E2F, 0xC22EAF); /* derive_boss_direction_quadrant_from_signed_differences */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x2E32, 0xC22ECC); /* make_boss_direction_differences_absolute_using_c5 */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x2E35, 0xC22EE3); /* classify_boss_direction_by_larger_absolute_axis */
    uint16_t value = RAM16(0x026A);
    uint8_t a_hi1;
    if (value & 0x01) {
        a_hi1 = value >> 1 >> 8;
    } else {
        uint16_t value2 = RAM16(0x026C);
        RAM16_SET(0x026C, (uint16_t)(1 - value2));
        a_hi1 = (uint16_t)(1 - value2) >> 8;
    }
    uint16_t value3 = RAM16(0x026C);
    uint8_t a1;
    uint8_t a_hi2;
    if ((uint16_t)(value + value3) != 4) {
        a1 = (uint8_t)(value + value3);
        a_hi2 = (uint16_t)(value + value3) >> 8;
    } else {
        uint16_t value4 = RAM16(0x02C5);
        a1 = (uint8_t)value4;
        a_hi2 = value4 >> 8;
    }
    r->a = (a_hi2 << 8) | a1;
    r->c = (uint16_t)(value + value3) >= 4;
    r->v = ((value ^ (uint16_t)(value + value3)) & (value3 ^ (uint16_t)(value + value3)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22E2A, SOM_RTS, "gen", derive_four_way_direction_from_coordinate_pairs, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 38, 18)
