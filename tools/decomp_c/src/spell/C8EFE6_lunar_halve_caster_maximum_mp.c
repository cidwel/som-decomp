#include "som_c.h"

/* C8EFE6 lunar_halve_caster_maximum_mp   [class A, 10 bytes, 5 instructions]
 * Source: src/rom/lunar_halve_caster_maximum_mp.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void lunar_halve_caster_maximum_mp(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_attacker_ptr = RAM16(BATTLE_ATTACKER_PTR);
    uint8_t value = RAM8(ACTOR_MAX_MP + battle_attacker_ptr);
    RAM8(ACTOR_MAX_MP + battle_attacker_ptr) = value >> 1;
    SET_A8(r, value >> 1);
    r->y = battle_attacker_ptr;
    r->c = value & 0x01;
    r->z = value >> 1 == 0;
    r->n = value >> 1 & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8EFE6, SOM_RTS, "gen", lunar_halve_caster_maximum_mp, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 10, 5)
