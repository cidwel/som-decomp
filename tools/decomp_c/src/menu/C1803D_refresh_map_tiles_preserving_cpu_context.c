#include "som_c.h"

/* C1803D refresh_map_tiles_preserving_cpu_context   [class A, 21 bytes, 14 instructions]
 * Source: src/rom/refresh_map_tiles_preserving_cpu_context.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: nothing.
 */
static void refresh_map_tiles_preserving_cpu_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 1) = db;
    RAM8(0x0000 + sp0 - 2) = dp >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 4) = 0;
    r->a = 0;
    r->z = 1;
    r->n = 0;
    r->db = 0;
    r->dp = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0x804D, 0x00CB8C); GUARD_JSL(c, sp_call, 0x804D); } /* refresh_map_tile_rows_long */
    r->sp += 4;
    uint8_t value = RAM8(0x0000 + sp0 - 3);
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->mf = value4 & 0x20;
    r->xf = value4 & 0x10;
    r->db = value3;
    r->dp = (value2 << 8) | value;
    r->i = value4 & 0x04;
    r->d = value4 & 0x08;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1803D, SOM_RTL, "gen", refresh_map_tiles_preserving_cpu_context, 0, 0, 5, 1, 0, 21, 14)
