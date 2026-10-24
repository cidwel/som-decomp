#include "som_c.h"

/* C22CBF divide_unsigned_word_by_word_in_software   [class B, 39 bytes, 22 instructions]
 * Source: src/rom/divide_unsigned_word_by_word_in_software.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=8 bit DB=$7E D=$0200.  Callers read: BXYZV.
 */
static void divide_unsigned_word_by_word_in_software(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t y = r->y;
    const bool overflow = r->v;
    if (RAM16(0x024E) == 0) {
        r->a = 0xFFFF;
        r->z = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0256, 0);
    uint16_t value2 = RAM16(0x02C5);
    uint8_t a1 = (uint8_t)value2;
    uint8_t a_hi1 = value2 >> 8;
    uint8_t x1 = 0x10;
    for (;;) {
        RAM16_SET(0x0256, (uint16_t)(RAM16(0x0256) << 1));
        uint16_t value4 = RAM16(0x0246);
        RAM16_SET(0x0246, (uint16_t)(RAM16(0x0246) << 1));
        uint16_t value5 = RAM16(0x024E);
        uint8_t a2;
        uint8_t a_hi2;
        if ((uint16_t)((((a_hi1 << 8) | a1) << 1) | (value4 >> 0x0F)) < value5) {
            a2 = (uint8_t)((((a_hi1 << 8) | a1) << 1) | (value4 >> 0x0F));
            a_hi2 = (uint16_t)((((a_hi1 << 8) | a1) << 1) | (value4 >> 0x0F)) >> 8;
        } else {
            RAM16_SET(0x0256, (uint16_t)(RAM16(0x0256) + 1));
            a2 = (uint8_t)((uint16_t)((((a_hi1 << 8) | a1) << 1) | (value4 >> 0x0F)) - value5 - ((uint16_t)((((a_hi1 << 8) | a1) << 1) | (value4 >> 0x0F)) >= value5 ^ 1));
            a_hi2 = (uint16_t)((uint16_t)((((a_hi1 << 8) | a1) << 1) | (value4 >> 0x0F)) - value5 - ((uint16_t)((((a_hi1 << 8) | a1) << 1) | (value4 >> 0x0F)) >= value5 ^ 1)) >> 8;
        }
        a1 = a2;
        a_hi1 = a_hi2;
        x1 = (uint8_t)(x1 - 1);
        if (!(x1 != 0)) break;
    }
    RAM16_SET(0x025E, (a_hi1 << 8) | a1);
    uint16_t value6 = RAM16(0x02C5);
    r->a = value6;
    r->x = x1;
    r->y = y;
    r->z = value6 == 0;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22CBF, SOM_RTS, "gen", divide_unsigned_word_by_word_in_software, 0, L_B | L_X | L_Y | L_Z | L_V, 1, 0, 1, 39, 22)
