#include "som_c.h"

/* 7ED20D fade_parent_display_in   [class B, 49 bytes, 25 instructions]
 * Source: src/boot/fade_parent_display_in.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYV.
 */
static void fade_parent_display_in(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t a1 = a;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = 0x0300;
    for (;;) {
        r->a = (a_hi1 << 8) | a1;
        r->x = 4;
        r->y = y1;
        r->c = carry1;
        r->z = 0;
        r->n = 0;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD218, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD218); } /* dispatch_parent_messages */
        r->sp += 3;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        bool x_flag2;
        uint8_t a3;
        uint8_t a_hi3;
        uint16_t x2;
        uint16_t y3;
        uint8_t data_bank3;
        uint16_t direct_page3;
        if ((uint8_t)a_all == 0) {
            x_flag2 = x_ret;
            a3 = (uint8_t)a_all;
            a_hi3 = a_all >> 8;
            x2 = x_ret2;
            y3 = y_ret;
            data_bank3 = db_ret;
            direct_page3 = dp_ret;
        } else {
            uint8_t value = BUS8_RDP(c, (db_ret << 0x10) + 0x0314);
            if (value != 0) {
                if (x_ret != 0) { c->fail = 3; return; }
                a1 = value;
                a_hi1 = a_all >> 8;
                x1 = x_ret2;
                y1 = y_ret;
                carry1 = (uint8_t)a_all >= 0;
                overflow1 = overflow_ret;
                data_bank = db_ret;
                direct_page = dp_ret;
                continue;
            }
            r->a = (a_all >> 8 << 8) | 0;
            r->c = (uint8_t)a_all >= 0;
            r->z = 1;
            r->n = 0;
            r->xf = 0;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD226, 0x7EC030); GUARD_JSR(c, sp_call, 0xD226); } /* allocate_ppu_register_entry */
            r->sp += 3;
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret3 = r->xf;
            uint16_t a_all2 = r->a;
            uint16_t x_ret4 = r->x;
            uint16_t y_ret2 = r->y;
            uint8_t value2 = BUS8_RDP(c, (db_ret2 << 0x10) + 2 + x_ret4);
            bool x_flag;
            uint8_t a2;
            uint8_t a_hi2;
            uint16_t y2;
            uint8_t data_bank2;
            uint16_t direct_page2;
            if (value2 >= 0x0F) {
                x_flag = x_ret3;
                a2 = value2;
                a_hi2 = a_all2 >> 8;
                y2 = y_ret2;
                data_bank2 = db_ret2;
                direct_page2 = dp_ret2;
            } else {
                BUS8_SET(c, (db_ret2 << 0x10) + 2 + x_ret4, (uint8_t)(value2 + 1));
                RAM8(0x0000 + sp0 - 3) = (uint8_t)(value2 + 1);
                r->a = (a_all2 >> 8 << 8) | (uint8_t)(value2 + 1);
                r->c = value2 >= 0x0F;
                r->z = (uint8_t)(value2 + 1) == 0;
                r->n = (uint8_t)(value2 + 1) & 0x80;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSR(c, 0xD235, 0x7EC097); GUARD_JSR(c, sp_call, 0xD235); } /* append_oneshot_ppu_entry */
                r->sp += 4;
                uint16_t dp_ret3 = r->dp;
                uint8_t db_ret3 = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                bool x_ret5 = r->xf;
                uint16_t a_all3 = r->a;
                uint16_t y_ret3 = r->y;
                bool overflow_ret3 = r->v;
                uint8_t value3 = RAM8(0x0000 + sp0 - 3);
                if (value3 < 0x0F) {
                    if (x_ret5 != 0) { c->fail = 3; return; }
                    a1 = value3;
                    a_hi1 = a_all3 >> 8;
                    x1 = x_ret4;
                    y1 = y_ret3;
                    carry1 = value3 >= 0x0F;
                    overflow1 = overflow_ret3;
                    data_bank = db_ret3;
                    direct_page = dp_ret3;
                    continue;
                }
                x_flag = 0;
                a2 = value3;
                a_hi2 = a_all3 >> 8;
                y2 = y_ret3;
                data_bank2 = db_ret3;
                direct_page2 = dp_ret3;
            }
            x_flag2 = x_flag;
            a3 = a2;
            a_hi3 = a_hi2;
            x2 = x_ret4;
            y3 = y2;
            data_bank3 = data_bank2;
            direct_page3 = direct_page2;
        }
        a1 = a3;
        a_hi1 = a_hi3;
        x1 = x2;
        y1 = y3;
        data_bank = data_bank3;
        direct_page = direct_page3;
        break;
    }
    uint8_t value4 = RAM8(0x0000 + sp0 - 2);
    uint8_t value5 = RAM8(0x0000 + sp0 - 1);
    uint8_t value6 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->v = value4 & 0x40;
    r->mf = value4 & 0x20;
    r->xf = value4 & 0x10;
    r->db = data_bank;
    r->dp = (value6 << 8) | value5;
    r->i = value4 & 0x04;
    r->d = value4 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ED20D, SOM_RTS, "gen", fade_parent_display_in, 0, L_A | L_B | L_X | L_Y | L_V, 4, 1, 0, 49, 25)
