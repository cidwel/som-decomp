#include "som_c.h"

/* C27464 initialize_leaping_projectile_animation_and_motion_callback   [class A, 28 bytes, 11 instructions]
 * Source: src/rom/initialize_leaping_projectile_animation_and_motion_callback.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_leaping_projectile_animation_and_motion_callback(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    r->a = 0x0104;
    r->x = value;
    JSR(c, 0x746E, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x00B2 + value, 0);
    RAM16_SET(0x0000 + value, 1);
    RAM16_SET(0x0090 + value, 0x3F4C);
    r->a = 0x3F4C;
    r->c = 0;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27464, SOM_RTS, "gen", initialize_leaping_projectile_animation_and_motion_callback, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 28, 11)
