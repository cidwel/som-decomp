#include "som_c.h"

/* C20690 test_second_collision_box_overlap   [class B, 53 bytes, 30 instructions]
 * Source: src/rom/test_second_collision_box_overlap.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABYCV.
 */
static void test_second_collision_box_overlap(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0252);
    uint16_t value2 = RAM16(0x0254);
    uint8_t a4;
    uint8_t a_hi4;
    bool carry3;
    bool overflow2;
    if ((value | value2) == 0) {
        a4 = (uint8_t)(value | value2);
        a_hi4 = (value | value2) >> 8;
        carry3 = 0;
        overflow2 = overflow;
    } else {
        uint16_t value3 = RAM16(0x024E);
        uint16_t value4 = RAM16(0x0256);
        uint8_t a1;
        uint8_t a_hi1;
        if (!((uint16_t)(value3 - value4) & 0x8000)) {
            a1 = (uint8_t)(value3 - value4);
            a_hi1 = (uint16_t)(value3 - value4) >> 8;
        } else {
            a1 = (uint8_t)(((uint16_t)(value3 - value4) ^ 0xFFFF) + 1);
            a_hi1 = (uint16_t)(((uint16_t)(value3 - value4) ^ 0xFFFF) + 1) >> 8;
        }
        RAM16_SET(0x025E, (a_hi1 << 8) | a1);
        uint16_t value5 = RAM16(0x025A);
        uint16_t value6 = RAM16(0x025E);
        uint8_t a3;
        uint8_t a_hi3;
        bool carry2;
        bool overflow1;
        if ((uint16_t)(value + value5) < value6) {
            a3 = (uint8_t)(value + value5);
            a_hi3 = (uint16_t)(value + value5) >> 8;
            carry2 = (uint16_t)(value + value5) >= value6;
            overflow1 = ((value ^ (uint16_t)(value + value5)) & (value5 ^ (uint16_t)(value + value5)) & 0x8000) != 0;
        } else {
            uint16_t value7 = RAM16(0x0250);
            uint16_t value8 = RAM16(0x0258);
            uint8_t a2;
            uint8_t a_hi2;
            if (!((uint16_t)(value7 - value8) & 0x8000)) {
                a2 = (uint8_t)(value7 - value8);
                a_hi2 = (uint16_t)(value7 - value8) >> 8;
            } else {
                a2 = (uint8_t)(((uint16_t)(value7 - value8) ^ 0xFFFF) + 1);
                a_hi2 = (uint16_t)(((uint16_t)(value7 - value8) ^ 0xFFFF) + 1) >> 8;
            }
            RAM16_SET(0x025E, (a_hi2 << 8) | a2);
            uint16_t value9 = RAM16(0x025C);
            uint16_t value10 = RAM16(0x025E);
            bool carry1;
            if ((uint16_t)(value2 + value9) < value10) {
                carry1 = (uint16_t)(value2 + value9) >= value10;
            } else {
                carry1 = 1;
            }
            a3 = (uint8_t)(value2 + value9);
            a_hi3 = (uint16_t)(value2 + value9) >> 8;
            carry2 = carry1;
            overflow1 = ((value2 ^ (uint16_t)(value2 + value9)) & (value9 ^ (uint16_t)(value2 + value9)) & 0x8000) != 0;
        }
        a4 = a3;
        a_hi4 = a_hi3;
        carry3 = carry2;
        overflow2 = overflow1;
    }
    r->a = (a_hi4 << 8) | a4;
    r->c = carry3;
    r->v = overflow2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20690, SOM_RTS, "gen", test_second_collision_box_overlap, 0, L_A | L_B | L_Y | L_C | L_V, 1, 0, 0, 53, 30)
