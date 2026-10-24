#include "som_c.h"

/* C217A9 test_animation_party_radii_and_mark_contact_slot   [class B, 59 bytes, 34 instructions]
 * Source: src/rom/test_animation_party_radii_and_mark_contact_slot.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void test_animation_party_radii_and_mark_contact_slot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0246);
    uint16_t value2 = RAM16(0x0256);
    uint8_t a1;
    uint8_t a_hi1;
    if (!((uint16_t)(value - value2) & 0x8000)) {
        a1 = (uint8_t)(value - value2);
        a_hi1 = (uint16_t)(value - value2) >> 8;
    } else {
        a1 = (uint8_t)(((uint16_t)(value - value2) ^ 0xFFFF) + 1);
        a_hi1 = (uint16_t)(((uint16_t)(value - value2) ^ 0xFFFF) + 1) >> 8;
    }
    RAM16_SET(0x0252, (a_hi1 << 8) | a1);
    uint16_t value3 = RAM16(0x0248);
    uint16_t value4 = RAM16(0x0258);
    uint16_t value5 = RAM16(0x0252);
    uint8_t a_hi4;
    uint16_t x2;
    bool carry2;
    bool overflow1;
    if ((uint16_t)(value3 + value4) < value5) {
        a_hi4 = (uint16_t)(value3 + value4) >> 8;
        x2 = x;
        carry2 = (uint16_t)(value3 + value4) >= value5;
        overflow1 = ((value3 ^ (uint16_t)(value3 + value4)) & (value4 ^ (uint16_t)(value3 + value4)) & 0x8000) != 0;
    } else {
        uint16_t value6 = RAM16(0x024E);
        uint16_t value7 = RAM16(0x025E);
        uint8_t a2;
        uint8_t a_hi2;
        if (!((uint16_t)(value6 - value7) & 0x8000)) {
            a2 = (uint8_t)(value6 - value7);
            a_hi2 = (uint16_t)(value6 - value7) >> 8;
        } else {
            a2 = (uint8_t)(((uint16_t)(value6 - value7) ^ 0xFFFF) + 1);
            a_hi2 = (uint16_t)(((uint16_t)(value6 - value7) ^ 0xFFFF) + 1) >> 8;
        }
        RAM16_SET(0x0252, (a_hi2 << 8) | a2);
        uint16_t value8 = RAM16(0x0250);
        uint16_t value9 = RAM16(0x0260);
        uint16_t value10 = RAM16(0x0252);
        uint8_t a_hi3;
        uint16_t x1;
        bool carry1;
        if ((uint16_t)(value8 + value9) < value10) {
            a_hi3 = (uint16_t)(value8 + value9) >> 8;
            x1 = x;
            carry1 = (uint16_t)(value8 + value9) >= value10;
        } else {
            uint16_t value11 = RAM16(0x0287);
            uint16_t value12 = RAM16(0x005B + value11);
            RAM16_SET(0x005B + value11, (uint16_t)(y << 4) | value12);
            a_hi3 = ((uint16_t)(y << 4) | value12) >> 8;
            x1 = value11;
            carry1 = 1;
        }
        a_hi4 = a_hi3;
        x2 = x1;
        carry2 = carry1;
        overflow1 = ((value8 ^ (uint16_t)(value8 + value9)) & (value9 ^ (uint16_t)(value8 + value9)) & 0x8000) != 0;
    }
    r->a = (a_hi4 << 8) | (uint8_t)a;
    r->x = x2;
    r->c = carry2;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC217A9, SOM_RTS, "gen", test_animation_party_radii_and_mark_contact_slot, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 59, 34)
