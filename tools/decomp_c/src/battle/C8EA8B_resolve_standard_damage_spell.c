#include "som_c.h"

/* C8EA8B resolve_standard_damage_spell   [class B, 12 bytes, 5 instructions]
 * Source: src/rom/resolve_standard_damage_spell.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void resolve_standard_damage_spell(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    r->x = RAM16(BATTLE_DEFENDER_PTR);
    JSR(c, 0xEA8F, 0xC8E8A0); /* select_spell_element_multiplier */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xEA92, 0xC8E8C0); /* calculate_spell_attack_roll */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xEA95, 0xC8E9DF); /* queue_spell_damage_with_minimum_one */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8EA8B, SOM_RTS, "gen", resolve_standard_damage_spell, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 12, 5)
