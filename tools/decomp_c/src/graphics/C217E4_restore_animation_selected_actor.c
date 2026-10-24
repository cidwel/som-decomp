#include "som_c.h"

/* C217E4 restore_animation_selected_actor   [class A, 3 bytes, 2 instructions]
 * Source: src/rom/restore_animation_selected_actor.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void restore_animation_selected_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    r->x = battle_defence_work;
    r->z = battle_defence_work == 0;
    r->n = battle_defence_work & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC217E4, SOM_RTS, "gen", restore_animation_selected_actor, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 3, 2)
