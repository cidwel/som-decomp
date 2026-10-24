#include "som_c.h"

/* C21BE5 enqueue_background_boss_animation_graphics_transfer   [class B, 82 bytes, 47 instructions]
 * Source: src/rom/enqueue_background_boss_animation_graphics_transfer.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0200.  Callers read: BYCV.
 */
static void enqueue_background_boss_animation_graphics_transfer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x0ED5 + RAM8(0x0268)) = a;
    RAM8(0x0F55 + (uint8_t)((a_hi << 8) | a)) = RAM8(0x0268);
    RAM8(0x026A) = (uint8_t)((a_hi << 8) | a);
    uint8_t value3 = RAM8(0x02CA);
    if (value3 >= 0x16) {
        r->c = 1;
        RETURN_RTS(c);
    }
    RAM8(0x0268) = (uint8_t)((a_hi << 8) | (uint8_t)(value3 << 2));
    RAM8(0x02CA)++;
    RAM8(0x0FAA) = (uint8_t)(RAM8(0x026A) + 1);
    uint16_t value5 = RAM16(0x026C);
    uint8_t a1;
    uint8_t a_hi1;
    if ((uint16_t)(value5 << 5) < 0x2000) {
        a1 = (uint8_t)(value5 << 5);
        a_hi1 = (uint16_t)(value5 << 5) >> 8;
    } else {
        a1 = (uint8_t)((uint16_t)(value5 << 5) + 0x2000);
        a_hi1 = (uint16_t)((uint16_t)(value5 << 5) + 0x2000) >> 8;
    }
    RAM16_SET(0x0E7D + (uint8_t)((a_hi << 8) | (uint8_t)(value3 << 2)), (uint16_t)(((a_hi1 << 8) | a1) + 0x2000));
    uint16_t value7 = BUS16(c, 0xD97F35 + (uint8_t)(RAM16(0x026A) << 1));
    RAM16_SET(0x0E7F + RAM8(0x0268), (uint16_t)((uint16_t)(value7 << 4) + 0x6000));
    r->a = (uint16_t)((uint16_t)(value7 << 4) + 0x6000);
    r->c = 0;
    r->v = (((uint16_t)(value7 << 4) ^ (uint16_t)((uint16_t)(value7 << 4) + 0x6000)) & ((uint16_t)((uint16_t)(value7 << 4) + 0x6000) ^ 0x6000) & 0x8000) != 0;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21BE5, SOM_RTS, "gen", enqueue_background_boss_animation_graphics_transfer, 0, L_B | L_Y | L_C | L_V, 1, 1, 1, 82, 47)
