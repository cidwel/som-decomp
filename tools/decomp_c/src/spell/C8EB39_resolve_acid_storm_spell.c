#include "som_c.h"

/* C8EB39 resolve_acid_storm_spell   [class B, 27 bytes, 11 instructions]
 * Source: src/rom/resolve_acid_storm_spell.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void resolve_acid_storm_spell(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    r->x = RAM16(BATTLE_DEFENDER_PTR);
    JSR(c, 0xEB3D, 0xC8E8A0); /* select_spell_element_multiplier */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xEB40, 0xC8E8C0); /* calculate_spell_attack_roll */
    uint16_t x_ret = r->x;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xEB43, 0xC8E9DF); /* queue_spell_damage_with_minimum_one */
    RAM8(ACTOR_BUFF_FLAGS + x_ret) = (RAM8(ACTOR_BUFF_FLAGS + x_ret) & 0xFC) | 2;
    uint8_t value2 = RAM8(0x039C);
    RAM8(0xE1BC + x_ret) = value2;
    SET_A8(r, value2);
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8EB39, SOM_RTS, "gen", resolve_acid_storm_spell, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 27, 11)
