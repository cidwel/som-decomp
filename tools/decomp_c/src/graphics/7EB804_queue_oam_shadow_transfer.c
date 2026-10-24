#include "som_c.h"

/* 7EB804 queue_oam_shadow_transfer   [class B, 60 bytes, 30 instructions]
 * Source: src/boot/queue_oam_shadow_transfer.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$4200.  Callers read: ABXYCZNV.
 */
static void queue_oam_shadow_transfer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x4200) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0x42;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    uint16_t value = RAM16(0x102CC);
    bool m_flag2;
    bool x_flag2;
    uint8_t a2;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if (value == 0) {
        m_flag2 = 1;
        x_flag2 = 0;
        a2 = 0x7F;
        a_hi2 = a_hi;
        x2 = value;
        y2 = y;
        data_bank2 = 0x7F;
        direct_page2 = 0x4200;
    } else {
        r->a = 0xFF04;
        r->x = value;
        r->z = 0;
        r->n = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB81B, 0x7E8FC7); GUARD_JSR(c, sp_call, 0xB81B); } /* allocate_transfer_descriptor */
        r->sp += 4;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool m_flag;
        bool x_flag;
        uint8_t a1;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        uint8_t data_bank;
        uint16_t direct_page;
        if (x_ret == 0) {
            m_flag = 1;
            x_flag = 0;
            a1 = (uint8_t)a_all;
            a_hi1 = a_all >> 8;
            x1 = x_ret;
            y1 = y_ret;
            data_bank = db_ret;
            direct_page = dp_ret;
        } else {
            BUS8_SET(c, (db_ret << 0x10) + 4 + x_ret, 0x7F);
            uint16_t value2 = BUS16_RDP(c, (db_ret << 0x10) + 0x02CC);
            BUS16_SET(c, (db_ret << 0x10) + 2 + x_ret, value2);
            BUS16_SET(c, (db_ret << 0x10) + 5 + x_ret, 0x0220);
            BUS16_SET(c, (db_ret << 0x10) + 0x0A + x_ret, 0);
            r->a = 0x0220;
            r->c = x_ret >= 0;
            r->z = 0;
            r->n = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB83B, 0x7E90DA); GUARD_JSR(c, sp_call, 0xB83B); } /* submit_transfer_or_program_hdma */
            r->sp += 4;
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            bool m_ret = r->mf;
            bool x_ret2 = r->xf;
            uint16_t a_all2 = r->a;
            uint16_t x_ret3 = r->x;
            uint16_t y_ret2 = r->y;
            m_flag = m_ret;
            x_flag = x_ret2;
            a1 = (uint8_t)a_all2;
            a_hi1 = a_all2 >> 8;
            x1 = x_ret3;
            y1 = y_ret2;
            data_bank = db_ret2;
            direct_page = dp_ret2;
        }
        m_flag2 = m_flag;
        x_flag2 = x_flag;
        a2 = a1;
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    uint8_t value3 = RAM8(0x0000 + sp0 - 3);
    uint8_t value4 = RAM8(0x0000 + sp0 - 2);
    uint8_t value5 = RAM8(0x0000 + sp0 - 1);
    uint8_t value6 = RAM8(0x0000 + sp0);
    r->a = (a_hi2 << 8) | a2;
    r->x = x2;
    r->y = y2;
    r->c = value4 & 0x01;
    r->z = ((value6 << 8) | value5) == 0;
    r->n = ((value6 << 8) | value5) & 0x8000;
    r->v = value4 & 0x40;
    r->mf = value4 & 0x20;
    r->xf = value4 & 0x10;
    r->db = value3;
    r->dp = (value6 << 8) | value5;
    r->i = value4 & 0x04;
    r->d = value4 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB804, SOM_RTS, "gen", queue_oam_shadow_transfer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 60, 30)
