#include "som_c.h"

/* C14190 release_main_spell_entity_heap   [class A, 21 bytes, 14 instructions]
 * Source: src/rom/release_main_spell_entity_heap.s
 * Documented in docs/actor-spell-entity-cleanup.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void release_main_spell_entity_heap(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    uint16_t value = RAM16(0x8424);
    r->a = (a_hi << 8) | 0x7E;
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x41A0, 0xC13D7D); GUARD_JSR(c, sp_call, 0x41A0); } /* release_spell_entity_heap_with_saved_bank */
    r->sp += 4;
    uint8_t value2 = RAM8(0x0000 + sp0 - 3);
    uint8_t value3 = RAM8(0x0000 + sp0 - 2);
    uint8_t value4 = RAM8(0x0000 + sp0 - 1);
    uint8_t value5 = RAM8(0x0000 + sp0);
    r->c = value3 & 0x01;
    r->z = ((value5 << 8) | value4) == 0;
    r->n = ((value5 << 8) | value4) & 0x8000;
    r->v = value3 & 0x40;
    r->mf = value3 & 0x20;
    r->xf = value3 & 0x10;
    r->db = value2;
    r->dp = (value5 << 8) | value4;
    r->i = value3 & 0x04;
    r->d = value3 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC14190, SOM_RTS, "gen", release_main_spell_entity_heap, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 21, 14)
