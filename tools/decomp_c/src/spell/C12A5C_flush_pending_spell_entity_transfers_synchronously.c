#include "som_c.h"

/* C12A5C flush_pending_spell_entity_transfers_synchronously   [class A, 36 bytes, 21 instructions]
 * Source: src/rom/flush_pending_spell_entity_transfers_synchronously.s
 * Documented in docs/actor-cast-entity-queue.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXY.
 */
static void flush_pending_spell_entity_transfers_synchronously(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t value = RAM8(0x821A);
    RAM8(0x821C) = value;
    r->c = (uint16_t)(sp0 - 3) >= 6;
    r->z = value == 0;
    r->n = value & 0x80;
    r->v = (((uint16_t)(sp0 - 3) ^ 6) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 9);
    r->sp -= 9;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2A71, 0xC12A80); GUARD_JSR(c, sp_call, 0x2A71); } /* drain_spell_entity_transfer_queue_to_ppu */
    r->sp += 9;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 9;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2A74, 0xC12B80); GUARD_JSR(c, sp_call, 0x2A74); } /* retire_completed_spell_entity_transfers */
    r->sp += 9;
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)((uint16_t)(sp0 - 9) + 6);
    r->mf = value2 & 0x20;
    r->xf = value2 & 0x10;
    r->dp = (value4 << 8) | value3;
    r->i = value2 & 0x04;
    r->d = value2 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12A5C, SOM_RTS, "gen", flush_pending_spell_entity_transfers_synchronously, 0, L_B | L_X | L_Y, 9, 1, 0, 36, 21)
