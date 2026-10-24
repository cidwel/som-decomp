#include "som_c.h"

/* C0CAFF reload_map_pieces_preserving_low_scratch_and_redraw   [class B, 40 bytes, 22 instructions]
 * Source: src/rom/reload_map_pieces_preserving_low_scratch_and_redraw.s
 * Entry: M=any X=any DB=$7E D=any.  Callers read: nothing.
 */
static void reload_map_pieces_preserving_low_scratch_and_redraw(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, -1)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0) = ((overflow << 6) | (d_entry << 3)) | (i_entry << 2) | 2 | carry;
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = 0x0E;
    for (;;) {
        uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x20 + x1));
        BUS16_SET(c, 0x0005F0 + x1, value);
        a_hi1 = value >> 8;
        x1 = (uint16_t)(x1 - 2);
        if (!(!(x1 & 0x8000))) break;
    }
    uint8_t value2 = RAM8(0x0000 + sp0);
    r->x = x1;
    r->y = y;
    r->c = value2 & 0x01;
    r->z = value2 & 0x02;
    r->n = value2 & 0x80;
    r->v = value2 & 0x40;
    r->mf = value2 & 0x20;
    r->xf = value2 & 0x10;
    r->db = 0;
    r->i = value2 & 0x04;
    r->d = value2 & 0x08;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCB17, 0xC0CB27); GUARD_JSR(c, sp_call, 0xCB17); } /* reload_or_decode_map_piece_then_redraw */
    uint8_t db_ret = r->db;
    uint16_t a_all = r->a;
    uint8_t a_hi2 = a_all >> 8;
    uint16_t x2 = 0x0E;
    for (;;) {
        uint16_t value3 = BUS16_RDP(c, (db_ret << 0x10) + 0x05F0 + x2);
        BUS16_SET(c, (uint16_t)(dp + 0x20 + x2), value3);
        a_hi2 = value3 >> 8;
        x2 = (uint16_t)(x2 - 2);
        if (!(!(x2 & 0x8000))) break;
    }
    r->mf = 0;
    r->xf = 0;
    r->i = value2 & 0x04;
    r->d = value2 & 0x08;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0CAFF, SOM_RTL, "gen", reload_map_pieces_preserving_low_scratch_and_redraw, 0, 0, 1, -1, -1, 40, 22)
