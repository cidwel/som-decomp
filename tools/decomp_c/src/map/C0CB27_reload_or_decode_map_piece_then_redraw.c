#include "som_c.h"
/* SOM_POLL_HOOK */

/* C0CB27 reload_or_decode_map_piece_then_redraw   [class B, 101 bytes, 55 instructions]
 * Source: src/rom/reload_or_decode_map_piece_then_redraw.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: nothing.
 */
static void reload_or_decode_map_piece_then_redraw(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    uint64_t loop_guard = 0;
    const uint16_t a = r->a;
    const bool carry = r->c;
    bool m_flag;
    bool x_flag;
    uint8_t a_hi1;
    bool carry1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (!carry) {
        RAM8(0x0000 + sp0) = 0;
        RAM8(0x0000 + sp0 - 1) = 0x7F;
        r->a = (a >> 8 << 8) | 0x7F;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->db = 0x7F;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCB3A, 0xC0CBC2); GUARD_JSR(c, sp_call, 0xCB3A); } /* clear_map_piece_work_cache */
        r->sp += 1;
        RAM16_SET(0x0016, 0);
        r->mf = 0;
        r->xf = 1;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCB41, 0xC0CC72); GUARD_JSR(c, sp_call, 0xCB41); } /* external */
        r->sp += 1;
        uint16_t dp_ret = r->dp;
        bool m_ret = r->mf;
        bool x_ret2 = r->xf;
        uint16_t a_all2 = r->a;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        uint8_t value = RAM8(0x0000 + sp0);
        m_flag = m_ret;
        x_flag = x_ret2;
        a_hi1 = a_all2 >> 8;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
        data_bank = value;
        direct_page = dp_ret;
    } else {
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCB2D, 0xC0CB90); GUARD_JSR(c, sp_call, 0xCB2D); } /* load_map_piece_list */
        r->mf = 1;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCB30, 0xC0D037); GUARD_JSR(c, sp_call, 0xCB30); } /* allocate_map_trigger_tiles */
        uint8_t db_ret3 = r->db;
        uint16_t a_all4 = r->a;
        bool carry_ret3 = r->c;
        bool overflow_ret3 = r->v;
        m_flag = 1;
        x_flag = 1;
        a_hi1 = a_all4 >> 8;
        carry1 = carry_ret3;
        overflow1 = overflow_ret3;
        data_bank = db_ret3;
        direct_page = 0;
    }
    uint16_t value2 = BUS16_RDP(c, (uint16_t)(direct_page + 0xAA));
    RAM8(0x0000 + sp0) = value2 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value2;
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(direct_page + 0xB2));
    RAM8(0x0000 + sp0 - 2) = value3 >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)value3;
    uint16_t value4 = BUS16_RDP(c, (uint16_t)(direct_page + 0xAE));
    RAM8(0x0000 + sp0 - 4) = value4 >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)value4;
    uint16_t value5 = BUS16_RDP(c, (uint16_t)(direct_page + 0xB6));
    RAM8(0x0000 + sp0 - 6) = value5 >> 8;
    RAM8(0x0000 + sp0 - 7) = (uint8_t)value5;
    uint8_t a_hi2 = value5 >> 8;
    uint8_t x1 = 0x10;
    bool carry2 = carry1;
    bool overflow2 = overflow1;
    uint8_t data_bank2 = data_bank;
    for (;;) {
        LOOP_GUARD(loop_guard);
        RAM8(0x0000 + sp0 - 8) = x1;
        uint8_t value6 = BUS8_RDP(c, (uint16_t)(direct_page + 0xB9));
        uint8_t x2;
        if (value6 == 0) {
            x2 = 2;
        } else {
            x2 = 0x0A;
        }
        BUS8_SET(c, (uint16_t)(direct_page + 0x2E), x2);
        BUS8_SET(c, (uint16_t)(direct_page + 0x2F), 0);
        r->a = (a_hi2 << 8) | (uint8_t)a;
        r->x = 0;
        r->y = value6;
        r->c = carry2;
        r->z = 1;
        r->n = 0;
        r->v = overflow2;
        r->mf = 0;
        r->xf = 1;
        r->db = data_bank2;
        r->dp = direct_page;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCB66, 0xC0C7C3); GUARD_JSR(c, sp_call, 0xCB66); } /* prepare_pending_map_rows */
        r->sp += 9;
        uint8_t db_ret4 = r->db;
        uint16_t a_all5 = r->a;
        uint16_t x_ret7 = r->x;
        uint16_t y_ret5 = r->y;
        bool carry_ret4 = r->c;
        bool overflow_ret4 = r->v;
        uint8_t value7 = BUS8_RDP(c, (uint16_t)(direct_page + 0xEC));
        BUS8_SET(c, (uint16_t)(direct_page + 0xEC), value7 | 2);
        bool overflow3 = overflow_ret4;
        for (;;) {
            LOOP_GUARD(loop_guard);
            uint8_t value8 = BUS8_RDP(c, (uint16_t)(direct_page + 0xEC));
            overflow3 = value8 & 0x40;
            if (!((value8 & 2) != 0)) break;
        }
        r->a = (a_all5 >> 8 << 8) | 2;
        r->x = x_ret7;
        r->y = y_ret5;
        r->c = carry_ret4;
        r->v = overflow3;
        r->mf = 1;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCB73, 0xC0C692); GUARD_JSR(c, sp_call, 0xCB73); } /* upload_pending_map_tile_rows_and_columns */
        r->sp += 9;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCB76, 0xC0CAC6); GUARD_JSR(c, sp_call, 0xCB76); } /* advance_map_tile_row_coordinates */
        r->sp += 9;
        bool m_ret2 = r->mf;
        uint16_t a_all7 = r->a;
        bool carry_ret5 = r->c;
        bool overflow_ret6 = r->v;
        uint8_t value9 = RAM8(0x0000 + sp0 - 8);
        if (m_ret2 != 0) { c->fail = 3; return; }
        a_hi2 = a_all7 >> 8;
        x1 = (uint8_t)(value9 - 1);
        carry2 = carry_ret5;
        overflow2 = overflow_ret6;
        data_bank2 = db_ret4;
        if (!(x1 != 0)) break;
    }
    BUS16_SET(c, (uint16_t)(direct_page + 0xB6), (RAM8(0x0000 + sp0 - 6) << 8) | RAM8(0x0000 + sp0 - 7));
    BUS16_SET(c, (uint16_t)(direct_page + 0xAE), (RAM8(0x0000 + sp0 - 4) << 8) | RAM8(0x0000 + sp0 - 5));
    BUS16_SET(c, (uint16_t)(direct_page + 0xB2), (RAM8(0x0000 + sp0 - 2) << 8) | RAM8(0x0000 + sp0 - 3));
    BUS16_SET(c, (uint16_t)(direct_page + 0xAA), (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1));
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank2;
    r->dp = direct_page;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0CB27, SOM_RTS, "gen", reload_or_decode_map_piece_then_redraw, 0, 0, 9, 0, 0, 101, 55)
