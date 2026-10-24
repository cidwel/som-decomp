#include "som_c.h"

/* C02227 render_native_menu_heading_until_text_command   [class B, 108 bytes, 46 instructions]
 * Source: src/rom/render_native_menu_heading_until_text_command.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXY.
 */
static void render_native_menu_heading_until_text_command(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0xA181) = 0;
    RAM8(0x1D03) = 0xC7;
    RAM8(0x0000 + sp0) = 0x7E;
    RAM8(0x0000 + sp0 - 1) = 0xC7;
    RAM16_SET(0xA217, 0x50);
    uint16_t value = RAM16(0xA20D);
    uint16_t value2 = BUS16(c, 0xC70000 + value);
    RAM16_SET(0x1D01, value2);
    RAM8(0xA1C5) = 0;
    RAM8(0xA212) &= 0xFE;
    uint8_t a_hi1 = value2 >> 8;
    uint16_t x1 = x;
    uint16_t y1 = value;
    bool carry1 = carry;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = 0;
    for (;;) {
        RAM8(0x1D00) = 0;
        r->a = (a_hi1 << 8) | 0;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = 1;
        r->n = 0;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        { const uint16_t sp_call = r->sp; JSR(c, 0x225B, 0xC02354); GUARD_JSR(c, sp_call, 0x225B); } /* decode_native_menu_font_stream_and_expand_double_rows */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t y_ret = r->y;
        uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0xA217);
        RAM8(0x0000 + sp0) = value4 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)value4;
        BUS16_SET(c, (db_ret << 0x10) + 0xA18C, (uint16_t)((uint16_t)(value4 << 3) + 0x6000));
        uint16_t value5 = BUS16_RDP(c, (db_ret << 0x10) + 0xA1CE);
        BUS16_SET(c, (db_ret << 0x10) + 0xA173, value5 & 0x7F);
        uint8_t value6 = RAM8(0x0000 + sp0 - 1);
        uint8_t value7 = RAM8(0x0000 + sp0);
        uint16_t value8 = BUS16_RDP(c, (db_ret << 0x10) + 0xA173);
        uint16_t value9 = BUS16_RDP(c, (db_ret << 0x10) + 0xA173);
        BUS16_SET(c, (db_ret << 0x10) + 0xA217, (uint16_t)((uint16_t)(((value7 << 8) | value6) + value8) + value9 + (((value7 << 8) | value6) + value8 > 0xFFFF)));
        BUS16_SET(c, (db_ret << 0x10) + 0xA191, 0x0400);
        r->a = (uint16_t)((uint16_t)(((value7 << 8) | value6) + value8) + value9 + (((value7 << 8) | value6) + value8 > 0xFFFF));
        r->x = 0x0400;
        r->c = (uint16_t)(((value7 << 8) | value6) + value8) + value9 + (((value7 << 8) | value6) + value8 > 0xFFFF) > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = (((uint16_t)(((value7 << 8) | value6) + value8) ^ (uint16_t)((uint16_t)(((value7 << 8) | value6) + value8) + value9 + (((value7 << 8) | value6) + value8 > 0xFFFF))) & (value9 ^ (uint16_t)((uint16_t)(((value7 << 8) | value6) + value8) + value9 + (((value7 << 8) | value6) + value8 > 0xFFFF))) & 0x8000) != 0;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x228A, 0xC023BA); GUARD_JSR(c, sp_call, 0x228A); } /* upload_native_menu_assembled_text_tiles */
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret2 = r->xf;
        uint16_t a_all2 = r->a;
        uint8_t value10 = BUS8_RDP(c, (db_ret << 0x10) + 0xA212);
        if (x_ret2 != 0) { c->fail = 3; return; }
        a_hi1 = a_all2 >> 8;
        x1 = 0x0400;
        y1 = y_ret;
        carry1 = (uint16_t)(((value7 << 8) | value6) + value8) + value9 + (((value7 << 8) | value6) + value8 > 0xFFFF) > 0xFFFF;
        overflow1 = (((uint16_t)(((value7 << 8) | value6) + value8) ^ (uint16_t)((uint16_t)(((value7 << 8) | value6) + value8) + value9 + (((value7 << 8) | value6) + value8 > 0xFFFF))) & (value9 ^ (uint16_t)((uint16_t)(((value7 << 8) | value6) + value8) + value9 + (((value7 << 8) | value6) + value8 > 0xFFFF))) & 0x8000) != 0;
        data_bank = db_ret;
        direct_page = dp_ret;
        if (!((value10 & 1) == 0)) break;
    }
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->y = y1;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02227, SOM_RTS, "gen", render_native_menu_heading_until_text_command, 0, L_B | L_X | L_Y, 2, 1, 0, 108, 46)
