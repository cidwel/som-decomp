#include "som_c.h"

/* C2300B draw_boss_frame_random_number   [class A, 33 bytes, 17 instructions]
 * Source: src/rom/draw_boss_frame_random_number.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0200.  Callers read: ABXYCZV.
 */
static void draw_boss_frame_random_number(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    r->mf = 1;
    r->sp -= 1;
    JSR(c, 0x3010, 0xC2302C); /* advance_boss_xor_random_pool */
    r->sp += 1;
    uint16_t a_all = r->a;
    RAM8(0x0246) = (uint8_t)a_all;
    if ((uint8_t)a == 0) {
        uint8_t value = RAM8(0x0246);
        r->a = ((a_all >> 8 << 8) | value) & 0xFF;
        r->z = (((a_all >> 8 << 8) | value) & 0xFF) == 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM8(0x024E) = (uint8_t)((uint8_t)a + 1);
    r->a = (a_all >> 8 << 8) | (uint8_t)((uint8_t)a + 1);
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0x301B, 0xC22AA6); /* multiply_boss_terrain_row_stride */
    uint16_t a_all2 = r->a;
    uint8_t value2 = RAM8(0x0257);
    r->a = ((a_all2 >> 8 << 8) | value2) & 0xFF;
    r->z = (((a_all2 >> 8 << 8) | value2) & 0xFF) == 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2300B, SOM_RTS, "gen", draw_boss_frame_random_number, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 0, 1, 33, 17)
