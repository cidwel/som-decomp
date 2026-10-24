#include "som_c.h"

/* C26877 derive_descriptor_thirteen_sixty_frame_velocity_and_thirty_frame_vertical_seed   [class B, 132 bytes, 60 instructions]
 * Source: src/rom/derive_descriptor_thirteen_sixty_frame_velocity_and_thirty_frame_vertical_seed.s
 * Documented in docs/boss-descriptor-thirteen-trajectory.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void derive_descriptor_thirteen_sixty_frame_velocity_and_thirty_frame_vertical_seed(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    RAM16_SET(0x0246, 0);
    RAM16_SET(0x0248, RAM16(0x02AD));
    RAM16_SET(0x024E, 0x3C);
    RAM16_SET(0x0250, 0);
    r->a = 0x3C;
    JSR(c, 0x6886, 0xC22CE6); /* divide_unsigned_double_words_in_software */
    uint16_t value2 = RAM16(0x0256);
    RAM16_SET(0x021A, value2);
    RAM16_SET(0x0246, value2);
    uint16_t value3 = RAM16(0x0258);
    RAM16_SET(0x021C, value3);
    RAM16_SET(0x0248, value3);
    RAM16_SET(0x024E, RAM16(0x02A5));
    RAM16_SET(0x0250, RAM16(0x02A7));
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x689D, 0xC22BC3); /* multiply_signed_double_words_to_quad_word */
    uint16_t value6 = RAM16(0x0287);
    RAM16_SET(0x003A + value6, RAM16(0x0258));
    RAM16_SET(0x003C + value6, RAM16(0x025A));
    RAM16_SET(0x0246, RAM16(0x021A));
    RAM16_SET(0x0248, RAM16(0x021C));
    RAM16_SET(0x024E, RAM16(0x02A9));
    RAM16_SET(0x0250, RAM16(0x02AB));
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x68BC, 0xC22BC3); /* multiply_signed_double_words_to_quad_word */
    bool carry_ret3 = r->c;
    bool overflow_ret3 = r->v;
    uint16_t value13 = RAM16(0x0287);
    RAM16_SET(0x003E + value13, RAM16(0x0258));
    RAM16_SET(0x0040 + value13, RAM16(0x025A));
    RAM16_SET(0x0246, RAM16(0x0FC0));
    RAM16_SET(0x0248, RAM16(0x0FC2));
    uint16_t value18 = RAM16(0x0248);
    uint8_t a_hi1;
    bool carry1;
    bool overflow1;
    if (!(value18 & 0x8000)) {
        a_hi1 = value18 >> 8;
        carry1 = carry_ret3;
        overflow1 = overflow_ret3;
    } else {
        uint16_t value19 = RAM16(0x02C5);
        uint16_t value20 = RAM16(0x0246);
        RAM16_SET(0x0246, (uint16_t)(value19 - value20));
        RAM16_SET(0x0248, (uint16_t)(value19 - value18 - (value19 >= value20 ^ 1)));
        a_hi1 = (uint16_t)(value19 - value18 - (value19 >= value20 ^ 1)) >> 8;
        carry1 = value19 - value18 >= (value19 >= value20 ^ 1);
        overflow1 = ((value19 ^ value18) & (value19 ^ (uint16_t)(value19 - value18 - (value19 >= value20 ^ 1))) & 0x8000) != 0;
    }
    RAM16_SET(0x024E, 0x1E);
    RAM16_SET(0x0250, 0);
    r->c = carry1;
    r->z = 0;
    r->n = 0;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x68ED, 0xC22B2F); /* multiply_unsigned_double_words_in_software */
    uint16_t value21 = RAM16(0x0287);
    RAM16_SET(0x00C4 + value21, RAM16(0x0256));
    RAM16_SET(0x00C6 + value21, RAM16(0x0258));
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26877, SOM_RTS, "gen", derive_descriptor_thirteen_sixty_frame_velocity_and_thirty_frame_vertical_seed, 0, 0, 1, 0, 0, 132, 60)
