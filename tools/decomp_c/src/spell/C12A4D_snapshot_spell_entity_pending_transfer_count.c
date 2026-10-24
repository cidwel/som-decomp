#include "som_c.h"

/* C12A4D snapshot_spell_entity_pending_transfer_count   [class A, 15 bytes, 9 instructions]
 * Source: src/rom/snapshot_spell_entity_pending_transfer_count.s
 * Documented in docs/actor-cast-entity-queue.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01B4.  Callers read: BXY.
 */
static void snapshot_spell_entity_pending_transfer_count(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01B4) { c->fail = 3; return; }
    RAM8(0x821C) = RAM8(0x821A);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12A4D, SOM_RTS, "gen", snapshot_spell_entity_pending_transfer_count, 0, L_B | L_X | L_Y, 3, 1, 0, 15, 9)
