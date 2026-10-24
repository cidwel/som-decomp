#include "som_c.h"

/* C8EA97 resolve_speed_down_spell   [class B, 12 bytes, 5 instructions]
 * Source: src/rom/resolve_speed_down_spell.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void resolve_speed_down_spell(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    r->x = RAM16(BATTLE_DEFENDER_PTR);
    JSR(c, 0xEA9B, 0xC8E8A0); /* select_spell_element_multiplier */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xEA9E, 0xC8E8C0); /* calculate_spell_attack_roll */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xEAA1, 0xC8E88E); /* apply_spell_row_status */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8EA97, SOM_RTS, "gen", resolve_speed_down_spell, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 12, 5)
