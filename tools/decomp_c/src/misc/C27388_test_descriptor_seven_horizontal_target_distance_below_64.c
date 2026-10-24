#include "som_c.h"

/* C27388 test_descriptor_seven_horizontal_target_distance_below_64   [class B, 31 bytes, 18 instructions]
 * Source: src/rom/test_descriptor_seven_horizontal_target_distance_below_64.s
 * Documented in docs/boss-descriptor-axis-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void test_descriptor_seven_horizontal_target_distance_below_64(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00A9 + x);
    uint16_t value2 = RAM16(0x0002 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
    uint16_t value3 = RAM16(0x002B + x);
    uint8_t a1;
    uint8_t a_hi1;
    if (!((uint16_t)(value2 - value3) & 0x8000)) {
        a1 = (uint8_t)(value2 - value3);
        a_hi1 = (uint16_t)(value2 - value3) >> 8;
    } else {
        uint16_t value4 = RAM16(0x02C7);
        a1 = (uint8_t)(((uint16_t)(value2 - value3) ^ value4) + 1);
        a_hi1 = (uint16_t)(((uint16_t)(value2 - value3) ^ value4) + 1) >> 8;
    }
    if (((a_hi1 << 8) | a1) < 0x40) {
        r->a = (a_hi1 << 8) | a1;
        r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
        r->c = 1;
        r->z = ((a_hi1 << 8) | a1) == 0x40;
        r->n = (uint16_t)(((a_hi1 << 8) | a1) - 0x40) & 0x8000;
        r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    r->a = (a_hi1 << 8) | a1;
    r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
    r->c = 0;
    r->z = ((a_hi1 << 8) | a1) == 0x40;
    r->n = (uint16_t)(((a_hi1 << 8) | a1) - 0x40) & 0x8000;
    r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27388, SOM_RTS, "gen", test_descriptor_seven_horizontal_target_distance_below_64, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 31, 18)
