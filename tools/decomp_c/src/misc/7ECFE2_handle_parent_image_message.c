#include "som_c.h"

/* 7ECFE2 handle_parent_image_message   [class B, 65 bytes, 34 instructions]
 * Source: src/boot/handle_parent_image_message.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$02EE.  Callers read: ABYV.
 */
static void handle_parent_image_message(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x02EE) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xEE;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    uint8_t value = BUS8(c, 0x7F0003 + x);
    RAM8(0x0001 + (uint16_t)(sp0 - 5)) = value;
    uint8_t value2 = BUS8(c, 0x7F0004 + x);
    RAM8(0x0002 + (uint16_t)(sp0 - 5)) = value2;
    r->a = ((uint16_t)(sp0 - 5) >> 8 << 8) | value2;
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCFF7, 0x7EB1DD); GUARD_JSR(c, sp_call, 0xCFF7); } /* release_eight_byte_record */
    r->sp += 5;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
    bool x_flag3;
    uint8_t a3;
    uint8_t a_hi3;
    uint16_t y3;
    uint8_t data_bank3;
    uint16_t direct_page3;
    if (value3 == 1) {
        x_flag3 = x_ret;
        a3 = value3;
        a_hi3 = a_all >> 8;
        y3 = y;
        data_bank3 = db_ret;
        direct_page3 = dp_ret;
    } else {
        bool x_flag2;
        uint8_t a2;
        uint8_t a_hi2;
        uint16_t y2;
        uint8_t data_bank2;
        uint16_t direct_page2;
        if (value3 == 2) {
            x_flag2 = x_ret;
            a2 = value3;
            a_hi2 = a_all >> 8;
            y2 = y;
            data_bank2 = db_ret;
            direct_page2 = dp_ret;
        } else {
            bool x_flag;
            uint8_t a1;
            uint8_t a_hi1;
            uint16_t y1;
            uint8_t data_bank;
            uint16_t direct_page;
            if (value3 == 4) {
                x_flag = x_ret;
                a1 = value3;
                a_hi1 = a_all >> 8;
                y1 = y;
                data_bank = db_ret;
                direct_page = dp_ret;
            } else {
                r->a = (a_all >> 8 << 8) | value3;
                r->c = value3 >= 4;
                r->z = value3 == 4;
                r->n = (uint8_t)(value3 - 4) & 0x80;
                r->sp -= 5;
                { const uint16_t sp_call = r->sp; JSR(c, 0xD008, 0x7EB1A9); GUARD_JSR(c, sp_call, 0xD008); } /* allocate_eight_byte_record */
                r->sp += 5;
                uint16_t dp_ret2 = r->dp;
                uint8_t db_ret2 = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                uint16_t a_all2 = r->a;
                uint16_t x_ret3 = r->x;
                uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 2));
                if (value4 == 4) {
                    BUS8_SET(c, (db_ret2 << 0x10) + 3 + x_ret3, 1);
                }
                uint8_t value5 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x0311);
                r->a = (a_all2 >> 8 << 8) | value5;
                r->c = value4 >= 4;
                r->z = value5 == 0;
                r->n = value5 & 0x80;
                r->sp -= 5;
                { const uint16_t sp_call = r->sp; JSR(c, 0xD019, 0x7EB258); GUARD_JSR(c, sp_call, 0xD019); } /* append_pending_record */
                r->sp += 5;
                uint16_t dp_ret3 = r->dp;
                uint8_t db_ret3 = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                bool x_ret4 = r->xf;
                uint16_t a_all3 = r->a;
                uint16_t y_ret = r->y;
                x_flag = x_ret4;
                a1 = 0;
                a_hi1 = a_all3 >> 8;
                y1 = y_ret;
                data_bank = db_ret3;
                direct_page = dp_ret3;
            }
            x_flag2 = x_flag;
            a2 = a1;
            a_hi2 = a_hi1;
            y2 = y1;
            data_bank2 = data_bank;
            direct_page2 = direct_page;
        }
        x_flag3 = x_flag2;
        a3 = a2;
        a_hi3 = a_hi2;
        y3 = y2;
        data_bank3 = data_bank2;
        direct_page3 = direct_page2;
    }
    RAM8(0x0000 + sp0 - 3) = a3;
    uint8_t value7 = RAM8(0x0000 + sp0 - 3);
    uint8_t value8 = RAM8(0x0000 + sp0 - 2);
    uint8_t value9 = RAM8(0x0000 + sp0 - 1);
    uint8_t value10 = RAM8(0x0000 + sp0);
    r->a = (a_hi3 << 8) | value7;
    r->y = y3;
    r->v = value8 & 0x40;
    r->mf = value8 & 0x20;
    r->xf = value8 & 0x10;
    r->db = data_bank3;
    r->dp = (value10 << 8) | value9;
    r->i = value8 & 0x04;
    r->d = value8 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ECFE2, SOM_RTS, "gen", handle_parent_image_message, 0, L_A | L_B | L_Y | L_V, 5, 1, 0, 65, 34)
