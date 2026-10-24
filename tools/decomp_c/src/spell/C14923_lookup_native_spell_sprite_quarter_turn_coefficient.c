#include "som_c.h"

/* C14923 lookup_native_spell_sprite_quarter_turn_coefficient   [class A, 23 bytes, 17 instructions]
 * Source: src/rom/lookup_native_spell_sprite_quarter_turn_coefficient.s
 * Documented in docs/actor-cast-entity-trigonometry.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABY.
 */
static void lookup_native_spell_sprite_quarter_turn_coefficient(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    r->a = (a_hi << 8) | (uint8_t)(a + 0x40);
    r->c = a + 0x40 > 0xFF;
    r->z = (uint8_t)(a + 0x40) == 0;
    r->n = (uint8_t)(a + 0x40) & 0x80;
    r->v = ((a ^ (uint8_t)(a + 0x40)) & ((uint8_t)(a + 0x40) ^ 0x40) & 0x80) != 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4935, 0xC148D9); GUARD_JSR(c, sp_call, 0x4935); } /* lookup_native_spell_sprite_angle_coefficient */
    r->sp += 4;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC14923, SOM_RTS, "gen", lookup_native_spell_sprite_quarter_turn_coefficient, 0, L_A | L_B | L_Y, 6, 1, 0, 23, 17)
