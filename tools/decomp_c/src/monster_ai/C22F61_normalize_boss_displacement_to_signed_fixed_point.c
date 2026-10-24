#include "som_c.h"

/* C22F61 normalize_boss_displacement_to_signed_fixed_point   [class B, 107 bytes, 54 instructions]
 * Source: src/rom/normalize_boss_displacement_to_signed_fixed_point.s
 * Documented in docs/boss-native-unrecovered-55.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XYCV.
 */
static void normalize_boss_displacement_to_signed_fixed_point(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    RAM16_SET(0x02A1, (uint16_t)(RAM16(0x02A1) - RAM16(0x0299)));
    uint16_t value3 = RAM16(0x029D);
    uint16_t value4 = RAM16(0x0295);
    RAM16_SET(0x029D, (uint16_t)(value3 - value4));
    uint16_t value5 = RAM16(0x029D);
    if (value5 != 0) {
        r->a = value5;
        r->c = value3 >= value4;
        r->v = ((value3 ^ value4) & (value3 ^ (uint16_t)(value3 - value4)) & 0x8000) != 0;
        JSR(c, 0x2F9C, 0xC22FCC); /* derive_boss_displacement_squared_length_and_root */
        RAM16_SET(0x0246, 0);
        RAM16_SET(0x0248, RAM16(0x029D));
        RAM16_SET(0x0250, 0);
        uint16_t value7 = RAM16(0x02AD);
        RAM16_SET(0x024E, value7);
        r->a = value7;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x2FAB, 0xC22DA5); /* divide_signed_double_words_with_remainder */
        RAM16_SET(0x02A5, RAM16(0x0256));
        RAM16_SET(0x02A7, RAM16(0x0258));
        RAM16_SET(0x0246, 0);
        RAM16_SET(0x0248, RAM16(0x02A1));
        RAM16_SET(0x0250, 0);
        uint16_t value11 = RAM16(0x02AD);
        RAM16_SET(0x024E, value11);
        r->a = value11;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x2FC2, 0xC22DA5); /* divide_signed_double_words_with_remainder */
        RAM16_SET(0x02A9, RAM16(0x0256));
        RAM16_SET(0x02AB, RAM16(0x0258));
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value14 = RAM16(0x02A1);
    RAM16_SET(0x02AD, value14);
    uint16_t value15 = RAM16(0x02AD);
    uint8_t a_hi1;
    bool carry1;
    bool overflow1;
    if (!(value15 & 0x8000)) {
        a_hi1 = value15 >> 8;
        carry1 = value3 >= value4;
        overflow1 = ((value3 ^ value4) & (value3 ^ (uint16_t)(value3 - value4)) & 0x8000) != 0;
    } else {
        uint16_t value16 = RAM16(0x02C5);
        RAM16_SET(0x02AD, (uint16_t)(value16 - value15));
        a_hi1 = (uint16_t)(value16 - value15) >> 8;
        carry1 = value16 >= value15;
        overflow1 = ((value16 ^ value15) & (value16 ^ (uint16_t)(value16 - value15)) & 0x8000) != 0;
    }
    RAM16_SET(0x02A5, 0);
    RAM16_SET(0x02A7, 0);
    if (value14 & 0x8000) {
        RAM16_SET(0x02AB, 0xFFFF);
        RAM16_SET(0x02A9, 0);
        r->c = carry1;
        r->v = overflow1;
        RETURN_RTS(c);
    }
    RAM16_SET(0x02AB, 1);
    RAM16_SET(0x02A9, 0);
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22F61, SOM_RTS, "gen", normalize_boss_displacement_to_signed_fixed_point, 0, L_X | L_Y | L_C | L_V, 1, 0, 0, 107, 54)
