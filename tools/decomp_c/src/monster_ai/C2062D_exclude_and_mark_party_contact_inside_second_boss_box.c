#include "som_c.h"

/* C2062D exclude_and_mark_party_contact_inside_second_boss_box   [class B, 99 bytes, 50 instructions]
 * Source: src/rom/exclude_and_mark_party_contact_inside_second_boss_box.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABYCV.
 */
static void exclude_and_mark_party_contact_inside_second_boss_box(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint16_t value = RAM16(0x028B);
    uint8_t value2 = BUS8(c, 0xC205F0 + value);
    uint8_t value3 = RAM8(0x005A + (uint16_t)((uint16_t)((((uint8_t)a << 8) | (a >> 8)) << 1) + 0xE000));
    if ((value2 & value3) != 0) {
        r->a = (uint16_t)((uint16_t)((((uint8_t)a << 8) | (a >> 8)) << 1) + 0xE000) >> 8 << 8 | (value2 & value3);
        r->y = (uint16_t)((uint16_t)((((uint8_t)a << 8) | (a >> 8)) << 1) + 0xE000);
        r->c = 1;
        r->v = (((uint16_t)((((uint8_t)a << 8) | (a >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)a << 8) | (a >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)a << 8) | (a >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint16_t value4 = RAM16(0x0252);
    uint16_t value5 = RAM16(0x0254);
    if ((value4 | value5) == 0) {
        r->a = value4 | value5;
        r->y = (uint16_t)((uint16_t)((((uint8_t)a << 8) | (a >> 8)) << 1) + 0xE000);
        r->c = 0;
        r->v = (((uint16_t)((((uint8_t)a << 8) | (a >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)a << 8) | (a >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)a << 8) | (a >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint16_t value6 = RAM16(0x024E);
    uint16_t value7 = RAM16(0x0256);
    uint8_t a1;
    uint8_t a_hi1;
    if (!((uint16_t)(value6 - value7) & 0x8000)) {
        a1 = (uint8_t)(value6 - value7);
        a_hi1 = (uint16_t)(value6 - value7) >> 8;
    } else {
        a1 = (uint8_t)(((uint16_t)(value6 - value7) ^ 0xFFFF) + 1);
        a_hi1 = (uint16_t)(((uint16_t)(value6 - value7) ^ 0xFFFF) + 1) >> 8;
    }
    RAM16_SET(0x025E, (a_hi1 << 8) | a1);
    uint16_t value8 = RAM16(0x025A);
    if ((uint16_t)(value4 + value8) < RAM16(0x025E)) {
        r->a = (uint16_t)(value4 + value8);
        r->y = (uint16_t)((uint16_t)((((uint8_t)a << 8) | (a >> 8)) << 1) + 0xE000);
        r->c = 0;
        r->v = ((value4 ^ (uint16_t)(value4 + value8)) & (value8 ^ (uint16_t)(value4 + value8)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint16_t value10 = RAM16(0x0250);
    uint16_t value11 = RAM16(0x0258);
    uint8_t a2;
    uint8_t a_hi2;
    if (!((uint16_t)(value10 - value11) & 0x8000)) {
        a2 = (uint8_t)(value10 - value11);
        a_hi2 = (uint16_t)(value10 - value11) >> 8;
    } else {
        a2 = (uint8_t)(((uint16_t)(value10 - value11) ^ 0xFFFF) + 1);
        a_hi2 = (uint16_t)(((uint16_t)(value10 - value11) ^ 0xFFFF) + 1) >> 8;
    }
    RAM16_SET(0x025E, (a_hi2 << 8) | a2);
    uint16_t value12 = RAM16(0x025C);
    uint16_t value13 = RAM16(0x025E);
    if ((uint16_t)(value5 + value12) < value13) {
        r->a = (uint16_t)(value5 + value12);
        r->y = (uint16_t)((uint16_t)((((uint8_t)a << 8) | (a >> 8)) << 1) + 0xE000);
        r->c = 0;
        r->v = ((value5 ^ (uint16_t)(value5 + value12)) & (value12 ^ (uint16_t)(value5 + value12)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint8_t value14 = BUS8(c, 0xC205F0 + value);
    RAM8(0x005A + (uint16_t)((uint16_t)((((uint8_t)a << 8) | (a >> 8)) << 1) + 0xE000)) = value14 | RAM8(0x005A + (uint16_t)((uint16_t)((((uint8_t)a << 8) | (a >> 8)) << 1) + 0xE000));
    r->a = 0;
    r->x = 0;
    r->y = (uint16_t)((uint16_t)((((uint8_t)a << 8) | (a >> 8)) << 1) + 0xE000);
    r->c = (uint16_t)(value5 + value12) >= value13;
    r->v = ((value5 ^ (uint16_t)(value5 + value12)) & (value12 ^ (uint16_t)(value5 + value12)) & 0x8000) != 0;
    JSR(c, 0x068B, 0xC230E3); /* request_boss_sound_with_parameter_word */
    r->c = 1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2062D, SOM_RTS, "gen", exclude_and_mark_party_contact_inside_second_boss_box, 0, L_A | L_B | L_Y | L_C | L_V, 1, 0, 0, 99, 50)
