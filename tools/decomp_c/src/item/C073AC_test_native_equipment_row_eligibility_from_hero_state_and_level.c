#include "som_c.h"

/* C073AC test_native_equipment_row_eligibility_from_hero_state_and_level   [class B, 47 bytes, 21 instructions]
 * Source: src/rom/test_native_equipment_row_eligibility_from_hero_state_and_level.s
 * Documented in docs/event-menu-inventory-builder.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void test_native_equipment_row_eligibility_from_hero_state_and_level(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x1844);
    uint8_t value2 = RAM8(0x0000 + (uint16_t)(value + 0xFEE0));
    uint8_t a2;
    uint16_t x4;
    bool carry4;
    bool zero2;
    bool negative2;
    bool overflow2;
    if (value2 == 0) {
        uint8_t ring_owner = RAM8(RING_OWNER);
        uint16_t x1;
        if ((ring_owner & 1) != 0) {
            x1 = 0x0186;
        } else {
            x1 = 0x0386;
        }
        uint8_t value3 = RAM8(0xE200 + x1);
        uint8_t value4 = RAM8(0x1843);
        bool carry1;
        if (value3 >= value4) {
            carry1 = value3 >= value4;
        } else {
            carry1 = 0;
        }
        a2 = (uint8_t)(value3 - value4);
        x4 = x1;
        carry4 = carry1;
        zero2 = (uint8_t)(value3 - value4) == 0;
        negative2 = (uint8_t)(value3 - value4) & 0x80;
        overflow2 = ((value3 ^ value4) & (value3 ^ (uint8_t)(value3 - value4)) & 0x80) != 0;
    } else {
        uint8_t a1;
        uint16_t x3;
        bool carry3;
        bool zero1;
        bool negative1;
        bool overflow1;
        if (value2 != 0x40) {
            a1 = value2;
            x3 = (uint16_t)(value + 0xFEE0);
            carry3 = 0;
            zero1 = value2 == 0x40;
            negative1 = (uint8_t)(value2 - 0x40) & 0x80;
            overflow1 = ((value ^ (uint16_t)(value + 0xFEE0)) & ((uint16_t)(value + 0xFEE0) ^ 0xFEE0) & 0x8000) != 0;
        } else {
            uint8_t ring_owner2 = RAM8(RING_OWNER);
            uint16_t x2;
            if ((ring_owner2 & 1) != 0) {
                x2 = 0x0186;
            } else {
                x2 = 0x0386;
            }
            uint8_t value5 = RAM8(0xE200 + x2);
            uint8_t value6 = RAM8(0x1843);
            bool carry2;
            if (value5 >= value6) {
                carry2 = value5 >= value6;
            } else {
                carry2 = 0;
            }
            a1 = (uint8_t)(value5 - value6);
            x3 = x2;
            carry3 = carry2;
            zero1 = (uint8_t)(value5 - value6) == 0;
            negative1 = (uint8_t)(value5 - value6) & 0x80;
            overflow1 = ((value5 ^ value6) & (value5 ^ (uint8_t)(value5 - value6)) & 0x80) != 0;
        }
        a2 = a1;
        x4 = x3;
        carry4 = carry3;
        zero2 = zero1;
        negative2 = negative1;
        overflow2 = overflow1;
    }
    r->a = ((uint16_t)(value + 0xFEE0) >> 8 << 8) | a2;
    r->x = x4;
    r->c = carry4;
    r->z = zero2;
    r->n = negative2;
    r->v = overflow2;
    r->mf = 1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC073AC, SOM_RTL, "gen", test_native_equipment_row_eligibility_from_hero_state_and_level, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 47, 21)
