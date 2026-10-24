#include "som_c.h"

/* D0CC11 cycle_native_weapon_palette_every_third_menu_frame   [class B, 197 bytes, 88 instructions]
 * Source: src/rom/cycle_native_weapon_palette_every_third_menu_frame.s
 * Documented in docs/event-menu-ring-palette.md
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: nothing.
 */
static void cycle_native_weapon_palette_every_third_menu_frame(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x1837);
    uint8_t a1;
    bool zero1;
    if ((uint8_t)(value + 1) < 3) {
        a1 = (uint8_t)(value + 1);
        zero1 = (uint8_t)(value + 1) == 3;
    } else {
        a1 = 0;
        zero1 = 1;
    }
    RAM8(0x1837) = a1;
    bool m_flag;
    bool x_flag;
    uint8_t data_bank;
    uint16_t direct_page;
    if (!zero1) {
        m_flag = 0;
        x_flag = 0;
        data_bank = 0;
        direct_page = 0;
    } else {
        uint16_t value2 = RAM16(0x1820);
        uint8_t a2;
        uint8_t a_hi1;
        if ((uint16_t)(value2 + 1) < 0x0A) {
            a2 = (uint8_t)(value2 + 1);
            a_hi1 = (uint16_t)(value2 + 1) >> 8;
        } else {
            a2 = 0;
            a_hi1 = 0;
        }
        RAM16_SET(0x1820, (a_hi1 << 8) | a2);
        uint16_t value3 = BUS16(c, 0xD9FEF4 + (uint16_t)(((a_hi1 << 8) | a2) << 1));
        RAM16_SET(0x1810, value3);
        uint8_t a3 = 3;
        uint8_t a_hi2 = 0;
        uint16_t x1 = 0x8100;
        bool overflow1 = overflow;
        for (;;) {
            RAM8(0x0000 + sp0) = a_hi2;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi2 << 8) | a3);
            uint16_t value4 = RAM16(0x1810);
            RAM16_SET(0x0000 + (uint16_t)(x1 + 2), value4);
            RAM16_SET(0x000A + (uint16_t)(x1 + 2), value4);
            RAM16_SET(0x0014 + (uint16_t)(x1 + 2), value4);
            uint8_t value5 = RAM8(0x0000 + sp0 - 1);
            uint8_t value6 = RAM8(0x0000 + sp0);
            uint8_t a3_next = (uint8_t)(((value6 << 8) | value5) - 1);
            uint8_t a_hi2_next = (uint16_t)(((value6 << 8) | value5) - 1) >> 8;
            uint16_t x1_next = (uint16_t)(x1 + 0x20);
            bool overflow1_next = (((uint16_t)(x1 + 2) ^ (uint16_t)(x1 + 0x20)) & ((uint16_t)(x1 + 0x20) ^ 0x1E) & 0x8000) != 0;
            a3 = a3_next;
            a_hi2 = a_hi2_next;
            x1 = x1_next;
            overflow1 = overflow1_next;
            if (!((uint16_t)(((value6 << 8) | value5) - 1) != 0)) break;
        }
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCC60, 0xD0CD18); GUARD_JSR(c, sp_call, 0xCC60); } /* locate_native_menu_icon_palette_page */
        uint16_t a_all = r->a;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        uint8_t a_hi3 = a_all >> 8;
        uint16_t x2 = 0;
        uint16_t y1 = a_all;
        bool carry1 = carry_ret;
        for (;;) {
            uint16_t value7 = RAM16(0x8100 + x2);
            BUS16_SET(c, 0x000000 + y1, value7);
            uint8_t a_hi3_next = value7 >> 8;
            uint16_t x2_next = (uint16_t)(x2 + 2);
            uint16_t y1_next = (uint16_t)(y1 + 2);
            bool carry1_next = (uint16_t)(x2 + 2) >= 0x80;
            a_hi3 = a_hi3_next;
            x2 = x2_next;
            y1 = y1_next;
            carry1 = carry1_next;
            if (!(x2 < 0x80)) break;
        }
        r->a = (a_hi3 << 8) | (uint8_t)a;
        r->x = x2;
        r->y = y1;
        r->c = carry1;
        r->v = overflow_ret;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCC77, 0xD0CDA9); GUARD_JSR(c, sp_call, 0xCC77); } /* request_menu_palette_upload */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        m_flag = m_ret;
        x_flag = x_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    r->mf = m_flag;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = direct_page;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0CC11, SOM_RTS, "gen", cycle_native_weapon_palette_every_third_menu_frame, 0, 0, 2, -1, 0, 197, 88)
