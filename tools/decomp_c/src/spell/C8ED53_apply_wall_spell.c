#include "som_c.h"

/* C8ED53 apply_wall_spell   [class A, 21 bytes, 10 instructions]
 * Source: src/rom/apply_wall_spell.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void apply_wall_spell(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
    r->x = battle_defender_ptr;
    JSR(c, 0xED57, 0xC8EA69); /* divide_spell_level_by_target_count */
    RAM8(ACTOR_GUARD_FLAGS + battle_defender_ptr) |= 0x40;
    uint8_t value2 = RAM8(0x039D);
    RAM8(0xE1B8 + battle_defender_ptr) = (uint8_t)(value2 + 2);
    SET_A8(r, (uint8_t)(value2 + 2));
    r->z = (uint8_t)(value2 + 2) == 0;
    r->n = (uint8_t)(value2 + 2) & 0x80;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8ED53, SOM_RTS, "gen", apply_wall_spell, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 21, 10)
