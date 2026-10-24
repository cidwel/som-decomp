#include "som_c.h"

/* C22999 divide_boss_palette_channel_deltas_by_duration   [class A, 36 bytes, 19 instructions]
 * Source: src/rom/divide_boss_palette_channel_deltas_by_duration.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void divide_boss_palette_channel_deltas_by_duration(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x009A + x);
    RAM16_SET(0x0268, value);
    uint8_t value2 = RAM8(0x02C5);
    uint8_t a_hi1 = value >> 8;
    uint8_t x1 = (uint8_t)x;
    uint8_t y1 = value2;
    for (;;) {
        uint16_t value3 = BUS16(c, RAM16(0x0279) + 0x7E0000 + y1);
        uint16_t value4 = BUS16(c, RAM16(0x0276) + 0x7E0000 + y1);
        RAM16_SET(0x0246, (uint16_t)(value3 - value4));
        uint16_t value5 = RAM16(0x0268);
        RAM16_SET(0x024E, value5);
        r->a = value5;
        r->x = x1;
        r->y = y1;
        r->c = value3 >= value4;
        r->v = ((value3 ^ value4) & (value3 ^ (uint16_t)(value3 - value4)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 1;
        r->db = 0x7E;
        r->dp = 0x0200;
        JSR(c, 0x29AF, 0xC22D69); /* divide_signed_word_by_word_with_remainder */
        uint8_t x_ret = r->x;
        uint16_t value6 = RAM16(0x0256);
        BUS16_SET(c, RAM16(0x0279) + 0x7E0000 + y1, value6);
        uint8_t value7 = RAM8(0x0266);
        a_hi1 = value6 >> 8;
        x1 = x_ret;
        y1 = (uint8_t)(y1 + 2);
        if (!(y1 != value7)) break;
    }
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22999, SOM_RTS, "gen", divide_boss_palette_channel_deltas_by_duration, 0, 0, 1, 0, 0, 36, 19)
