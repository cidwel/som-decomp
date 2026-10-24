#include "som_c.h"

/* C2C171 add_charge_effect_terrain_height   [class A, 18 bytes, 8 instructions]
 * Source: src/rom/add_charge_effect_terrain_height.s
 * Documented in docs/actor-animation-special-helpers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XYV.
 */
static void add_charge_effect_terrain_height(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    JSR(c, 0xC173, 0xC2C1D1); /* read_charge_effect_terrain_height_preserving_actor */
    uint16_t a_all = r->a;
    uint8_t value = RAM8(0xD006 + y);
    RAM8(0xD006 + y) = (uint8_t)((uint8_t)a_all + value);
    RAM8(0xD007 + y) = 0;
    r->v = (((uint8_t)a_all ^ (uint8_t)((uint8_t)a_all + value)) & (value ^ (uint8_t)((uint8_t)a_all + value)) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2C171, SOM_RTS, "gen", add_charge_effect_terrain_height, 0, L_X | L_Y | L_V, 1, 1, 0, 18, 8)
