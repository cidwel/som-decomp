#include "som_c.h"

/* C2C021 prepare_actor_charge_effect_primary_record   [class B, 44 bytes, 17 instructions]
 * Source: src/rom/prepare_actor_charge_effect_primary_record.s
 * Documented in docs/actor-animation-special-helpers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XYV.
 */
static void prepare_actor_charge_effect_primary_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM8(0xD000 + y) = a;
    uint8_t value = RAM8(0xE010 + x);
    uint8_t a1;
    if (!(value & 0x80)) {
        a1 = value;
    } else {
        a1 = 3;
    }
    RAM8(0xD001 + y) = a1;
    RAM8(0xD001 + y) = (RAM8(0xE00B + x) & 0x80) | RAM8(0xD001 + y);
    RAM8(0xD008 + y) = 0;
    RAM8(0xD009 + y) = 0;
    JSR(c, 0xC043, 0xC2C04D); /* position_actor_charge_effect_in_wrapped_map */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xC046, 0xC2C171); /* add_charge_effect_terrain_height */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xC049, 0xC2C148); /* prepare_actor_charge_effect_velocity */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2C021, SOM_RTS, "gen", prepare_actor_charge_effect_primary_record, 0, L_X | L_Y | L_V, 1, 1, 0, 44, 17)
