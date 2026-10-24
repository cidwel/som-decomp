#include "som_c.h"

/* C205F8 test_first_collision_box_overlap   [class B, 53 bytes, 30 instructions]
 * Source: src/rom/test_first_collision_box_overlap.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABYCV.
 */
static void test_first_collision_box_overlap(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x024A);
    uint16_t value2 = RAM16(0x024C);
    if ((value | value2) == 0) {
        r->a = value | value2;
        r->c = 0;
        RETURN_RTS(c);
    }
    uint16_t value3 = RAM16(0x0246);
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
    if ((uint16_t)(value + value5) < RAM16(0x025E)) {
        r->a = (uint16_t)(value + value5);
        r->c = 0;
        r->v = ((value ^ (uint16_t)(value + value5)) & (value5 ^ (uint16_t)(value + value5)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint16_t value7 = RAM16(0x0248);
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
    if ((uint16_t)(value2 + value9) < value10) {
        r->a = (uint16_t)(value2 + value9);
        r->c = 0;
        r->v = ((value2 ^ (uint16_t)(value2 + value9)) & (value9 ^ (uint16_t)(value2 + value9)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    r->a = (uint16_t)(value2 + value9);
    r->c = (uint16_t)(value2 + value9) >= value10;
    r->v = ((value2 ^ (uint16_t)(value2 + value9)) & (value9 ^ (uint16_t)(value2 + value9)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC205F8, SOM_RTS, "gen", test_first_collision_box_overlap, 0, L_A | L_B | L_Y | L_C | L_V, 1, 0, 0, 53, 30)
