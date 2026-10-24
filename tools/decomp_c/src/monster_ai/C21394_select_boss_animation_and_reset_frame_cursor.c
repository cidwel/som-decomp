#include "som_c.h"

/* C21394 select_boss_animation_and_reset_frame_cursor   [class A, 25 bytes, 10 instructions]
 * Source: src/rom/select_boss_animation_and_reset_frame_cursor.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void select_boss_animation_and_reset_frame_cursor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    RAM16_SET(0x009A + x, a);
    RAM16_SET(0x009E + x, 1);
    RAM16_SET(0x009C + x, 0);
    RAM8(0x005A + x) = 0;
    RAM8(0x00A2 + x) = 0xCA;
    r->a = 0xCA;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21394, SOM_RTS, "gen", select_boss_animation_and_reset_frame_cursor, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 25, 10)
