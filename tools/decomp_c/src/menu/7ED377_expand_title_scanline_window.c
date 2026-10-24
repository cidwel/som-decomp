#include "som_c.h"

/* 7ED377 expand_title_scanline_window   [class B, 51 bytes, 29 instructions]
 * Source: src/boot/expand_title_scanline_window.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYV.
 */
static void expand_title_scanline_window(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 6) + 0x3 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = x >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)x;
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 6), 0x40);
    uint8_t a1 = (uint8_t)(sp0 - 6);
    uint8_t a_hi1 = (uint16_t)(sp0 - 6) >> 8;
    uint16_t x1 = 0x40;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = (uint16_t)(sp0 - 6);
    for (;;) {
        uint16_t value = BUS16_RDP(c, (uint16_t)(direct_page + 2));
        BUS16_SET(c, (uint16_t)(direct_page + 2), (uint16_t)(value + 1));
        r->a = (a_hi1 << 8) | a1;
        r->x = (uint16_t)(value + 1);
        r->y = 0x70;
        r->c = carry1;
        r->z = 0;
        r->n = 0;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD390, 0x7ECE6B); GUARD_JSR(c, sp_call, 0xD390); } /* build_title_window_scanline_table */
        r->sp += 6;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        uint8_t a2;
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        uint8_t data_bank2;
        uint16_t direct_page2;
        if (x_ret == 0x10) {
            a2 = 1;
            a_hi2 = a_all >> 8;
            x2 = x_ret;
            y2 = y_ret;
            data_bank2 = db_ret;
            direct_page2 = direct_page;
        } else {
            r->a = (a_all >> 8 << 8) | 1;
            r->x = 3;
            r->c = x_ret >= 0x10;
            r->z = 0;
            r->n = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD39D, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD39D); } /* dispatch_parent_messages */
            r->sp += 6;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret2 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret2 = r->xf;
            uint16_t a_all2 = r->a;
            uint16_t x_ret3 = r->x;
            uint16_t y_ret2 = r->y;
            bool overflow_ret2 = r->v;
            if ((uint8_t)a_all2 != 0) {
                if (x_ret2 != 0) { c->fail = 3; return; }
                a1 = (uint8_t)a_all2;
                a_hi1 = a_all2 >> 8;
                x1 = x_ret3;
                y1 = y_ret2;
                carry1 = (uint8_t)a_all2 >= 0;
                overflow1 = overflow_ret2;
                data_bank = db_ret2;
                direct_page = dp_ret;
                continue;
            }
            a2 = (uint8_t)a_all2;
            a_hi2 = a_all2 >> 8;
            x2 = x_ret3;
            y2 = y_ret2;
            data_bank2 = db_ret2;
            direct_page2 = dp_ret;
        }
        a1 = a2;
        a_hi1 = a_hi2;
        x1 = x2;
        y1 = y2;
        data_bank = data_bank2;
        direct_page = direct_page2;
        break;
    }
    RAM8(0x0000 + sp0 - 3) = a1;
    uint8_t value4 = RAM8(0x0000 + sp0 - 3);
    uint8_t value5 = RAM8(0x0000 + sp0 - 2);
    uint8_t value6 = RAM8(0x0000 + sp0 - 1);
    uint8_t value7 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value4;
    r->x = x1;
    r->y = y1;
    r->v = value5 & 0x40;
    r->mf = value5 & 0x20;
    r->xf = value5 & 0x10;
    r->db = data_bank;
    r->dp = (value7 << 8) | value6;
    r->i = value5 & 0x04;
    r->d = value5 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ED377, SOM_RTS, "gen", expand_title_scanline_window, 0, L_A | L_B | L_X | L_Y | L_V, 6, 1, 0, 51, 29)
