#include "som_c.h"

/* C26C35 capture_eligible_boss_target_at_boss_position   [class B, 66 bytes, 29 instructions]
 * Source: src/rom/capture_eligible_boss_target_at_boss_position.s
 * Documented in docs/boss-native-child-capture.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void capture_eligible_boss_target_at_boss_position(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00A9 + x);
    uint16_t value2 = RAM16(0x0190 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
    uint8_t a2;
    uint8_t a_hi2;
    bool zero2;
    bool negative2;
    if ((value2 & 0xC568) != 0) {
        a2 = (uint8_t)(value2 & 0xC568);
        a_hi2 = (value2 & 0xC568) >> 8;
        zero2 = (value2 & 0xC568) == 0;
        negative2 = value2 & 0xC568 & 0x8000;
    } else {
        uint8_t value3 = RAM8(0x0060 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
        uint8_t a1;
        uint8_t a_hi1;
        bool zero1;
        bool negative1;
        if (value3 != 0) {
            a1 = value3;
            a_hi1 = (value2 & 0xC568) >> 8;
            zero1 = value3 == 0;
            negative1 = value3 & 0x80;
        } else {
            RAM8(0x01E5 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) = 0x19;
            RAM8(0x0190 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) |= 1;
            RAM8(0x01B4 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) = 0x20;
            RAM8(0x0045 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) = 0x18;
            RAM16_SET(0x0002 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000), RAM16(0x002B + x));
            uint16_t value6 = RAM16(0x0032 + x);
            RAM16_SET(0x0004 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000), (uint16_t)(value6 + 1));
            a1 = (uint8_t)(value6 + 1);
            a_hi1 = (uint16_t)(value6 + 1) >> 8;
            zero1 = (uint16_t)(value6 + 1) == 0;
            negative1 = (uint16_t)(value6 + 1) & 0x8000;
        }
        a2 = a1;
        a_hi2 = a_hi1;
        zero2 = zero1;
        negative2 = negative1;
    }
    r->a = (a_hi2 << 8) | a2;
    r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
    r->c = (uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000 > 0xFFFF;
    r->z = zero2;
    r->n = negative2;
    r->v = (((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26C35, SOM_RTS, "gen", capture_eligible_boss_target_at_boss_position, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 66, 29)
