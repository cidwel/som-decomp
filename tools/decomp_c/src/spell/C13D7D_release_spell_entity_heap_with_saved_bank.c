#include "som_c.h"

/* C13D7D release_spell_entity_heap_with_saved_bank   [class A, 18 bytes, 13 instructions]
 * Source: src/rom/release_spell_entity_heap_with_saved_bank.s
 * Documented in docs/actor-cast-entity-memory.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: BYCZNV.
 */
static void release_spell_entity_heap_with_saved_bank(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t m_entry = r->mf;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = (((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3D8A, 0xC13CB8); GUARD_JSR(c, sp_call, 0x3D8A); } /* release_spell_entity_heap_units */
    r->sp += 4;
    uint8_t value = RAM8(0x0000 + sp0 - 3);
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->c = value2 & 0x01;
    r->z = ((value4 << 8) | value3) == 0;
    r->n = ((value4 << 8) | value3) & 0x8000;
    r->v = value2 & 0x40;
    r->mf = value2 & 0x20;
    r->xf = value2 & 0x10;
    r->db = value;
    r->dp = (value4 << 8) | value3;
    r->i = value2 & 0x04;
    r->d = value2 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC13D7D, SOM_RTS, "gen", release_spell_entity_heap_with_saved_bank, 0, L_B | L_Y | L_C | L_Z | L_N | L_V, 5, -1, 0, 18, 13)
