#include "som_c.h"

/* 7ED081 handle_parent_buffer_message   [class B, 45 bytes, 22 instructions]
 * Source: src/boot/handle_parent_buffer_message.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$02EE.  Callers read: ABYCV.
 */
static void handle_parent_buffer_message(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x02EE) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xEE;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t value = BUS8(c, 0x7F0003 + x);
    RAM8(0x0000 + sp0 - 3) = value;
    r->a = (a_hi << 8) | value;
    r->z = value == 0;
    r->n = value & 0x80;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD08D, 0x7EB1DD); GUARD_JSR(c, sp_call, 0xD08D); } /* release_eight_byte_record */
    r->sp += 4;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint8_t value2 = RAM8(0x0000 + sp0 - 3);
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t y1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (value2 == 1) {
        r->a = (a_all >> 8 << 8) | value2;
        r->c = value2 >= 1;
        r->z = value2 == 1;
        r->n = (uint8_t)(value2 - 1) & 0x80;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD09A, 0x7EB1A9); GUARD_JSR(c, sp_call, 0xD09A); } /* allocate_eight_byte_record */
        r->sp += 3;
        uint8_t db_ret2 = r->db;
        uint16_t x_ret3 = r->x;
        uint16_t value3 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x0306);
        BUS16_SET(c, (db_ret2 << 0x10) + 4 + x_ret3, value3);
        uint8_t value4 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x0312);
        r->a = (value3 >> 8 << 8) | value4;
        r->z = value4 == 0;
        r->n = value4 & 0x80;
        r->mf = 1;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD0AA, 0x7EB258); GUARD_JSR(c, sp_call, 0xD0AA); } /* append_pending_record */
        r->sp += 3;
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        bool m_ret2 = r->mf;
        bool x_ret4 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t y_ret = r->y;
        m_flag = m_ret2;
        x_flag = x_ret4;
        a1 = (uint8_t)a_all3;
        a_hi1 = a_all3 >> 8;
        y1 = y_ret;
        data_bank = db_ret3;
        direct_page = dp_ret3;
    } else {
        BUS8_SET(c, (db_ret << 0x10) + 0x0312, 0);
        m_flag = 1;
        x_flag = x_ret;
        a1 = value2;
        a_hi1 = a_all >> 8;
        y1 = y;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    uint8_t value5 = RAM8(0x0000 + sp0 - 2);
    uint8_t value6 = RAM8(0x0000 + sp0 - 1);
    uint8_t value7 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | a1;
    r->y = y1;
    r->c = value5 & 0x01;
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
SOM_REGISTER(0x7ED081, SOM_RTS, "gen", handle_parent_buffer_message, 0, L_A | L_B | L_Y | L_C | L_V, 4, 1, 0, 45, 22)
