#include "som_c.h"

/* C27886 advance_descriptor_ten_chain_death_animation_state   [class A, 22 bytes, 9 instructions]
 * Source: src/rom/advance_descriptor_ten_chain_death_animation_state.s
 * Documented in docs/boss-descriptor-ten-children.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void advance_descriptor_ten_chain_death_animation_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    RAM16_SET(OBJECT_PHASE + battle_defence_work, (uint16_t)(RAM16(OBJECT_PHASE + battle_defence_work) + 1));
    RAM16_SET(0x0098 + battle_defence_work, 0x9811);
    r->a = 0x015C;
    r->x = battle_defence_work;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7896, 0xC21394); GUARD_JSR(c, sp_call, 0x7896); } /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(OBJECT_AGE + battle_defence_work, 0);
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27886, SOM_RTS, "gen", advance_descriptor_ten_chain_death_animation_state, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 22, 9)
