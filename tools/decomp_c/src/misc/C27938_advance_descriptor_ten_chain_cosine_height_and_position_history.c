#include "som_c.h"

/* C27938 advance_descriptor_ten_chain_cosine_height_and_position_history   [class B, 128 bytes, 47 instructions]
 * Source: src/rom/advance_descriptor_ten_chain_cosine_height_and_position_history.s
 * Documented in docs/boss-descriptor-ten-children.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void advance_descriptor_ten_chain_cosine_height_and_position_history(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x002B + x, RAM16(0x00B6 + x));
    RAM16_SET(0x0032 + x, RAM16(0x00B8 + x));
    uint16_t value3 = RAM16(0x00B2 + x);
    RAM16_SET(0x00B2 + x, (uint16_t)(value3 + 0x10));
    r->a = (uint16_t)(value3 + 0x10);
    r->c = value3 + 0x10 > 0xFFFF;
    r->v = ((value3 ^ (uint16_t)(value3 + 0x10)) & ((uint16_t)(value3 + 0x10) ^ 0x10) & 0x8000) != 0;
    JSR(c, 0x7950, 0xC22A59); /* derive_cosine_by_adding_quarter_turn */
    uint16_t a_all = r->a;
    RAM16_SET(0x0246, a_all);
    uint16_t value4 = RAM16(0x0287);
    uint16_t value5 = RAM16(0x00B4 + value4);
    RAM16_SET(0x024E, value5);
    r->a = value5;
    r->x = value4;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x795C, 0xC22B94); /* multiply_signed_words_to_double_word */
    uint16_t value6 = RAM16(0x0287);
    uint16_t value7 = RAM16(0x0257);
    uint16_t value8 = RAM16(0x00B4 + value6);
    RAM16_SET(0x0066 + value6, (uint16_t)(value7 + value8));
    uint16_t value9 = RAM16(0x00B0 + value6);
    uint16_t value10 = RAM16(0x002B + value9);
    uint16_t value11 = RAM16(0x007C + value6);
    uint8_t a2;
    uint8_t a_hi2;
    bool carry1;
    bool zero2;
    bool negative2;
    if (value10 != value11) {
        RAM16_SET(0x00B6 + value6, RAM16(0x00BA + value6));
        RAM16_SET(0x00B8 + value6, RAM16(0x00BC + value6));
        RAM16_SET(0x00BA + value6, RAM16(0x00BE + value6));
        RAM16_SET(0x00BC + value6, RAM16(0x0076 + value6));
        RAM16_SET(0x00BE + value6, RAM16(0x0078 + value6));
        RAM16_SET(0x0076 + value6, RAM16(0x007A + value6));
        RAM16_SET(0x0078 + value6, RAM16(0x007C + value6));
        RAM16_SET(0x007A + value6, RAM16(0x007E + value6));
        RAM16_SET(0x007C + value6, RAM16(0x002B + value9));
        uint16_t value21 = RAM16(0x0032 + value9);
        RAM16_SET(0x007E + value6, value21);
        a2 = (uint8_t)value21;
        a_hi2 = value21 >> 8;
        carry1 = value10 >= value11;
        zero2 = value21 == 0;
        negative2 = value21 & 0x8000;
    } else {
        uint16_t value22 = RAM16(0x0032 + value9);
        uint16_t value23 = RAM16(0x007E + value6);
        uint8_t a1;
        uint8_t a_hi1;
        bool zero1;
        bool negative1;
        if (value22 == value23) {
            a1 = (uint8_t)value22;
            a_hi1 = value22 >> 8;
            zero1 = value22 == value23;
            negative1 = (uint16_t)(value22 - value23) & 0x8000;
        } else {
            RAM16_SET(0x00B6 + value6, RAM16(0x00BA + value6));
            RAM16_SET(0x00B8 + value6, RAM16(0x00BC + value6));
            RAM16_SET(0x00BA + value6, RAM16(0x00BE + value6));
            RAM16_SET(0x00BC + value6, RAM16(0x0076 + value6));
            RAM16_SET(0x00BE + value6, RAM16(0x0078 + value6));
            RAM16_SET(0x0076 + value6, RAM16(0x007A + value6));
            RAM16_SET(0x0078 + value6, RAM16(0x007C + value6));
            RAM16_SET(0x007A + value6, RAM16(0x007E + value6));
            RAM16_SET(0x007C + value6, RAM16(0x002B + value9));
            uint16_t value33 = RAM16(0x0032 + value9);
            RAM16_SET(0x007E + value6, value33);
            a1 = (uint8_t)value33;
            a_hi1 = value33 >> 8;
            zero1 = value33 == 0;
            negative1 = value33 & 0x8000;
        }
        a2 = a1;
        a_hi2 = a_hi1;
        carry1 = value22 >= value23;
        zero2 = zero1;
        negative2 = negative1;
    }
    r->a = (a_hi2 << 8) | a2;
    r->x = value6;
    r->y = value9;
    r->c = carry1;
    r->z = zero2;
    r->n = negative2;
    r->v = ((value7 ^ (uint16_t)(value7 + value8)) & (value8 ^ (uint16_t)(value7 + value8)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27938, SOM_RTS, "gen", advance_descriptor_ten_chain_cosine_height_and_position_history, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 128, 47)
