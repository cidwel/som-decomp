#include "som_c.h"

/* C2734B move_descriptor_seven_toward_target_vertical_axis_until_within_32   [class B, 61 bytes, 29 instructions]
 * Source: src/rom/move_descriptor_seven_toward_target_vertical_axis_until_within_32.s
 * Documented in docs/boss-descriptor-axis-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void move_descriptor_seven_toward_target_vertical_axis_until_within_32(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00A9 + value);
    uint16_t value3 = RAM16(0x0032 + value);
    uint16_t value4 = RAM16(0x0004 + (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000));
    if ((uint16_t)(value3 - value4) & 0x8000) {
        uint8_t a_hi1;
        if ((uint16_t)(value4 - value3) & 0x8000) {
            RAM16_SET(0x0040 + value, 0xFFFE);
            a_hi1 = 0xFF;
        } else {
            RAM16_SET(0x0040 + value, 2);
            a_hi1 = 0;
        }
        r->a = RAM16(0x02C5);
        r->x = value;
        r->y = (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000);
        JSR(c, 0x7380, 0xC20A47); /* move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding */
        uint16_t x_ret = r->x;
        RAM16_SET(0x0040 + x_ret, 0);
        r->c = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if ((uint16_t)(value3 - value4) < 0x20) {
        r->a = (uint16_t)(value3 - value4);
        r->x = value;
        r->y = (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000);
        r->c = 1;
        r->z = (uint16_t)(value3 - value4) == 0x20;
        r->n = (uint16_t)((uint16_t)(value3 - value4) - 0x20) & 0x8000;
        r->v = ((value3 ^ value4) & (value3 ^ (uint16_t)(value3 - value4)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint8_t a_hi2;
    if ((uint16_t)(value4 - value3) & 0x8000) {
        RAM16_SET(0x0040 + value, 0xFFFE);
        a_hi2 = 0xFF;
    } else {
        RAM16_SET(0x0040 + value, 2);
        a_hi2 = 0;
    }
    r->a = RAM16(0x02C5);
    r->x = value;
    r->y = (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000);
    JSR(c, 0x7380, 0xC20A47); /* move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding */
    uint16_t x_ret2 = r->x;
    RAM16_SET(0x0040 + x_ret2, 0);
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2734B, SOM_RTS, "gen", move_descriptor_seven_toward_target_vertical_axis_until_within_32, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 61, 29)
