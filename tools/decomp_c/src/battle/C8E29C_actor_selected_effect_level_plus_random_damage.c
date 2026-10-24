#include "som_c.h"

/* C8E29C actor_selected_effect_level_plus_random_damage   [class A, 25 bytes, 11 instructions]
 * Source: src/rom/actor_selected_effect_level_plus_random_damage.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void actor_selected_effect_level_plus_random_damage(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
    r->x = battle_defender_ptr;
    r->z = battle_defender_ptr == 0;
    r->n = battle_defender_ptr & 0x8000;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE2A1, 0xC0389C); GUARD_JSL(c, sp_call, 0xE2A1); } /* random_byte_long_wrapper */
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t value = RAM16(ACTOR_LEVEL + x_ret2);
    RAM16_SET(ACTOR_PENDING_HP_DAMAGE + x_ret2, ((uint16_t)((a_all & 7) + value) & 0xFF) + 1);
    r->a = ((uint16_t)((a_all & 7) + value) & 0xFF) + 1;
    r->c = (a_all & 7) + value > 0xFFFF;
    r->z = ((uint16_t)((a_all & 7) + value) & 0xFF) + 1 == 0;
    r->n = ((uint16_t)((a_all & 7) + value) & 0xFF) + 1 & 0x8000;
    r->v = (((a_all & 7) ^ (uint16_t)((a_all & 7) + value)) & (value ^ (uint16_t)((a_all & 7) + value)) & 0x8000) != 0;
    r->mf = 1;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8E29C, SOM_RTS, "gen", actor_selected_effect_level_plus_random_damage, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 25, 11)
