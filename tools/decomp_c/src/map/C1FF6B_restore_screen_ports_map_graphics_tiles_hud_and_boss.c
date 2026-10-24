#include "som_c.h"

/* C1FF6B restore_screen_ports_map_graphics_tiles_hud_and_boss   [class D, 149 bytes, 56 instructions]
 * Source: src/rom/restore_screen_ports_map_graphics_tiles_hud_and_boss.s
 * Entry: M=8 bit X=any DB=$00 D=$0000.  Callers read: XYCV.
 */
static void restore_screen_ports_map_graphics_tiles_hud_and_boss(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    BUS8_SET(c, 0x00420C, 0);
    RAM8(0x002C) = 0;
    BUS8_SET(c, 0x002106, RAM8(0x0020));
    BUS8_SET(c, 0x002124, 0);
    BUS8_SET(c, 0x002125, 0);
    BUS8_SET(c, 0x00212A, 0);
    BUS8_SET(c, 0x00212B, 0);
    BUS8_SET(c, 0x00212C, RAM8(0x0021));
    BUS8_SET(c, 0x00212D, RAM8(0x0022));
    BUS8_SET(c, 0x00212E, 0);
    BUS8_SET(c, 0x00212F, 0);
    BUS8_SET(c, 0x002130, 2);
    BUS8_SET(c, 0x002131, RAM8(0x0023));
    BUS8_SET(c, 0x002132, 0);
    BUS8_SET(c, 0x002126, 0);
    BUS8_SET(c, 0x002128, 0);
    BUS8_SET(c, 0x002127, 0xFF);
    BUS8_SET(c, 0x002129, 0xFF);
    BUS8_SET(c, 0x002101, RAM8(0x0091));
    RAM8(0x00E3) &= 0xF0;
    BUS8_SET(c, 0x00210D, RAM8(0x00B0));
    BUS8_SET(c, 0x00210D, 0);
    BUS8_SET(c, 0x00210E, RAM8(0x00B2));
    BUS8_SET(c, 0x00210E, 0);
    BUS8_SET(c, 0x004207, 0xB8);
    BUS8_SET(c, 0x004208, 0);
    BUS8_SET(c, 0x004209, 0xC4);
    BUS8_SET(c, 0x00420A, 0);
    RAM8(0x00E8) = 0;
    r->a = (a_hi << 8) | 0xC4;
    r->z = 0;
    r->n = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xFFDB, 0xC1FD52); GUARD_JSR(c, sp_call, 0xFFDB); } /* configure_map_backgrounds */
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xFFDF, 0x00C45E); GUARD_JSL(c, sp_call, 0xFFDF); } /* reload_map_header_graphics */
    uint8_t db_ret = r->db;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xFFE3, 0x00C9E6); GUARD_JSL(c, sp_call, 0xFFE3); } /* fill_map_tile_rows_long */
    { const uint16_t sp_call = r->sp; JSL(c, 0xFFE7, 0x01E0D7); GUARD_JSL(c, sp_call, 0xFFE7); } /* initialize_party_hud_long */
    bool x_ret5 = r->xf;
    uint16_t a_all4 = r->a;
    uint16_t x_ret6 = r->x;
    uint16_t y_ret4 = r->y;
    bool carry_ret4 = r->c;
    uint8_t value9 = RAM8(0x005C);
    bool m_flag;
    bool x_flag;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (!(value9 & 0x80)) {
        m_flag = 1;
        x_flag = x_ret5;
        a_hi1 = a_all4 >> 8;
        x1 = x_ret6;
        y1 = y_ret4;
        carry1 = carry_ret4;
        overflow1 = value9 & 0x40;
        data_bank = db_ret;
        direct_page = 0;
    } else {
        r->z = ((uint8_t)a_all4 & value9) == 0;
        r->n = value9 & 0x80;
        r->v = value9 & 0x40;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xFFF3, 0xC20012); GUARD_JSL(c, sp_call, 0xFFF3); } /* restore_boss_screen_resources_long_entry */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret3 = r->mf;
        bool x_ret7 = r->xf;
        uint16_t a_all5 = r->a;
        uint16_t x_ret8 = r->x;
        uint16_t y_ret5 = r->y;
        bool carry_ret5 = r->c;
        bool overflow_ret4 = r->v;
        m_flag = m_ret3;
        x_flag = x_ret7;
        a_hi1 = a_all5 >> 8;
        x1 = x_ret8;
        y1 = y_ret5;
        carry1 = carry_ret5;
        overflow1 = overflow_ret4;
        data_bank = db_ret2;
        direct_page = dp_ret;
    }
    uint16_t value10 = BUS16_RDP(c, (uint16_t)(direct_page + 0x27));
    BUS16_SET(c, (data_bank << 0x10) + 0x0600, value10);
    RAM16_SET(0xDE00, value10);
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = direct_page;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1FF6B, SOM_RTS, "gen", restore_screen_ports_map_graphics_tiles_hud_and_boss, 0, L_X | L_Y | L_C | L_V, 1, 1, -1, 149, 56)
