#include "som_c.h"

/* C2C1D1 read_charge_effect_terrain_height_preserving_actor   [class A, 6 bytes, 4 instructions]
 * Source: src/rom/read_charge_effect_terrain_height_preserving_actor.s
 * Documented in docs/actor-animation-special-helpers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: AXY.
 */
static void read_charge_effect_terrain_height_preserving_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    r->sp -= 2;
    JSR(c, 0xC1D4, 0xC2C1D7); /* read_charge_effect_terrain_height */
    r->sp += 2;
    r->x = x;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2C1D1, SOM_RTS, "gen", read_charge_effect_terrain_height_preserving_actor, 0, L_A | L_X | L_Y, 2, 1, 0, 6, 4)
