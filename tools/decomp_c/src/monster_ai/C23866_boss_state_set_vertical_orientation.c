#include "som_c.h"

/* C23866 boss_state_set_vertical_orientation   [class A, 15 bytes, 6 instructions]
 * Source: src/rom/boss_state_set_vertical_orientation.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void boss_state_set_vertical_orientation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(0x0098 + battle_defence_work);
    RAM16_SET(0x0098 + battle_defence_work, (value & 0xFF7F) | 0x80);
    r->a = (value & 0xFF7F) | 0x80;
    r->x = battle_defence_work;
    r->z = ((value & 0xFF7F) | 0x80) == 0;
    r->n = ((value & 0xFF7F) | 0x80) & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23866, SOM_RTS, "gen", boss_state_set_vertical_orientation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 15, 6)
