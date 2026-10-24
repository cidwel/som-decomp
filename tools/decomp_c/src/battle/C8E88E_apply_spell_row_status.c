#include "som_c.h"

/* C8E88E apply_spell_row_status   [class A, 18 bytes, 8 instructions]
 * Source: src/rom/apply_spell_row_status.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void apply_spell_row_status(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t value = BUS16_RDL(c, (RAM8(0x03DE) << 0x10) + RAM16(0x03DC) + 0x2ADD, RAM8(0x03DE));
    uint16_t battle_attacker_ptr = RAM16(BATTLE_ATTACKER_PTR);
    RAM16_SET(0x039A, value);
    r->y = battle_attacker_ptr;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE89E, 0xC8E301); GUARD_JSL(c, sp_call, 0xE89E); } /* apply_actor_status_and_timers */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8E88E, SOM_RTS, "gen", apply_spell_row_status, 0, 0, 1, 1, 0, 18, 8)
