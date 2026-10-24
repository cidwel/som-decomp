#include "som_c.h"

/* C8E2B5 actor_selected_effect_high_status_bit20   [class A, 11 bytes, 5 instructions]
 * Source: src/rom/actor_selected_effect_high_status_bit20.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void actor_selected_effect_high_status_bit20(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
    uint8_t value = RAM8(ACTOR_STATUS_HIGH + battle_defender_ptr);
    RAM8(ACTOR_STATUS_HIGH + battle_defender_ptr) = value | 0x20;
    SET_A8(r, value | 0x20);
    r->x = battle_defender_ptr;
    r->z = (value | 0x20) == 0;
    r->n = (value | 0x20) & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8E2B5, SOM_RTS, "gen", actor_selected_effect_high_status_bit20, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 11, 5)
