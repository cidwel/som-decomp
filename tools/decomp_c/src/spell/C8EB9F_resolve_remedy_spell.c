#include "som_c.h"

/* C8EB9F resolve_remedy_spell   [class B, 20 bytes, 8 instructions]
 * Source: src/rom/resolve_remedy_spell.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void resolve_remedy_spell(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
    RAM8(0x038F) = 4;
    r->a = (a_hi << 8) | 4;
    r->x = battle_defender_ptr;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEBA7, 0xC8E8C0); GUARD_JSR(c, sp_call, 0xEBA7); } /* calculate_spell_attack_roll */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEBAA, 0xC8EA69); GUARD_JSR(c, sp_call, 0xEBAA); } /* divide_spell_level_by_target_count */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEBAD, 0xC8E9FC); GUARD_JSR(c, sp_call, 0xEBAD); } /* cure_actor_statuses_and_shorten_timers */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEBB1, 0xC03F28); GUARD_JSL(c, sp_call, 0xEBB1); } /* refresh_controller_status_public_call */
    r->mf = 1;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8EB9F, SOM_RTS, "gen", resolve_remedy_spell, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 20, 8)
