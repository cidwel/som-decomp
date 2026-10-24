#include "som_c.h"

/* C22FCC derive_boss_displacement_squared_length_and_root   [class B, 63 bytes, 31 instructions]
 * Source: src/rom/derive_boss_displacement_squared_length_and_root.s
 * Documented in docs/boss-native-unrecovered-55.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XYCV.
 */
static void derive_boss_displacement_squared_length_and_root(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x02A1);
    RAM16_SET(0x0246, value);
    RAM16_SET(0x024E, value);
    r->a = value;
    JSR(c, 0x2FD4, 0xC22B94); /* multiply_signed_words_to_double_word */
    RAM16_SET(0x02A5, RAM16(0x0256));
    RAM16_SET(0x02A7, RAM16(0x0258));
    uint16_t value4 = RAM16(0x029D);
    RAM16_SET(0x0246, value4);
    RAM16_SET(0x024E, value4);
    r->a = value4;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x2FE5, 0xC22B94); /* multiply_signed_words_to_double_word */
    RAM16_SET(0x02AD, RAM16(0x0256));
    RAM16_SET(0x02AF, RAM16(0x0258));
    uint16_t value7 = RAM16(0x02A5);
    uint16_t value8 = RAM16(0x02AD);
    RAM16_SET(0x02A5, (uint16_t)(value7 + value8));
    RAM16_SET(0x02A7, (uint16_t)(RAM16(0x02A7) + RAM16(0x02AF) + (value7 + value8 > 0xFFFF)));
    RAM16_SET(0x0246, RAM16(0x02A5));
    uint16_t value12 = RAM16(0x02A7);
    RAM16_SET(0x0248, value12);
    r->a = value12;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x3005, 0xC22DF9); /* derive_unsigned_double_word_integer_square_root */
    RAM16_SET(0x02AD, RAM16(0x024E));
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22FCC, SOM_RTS, "gen", derive_boss_displacement_squared_length_and_root, 0, L_X | L_Y | L_C | L_V, 1, 0, 0, 63, 31)
