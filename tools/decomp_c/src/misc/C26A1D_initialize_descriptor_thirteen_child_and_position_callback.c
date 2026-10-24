#include "som_c.h"

/* C26A1D initialize_descriptor_thirteen_child_and_position_callback   [class B, 109 bytes, 45 instructions]
 * Source: src/rom/initialize_descriptor_thirteen_child_and_position_callback.s
 * Documented in docs/boss-descriptor-thirteen-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_thirteen_child_and_position_callback(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0287);
    r->x = value;
    JSR(c, 0x6A21, 0xC20CE0); /* set_boss_animation_bank_low_byte_c7 */
    RAM16_SET(0x0000 + value, 1);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    r->a = 0x014A;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x6A30, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x0090 + value, 0x6A98);
    uint16_t value2 = RAM16(0x0287);
    uint16_t value3 = RAM16(0x00B0 + value2);
    uint16_t value4 = RAM16(OBJECT_PHASE + value3);
    if (value4 >= 6) {
        r->a = value4;
        r->x = value2;
        r->y = value3;
        r->c = 1;
        r->z = value4 == 6;
        r->n = (uint16_t)(value4 - 6) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0295, RAM16(0x0098 + value3) & 0x40);
    uint16_t value6 = RAM16(0x0098 + value2);
    uint16_t value7 = RAM16(0x0295);
    RAM16_SET(0x0098 + value2, (value6 & 0xFFBF) | value7);
    uint8_t value8 = RAM8(0x0089 + value3);
    uint8_t value9 = RAM8(0x00B4 + value2);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x3;
    bool zero1;
    bool negative1;
    if (value8 == value9) {
        a1 = value8;
        a_hi1 = ((value6 & 0xFFBF) | value7) >> 8;
        x3 = value2;
        zero1 = value8 == value9;
        negative1 = (uint8_t)(value8 - value9) & 0x80;
    } else {
        RAM8(0x00B4 + value2) = value8;
        uint16_t x1 = 0;
        for (;;) {
            uint8_t value10 = BUS8(c, 0xC26A8A + x1);
            uint16_t x2;
            if (value8 == value10) {
                x2 = x1;
            } else {
                if ((uint16_t)(x1 + 1) < 4) {
                    x1 = (uint16_t)(x1 + 1);
                    continue;
                }
                x2 = (uint16_t)(x1 + 1);
            }
            x1 = x2;
            break;
        }
        uint16_t value11 = BUS16(c, 0xC26A8E + (uint16_t)(x1 << 1));
        uint16_t value12 = RAM16(0x0287);
        r->a = value11;
        r->x = value12;
        r->y = value3;
        r->c = x1 & 0x8000;
        r->v = overflow;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x6A83, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        uint16_t a_all3 = r->a;
        bool zero_ret3 = r->z;
        bool negative_ret3 = r->n;
        a1 = (uint8_t)a_all3;
        a_hi1 = a_all3 >> 8;
        x3 = value12;
        zero1 = zero_ret3;
        negative1 = negative_ret3;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x3;
    r->y = value3;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26A1D, SOM_RTS, "gen", initialize_descriptor_thirteen_child_and_position_callback, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 109, 45)
