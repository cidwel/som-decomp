#include "som_c.h"

/* C24C74 retract_body_segments_and_choose_next_phase   [class B, 123 bytes, 55 instructions]
 * Source: src/rom/retract_body_segments_and_choose_next_phase.s
 * Documented in docs/boss-native54-body.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void retract_body_segments_and_choose_next_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value2 = RAM16(0x00B0 + RAM16(0x0287));
    RAM16_SET(0x00BC + value2, (uint16_t)(RAM16(0x00BC + value2) + 1));
    uint16_t value3 = RAM16(0x0287);
    r->a = value2;
    r->x = value3;
    JSR(c, 0x4C81, 0xC24DB9); /* consume_body_damage_or_parent_phase15_and_enter_hurt */
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    if (carry_ret) {
        r->c = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if (RAM16(0x00B2 + x_ret) == 0) {
        if (RAM16(0x00BC + x_ret) == 0) {
            RAM16_SET(OBJECT_PHASE + x_ret, 8);
            RAM16_SET(OBJECT_AGE + x_ret, 0);
            r->a = 8;
            r->c = 0;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0x78;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x4CDB, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        RAM16_SET(OBJECT_PHASE + x_ret, 2);
        r->a = 2;
        r->c = 0;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value6 = RAM16(OBJECT_AGE + x_ret);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (value6 != 4) {
        a1 = (uint8_t)value6;
        a_hi1 = value6 >> 8;
        x1 = x_ret;
        y1 = y;
        zero1 = value6 == 4;
        negative1 = (uint16_t)(value6 - 4) & 0x8000;
        overflow1 = overflow;
    } else {
        RAM8(0xF804 + y) ^= 0x40;
        uint16_t value8 = RAM16(0x00B8 + x_ret);
        RAM16_SET(0x00B8 + x_ret, (uint16_t)(value8 - 4));
        uint16_t value9 = RAM16(0x0000 + (uint16_t)(value8 - 4));
        if ((value9 & 0x0F) != 2) {
            uint8_t value10 = BUS8(c, 0xDCE637 + ((value9 & 0x0F) >> 1));
            RAM8(0x0000 + (uint16_t)(value8 - 4)) = value10;
        }
        uint16_t value11 = RAM16(0x0287);
        RAM16_SET(0x00B2 + value11, (uint16_t)(RAM16(0x00B2 + value11) - 1));
        RAM16_SET(OBJECT_AGE + value11, 0);
        uint16_t value13 = RAM16(0x028B);
        RAM16_SET(0xF800 + ((((uint8_t)value13 << 8) | (value13 >> 8)) >> 1), (uint16_t)(RAM16(0xF800 + ((((uint8_t)value13 << 8) | (value13 >> 8)) >> 1)) - 1));
        a1 = (uint8_t)((((uint8_t)value13 << 8) | (value13 >> 8)) >> 1);
        a_hi1 = (((uint8_t)value13 << 8) | (value13 >> 8)) >> 1 >> 8;
        x1 = (((uint8_t)value13 << 8) | (value13 >> 8)) >> 1;
        y1 = (uint16_t)(value8 - 4);
        zero1 = RAM16(0xF800 + ((((uint8_t)value13 << 8) | (value13 >> 8)) >> 1)) == 0;
        negative1 = RAM16(0xF800 + ((((uint8_t)value13 << 8) | (value13 >> 8)) >> 1)) & 0x8000;
        overflow1 = ((value8 ^ 4) & (value8 ^ (uint16_t)(value8 - 4)) & 0x8000) != 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24C74, SOM_RTS, "gen", retract_body_segments_and_choose_next_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 123, 55)
