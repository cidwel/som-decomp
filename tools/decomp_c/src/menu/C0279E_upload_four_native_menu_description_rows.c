#include "som_c.h"

/* C0279E upload_four_native_menu_description_rows   [class D, 66 bytes, 27 instructions]
 * Source: src/rom/upload_four_native_menu_description_rows.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYC.
 */
static void upload_four_native_menu_description_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0xA175) = 4;
    RAM16_SET(0xA173, 0x58C1);
    RAM16_SET(0xA194, 0x9182);
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = 0x9182;
    bool carry1 = carry;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = 0;
    for (;;) {
        uint16_t value = BUS16_RDP(c, (data_bank << 0x10) + 0xA173);
        RAM8(0x0000 + sp0) = value >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)value;
        BUS16_SET(c, 0x002116, value);
        BUS16_SET(c, (data_bank << 0x10) + 0xA191, 0x78);
        r->a = 0x78;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = 0;
        r->n = 0;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x27C3, 0xC025CC); GUARD_JSR(c, sp_call, 0x27C3); } /* select_wram_source_for_native_menu_tile_dma */
        r->sp += 2;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool x_ret = r->xf;
        BUS16_SET(c, (db_ret << 0x10) + 0xA173, (uint16_t)(((RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1)) + 0x20));
        uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0xA194);
        BUS16_SET(c, (db_ret << 0x10) + 0xA194, (uint16_t)(value4 + 0x40));
        uint8_t value5 = BUS8_RDP(c, (db_ret << 0x10) + 0xA175);
        BUS8_SET(c, (db_ret << 0x10) + 0xA175, (uint8_t)(value5 - 1));
        if (x_ret != 0) { c->fail = 3; return; }
        a_hi1 = (uint16_t)(value4 + 0x40) >> 8;
        carry1 = value4 + 0x40 > 0xFFFF;
        overflow1 = ((value4 ^ (uint16_t)(value4 + 0x40)) & ((uint16_t)(value4 + 0x40) ^ 0x40) & 0x8000) != 0;
        data_bank = db_ret;
        direct_page = dp_ret;
        if (!((uint8_t)(value5 - 1) != 0)) break;
    }
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0279E, SOM_RTS, "gen", upload_four_native_menu_description_rows, 0, L_B | L_X | L_Y | L_C, 2, 1, 0, 66, 27)
