#include "som_c.h"

/* C8ECD1 apply_moon_energy_spell   [class A, 25 bytes, 14 instructions]
 * Source: src/rom/apply_moon_energy_spell.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void apply_moon_energy_spell(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
    r->x = battle_defender_ptr;
    { const uint16_t sp_call = r->sp; JSR(c, 0xECD5, 0xC8EA69); GUARD_JSR(c, sp_call, 0xECD5); } /* divide_spell_level_by_target_count */
    uint8_t value = RAM8(0x039D);
    RAM8(BATTLE_TEMP_A4) = (uint8_t)((uint8_t)(value + 1) << 4);
    uint8_t value2 = RAM8(ACTOR_SABER_AND_CRIT_COUNTER + battle_defender_ptr);
    uint8_t battle_temp_a4 = RAM8(BATTLE_TEMP_A4);
    RAM8(ACTOR_SABER_AND_CRIT_COUNTER + battle_defender_ptr) = (value2 & 0x0F) | battle_temp_a4;
    SET_A8(r, (value2 & 0x0F) | battle_temp_a4);
    r->c = (uint8_t)((uint8_t)(value + 1) << 3) & 0x80;
    r->z = ((value2 & 0x0F) | battle_temp_a4) == 0;
    r->n = ((value2 & 0x0F) | battle_temp_a4) & 0x80;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8ECD1, SOM_RTS, "gen", apply_moon_energy_spell, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 25, 14)
