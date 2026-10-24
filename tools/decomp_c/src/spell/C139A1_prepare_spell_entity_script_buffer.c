#include "som_c.h"

/* C139A1 prepare_spell_entity_script_buffer   [class A, 25 bytes, 12 instructions]
 * Source: src/rom/prepare_spell_entity_script_buffer.s
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: BYCV.
 */
static void prepare_spell_entity_script_buffer(SomCtx *c)
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
    r->x = 0x0380;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x39AA, 0xC13D29); GUARD_JSR(c, sp_call, 0x39AA); } /* allocate_spell_entity_heap_bytes */
    r->sp += 3;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t x_ret = r->x;
    BUS16_SET(c, (db_ret << 0x10) + 0x8234, x_ret);
    r->a = 6;
    r->y = 0xFC6A;
    r->z = 0;
    r->n = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x39B6, 0xC1302E); GUARD_JSR(c, sp_call, 0x39B6); } /* build_spell_entity_script_transfers */
    r->sp += 3;
    uint8_t value = RAM8(0x0000 + sp0 - 2);
    uint8_t value2 = RAM8(0x0000 + sp0 - 1);
    uint8_t value3 = RAM8(0x0000 + sp0);
    r->c = value & 0x01;
    r->v = value & 0x40;
    r->mf = value & 0x20;
    r->xf = value & 0x10;
    r->dp = (value3 << 8) | value2;
    r->i = value & 0x04;
    r->d = value & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC139A1, SOM_RTS, "gen", prepare_spell_entity_script_buffer, 0, L_B | L_Y | L_C | L_V, 3, -1, 0, 25, 12)
