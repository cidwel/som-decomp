#include "som_c.h"

/* C23F4C move_projectile_by_velocity_and_prepare_terrain   [class A, 24 bytes, 10 instructions]
 * Source: src/rom/move_projectile_by_velocity_and_prepare_terrain.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void move_projectile_by_velocity_and_prepare_terrain(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x002B + x, (uint16_t)(RAM16(0x002B + x) + RAM16(0x003C + x)));
    uint16_t value3 = RAM16(0x0032 + x);
    uint16_t value4 = RAM16(0x0040 + x);
    RAM16_SET(0x0032 + x, (uint16_t)(value3 + value4));
    r->a = (uint16_t)(value3 + value4);
    r->v = ((value3 ^ (uint16_t)(value3 + value4)) & (value4 ^ (uint16_t)(value3 + value4)) & 0x8000) != 0;
    JSR(c, 0x3F62, 0xC215B7); /* prepare_boss_object_terrain */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23F4C, SOM_RTS, "gen", move_projectile_by_velocity_and_prepare_terrain, 0, 0, 1, 0, 0, 24, 10)
