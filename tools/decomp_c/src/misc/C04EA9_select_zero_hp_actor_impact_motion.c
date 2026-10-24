#include "som_c.h"

/* C04EA9 select_zero_hp_actor_impact_motion   [class B, 117 bytes, 56 instructions]
 * Source: src/rom/select_zero_hp_actor_impact_motion.s
 * Documented in docs/rom-combat.md
 * Entry: M=any X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void select_zero_hp_actor_impact_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM8(0xE1E5 + x) = (uint8_t)(RAM8(BATTLE_TEMP_A4) + 1);
    RAM8(ACTOR_STATUS + x) = 2;
    RAM8(ACTOR_DEATH_TIMER + x) = 0x20;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04EA9, SOM_RTS, "gen", select_zero_hp_actor_impact_motion, 0, L_B | L_X | L_Y | L_C | L_V, 1, -1, 0, 117, 56)
