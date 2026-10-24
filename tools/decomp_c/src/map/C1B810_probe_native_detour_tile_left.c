#include "som_c.h"

/* C1B84B test_native_partner_detour_tile_attributes: carry set when the tile blocks the detour.  Entered with 16-bit A. */
static void test_native_partner_detour_tile_attributes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t value;
    uint16_t word;
    uint32_t tile_ptr = dp_rd16(c, 0x0A) | ((uint32_t)dp_rd8(c, 0x0C) << 16);
    uint32_t attr_ptr = dp_rd16(c, 0x0D) | ((uint32_t)dp_rd8(c, 0x0F) << 16);
    BUS16_PTR(c, (tile_ptr + r->y) & 0xFFFFFF, tile_ptr >> 16, word);
    a_lda(r, word);
    a_and(r, 0x00FF);
    i_asla(r);
    i_asla(r);
    i_tay(r);
    i_sep(r, 0x20);
    BUS8_PTR(c, (attr_ptr + r->y) & 0xFFFFFF, attr_ptr >> 16, value);
    a_lda(r, value);
    a_and(r, 0x07);
    if (!r->z) {
        a_cmp(r, 0x04);
        if (!r->c) {
            a_cmp(r, 0x03);
            if (r->z) { r->c = 1; RETURN_RTS(c); }
            a_eor(r, dp_rd8(c, 0x04));
            a_cmp(r, 0x03);
            if (r->z) { r->c = 1; RETURN_RTS(c); }
        }
    }
    i_iny(r);
    i_iny(r);
    BUS8_PTR(c, (attr_ptr + r->y) & 0xFFFFFF, attr_ptr >> 16, value);
    a_lda(r, value);
    a_and(r, 0xF0);
    a_cmp(r, 0x10);
    r->c = r->z;
    RETURN_RTS(c);
}

/* C1B810 probe_native_detour_tile_left   [class C, 151 bytes, 84 instructions]
 * Source: src/rom/probe_native_detour_tile_left.s
 * Documented in docs/actor-party-obstacle-detour.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void probe_native_detour_tile_left(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    i_sep(r, 0x20);
    a_lda(r, dp_rd8(c, 0x08));
    a_and(r, 0x7F);
    i_deca(r);
    if (r->n) {
        r->c = 0;
        a_adc(r, dp_rd8(c, 0x9C));
    }
    a_bit(r, dp_rd8(c, 0x08));
    if (r->n) a_ora(r, 0x80);
    dp_wr8(c, 0x08, r->a);
    a_and(r, 0x7F);
    a_bit(r, dp_rd8(c, 0x02));
    if (r->n) a_ora(r, 0x80);
    dp_wr8(c, 0x02, r->a);
    i_rep(r, 0x20);
    a_ldy(r, dp_rd16(c, 0x02));
    { const uint16_t sp_call = r->sp; JSR_LOCAL(c, 0xB843, test_native_partner_detour_tile_attributes); GUARD_JSR(c, sp_call, 0xB843); }
    if (r->c) RETURN_RTS(c);
    i_rep(r, 0x20);
    a_ldy(r, dp_rd16(c, 0x08));
    test_native_partner_detour_tile_attributes(c);
}
SOM_REGISTER(0xC1B810, SOM_RTS, "hand", probe_native_detour_tile_left, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 281, 84)
