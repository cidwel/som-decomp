#include "som_c.h"

/* C26292 reset_selected_boss_to_identity_7a   [class A, 10 bytes, 4 instructions]
 * Source: src/rom/reset_selected_boss_to_identity_7a.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void reset_selected_boss_to_identity_7a(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    r->a = 0x7A;
    r->x = battle_defence_work;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x629A, 0xC0003F); GUARD_JSL(c, sp_call, 0x629A); } /* change_actor_identity_public_jump */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26292, SOM_RTS, "gen", reset_selected_boss_to_identity_7a, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 10, 4)
