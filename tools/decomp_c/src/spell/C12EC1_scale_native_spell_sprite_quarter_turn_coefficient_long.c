#include "som_c.h"

/* C12EC1 scale_native_spell_sprite_quarter_turn_coefficient_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/scale_native_spell_sprite_quarter_turn_coefficient_long.s
 * Documented in docs/actor-cast-entity-trigonometry.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: ABY.
 */
static void scale_native_spell_sprite_quarter_turn_coefficient_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2EC3, 0xC14993); GUARD_JSR(c, sp_call, 0x2EC3); } /* scale_native_spell_sprite_quarter_turn_coefficient */
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12EC1, SOM_RTL, "gen", scale_native_spell_sprite_quarter_turn_coefficient_long, 0, L_A | L_B | L_Y, 1, -1, 0, 4, 2)
