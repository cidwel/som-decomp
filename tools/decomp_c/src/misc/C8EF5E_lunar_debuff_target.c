#include "som_c.h"

/* C8EF5E lunar_debuff_target   [class A, 22 bytes, 9 instructions]
 * Source: src/rom/lunar_debuff_target.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void lunar_debuff_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
    uint8_t value = RAM8(0x039C);
    RAM8(0xE1B7 + battle_defender_ptr) = value;
    RAM8(0xE1BA + battle_defender_ptr) = value;
    RAM8(0xE1BB + battle_defender_ptr) = value;
    RAM8(0xE1BC + battle_defender_ptr) = value;
    RAM8(ACTOR_BUFF_FLAGS + battle_defender_ptr) = 0xAA;
    SET_A8(r, 0xAA);
    r->x = battle_defender_ptr;
    r->z = 0;
    r->n = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8EF5E, SOM_RTS, "gen", lunar_debuff_target, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 22, 9)
