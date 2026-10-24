#include "som_c.h"

/* C23A63 compare_target_axis_proximity_with_literal_early_return   [class A, 55 bytes, 27 instructions]
 * Source: src/rom/compare_target_axis_proximity_with_literal_early_return.s
 * Documented in docs/boss-descriptor-one.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void compare_target_axis_proximity_with_literal_early_return(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    RAM16_SET(0x0295, RAM16(0x0002 + (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)));
    RAM16_SET(0x0297, RAM16(0x0004 + (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)));
    uint16_t value3 = RAM16(0x0287);
    uint16_t value4 = RAM16(0x002B + value3);
    uint16_t value5 = RAM16(0x0295);
    uint8_t a1;
    uint8_t a_hi1;
    if (!((uint16_t)(value4 - value5) & 0x8000)) {
        a1 = (uint8_t)(value4 - value5);
        a_hi1 = (uint16_t)(value4 - value5) >> 8;
    } else {
        a1 = (uint8_t)(((uint16_t)(value4 - value5) ^ 0xFFFF) + 1);
        a_hi1 = (uint16_t)(((uint16_t)(value4 - value5) ^ 0xFFFF) + 1) >> 8;
    }
    uint8_t a3;
    uint8_t a_hi3;
    bool carry1;
    bool overflow1;
    if (((a_hi1 << 8) | a1) < 0x10) {
        a3 = a1;
        a_hi3 = a_hi1;
        carry1 = ((a_hi1 << 8) | a1) >= 0x10;
        overflow1 = ((value4 ^ value5) & (value4 ^ (uint16_t)(value4 - value5)) & 0x8000) != 0;
    } else {
        uint16_t value6 = RAM16(0x0032 + value3);
        uint16_t value7 = RAM16(0x0297);
        uint8_t a2;
        uint8_t a_hi2;
        if (!((uint16_t)(value6 - value7) & 0x8000)) {
            a2 = (uint8_t)(value6 - value7);
            a_hi2 = (uint16_t)(value6 - value7) >> 8;
        } else {
            a2 = (uint8_t)(((uint16_t)(value6 - value7) ^ 0xFFFF) + 1);
            a_hi2 = (uint16_t)(((uint16_t)(value6 - value7) ^ 0xFFFF) + 1) >> 8;
        }
        a3 = a2;
        a_hi3 = a_hi2;
        carry1 = ((a_hi2 << 8) | a2) >= 8;
        overflow1 = ((value6 ^ value7) & (value6 ^ (uint16_t)(value6 - value7)) & 0x8000) != 0;
    }
    r->a = (a_hi3 << 8) | a3;
    r->x = value3;
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23A63, SOM_RTS, "gen", compare_target_axis_proximity_with_literal_early_return, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 55, 27)
