#include "som_c.h"

/* 7ED14C ensure_parent_control_task   [class B, 51 bytes, 22 instructions]
 * Source: src/boot/ensure_parent_control_task.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$02EE.  Callers read: BXYCV.
 */
static void ensure_parent_control_task(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x02EE) { c->fail = 3; return; }
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
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xEE;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t value = RAM8(0x10314);
    bool m_flag;
    bool x_flag;
    uint8_t a_hi2;
    uint16_t x1;
    uint16_t y2;
    uint8_t data_bank;
    uint16_t direct_page;
    if (value != 0) {
        m_flag = 1;
        x_flag = 0;
        a_hi2 = a_hi;
        x1 = x;
        y2 = y;
        data_bank = 0x7F;
        direct_page = 0x02EE;
    } else {
        uint8_t value2 = RAM8(0x10316);
        uint8_t a_hi1;
        uint16_t y1;
        bool carry1;
        bool overflow1;
        if (value2 == 0) {
            a_hi1 = a_hi;
            y1 = y;
            carry1 = carry;
            overflow1 = overflow;
        } else {
            RAM8(0x1E00) = 0x80;
            RAM8(0x1E01) = 0x20;
            r->a = (a_hi << 8) | 0x20;
            r->z = 0;
            r->n = 0;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD16B, 0xC30004); GUARD_JSL(c, sp_call, 0xD16B); } /* audio_command_sender_public_jump */
            r->sp += 3;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all = r->a;
            uint16_t y_ret = r->y;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            a_hi1 = a_all >> 8;
            y1 = y_ret;
            carry1 = carry_ret;
            overflow1 = overflow_ret;
        }
        r->a = (a_hi1 << 8) | 0x7E;
        r->x = 0x6492;
        r->y = y1;
        r->c = carry1;
        r->z = 0;
        r->n = 0;
        r->v = overflow1;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD173, 0x7EAB88); GUARD_JSR(c, sp_call, 0xD173); } /* create_and_enqueue_task */
        r->sp += 3;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all2 = r->a;
        uint16_t y_ret2 = r->y;
        BUS8_SET(c, (db_ret << 0x10) + 0x0314, (uint8_t)a_all2);
        r->a = (a_all2 >> 8 << 8) | 5;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD17B, 0x7EA3A5); GUARD_JSR(c, sp_call, 0xD17B); } /* release_controller_routes */
        r->sp += 3;
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret = r->mf;
        bool x_ret4 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t x_ret5 = r->x;
        m_flag = m_ret;
        x_flag = x_ret4;
        a_hi2 = a_all3 >> 8;
        x1 = x_ret5;
        y2 = y_ret2;
        data_bank = db_ret2;
        direct_page = dp_ret2;
    }
    uint8_t value3 = RAM8(0x0000 + sp0 - 2);
    uint8_t value4 = RAM8(0x0000 + sp0 - 1);
    uint8_t value5 = RAM8(0x0000 + sp0);
    r->a = (a_hi2 << 8) | a;
    r->x = x1;
    r->y = y2;
    r->c = value3 & 0x01;
    r->v = value3 & 0x40;
    r->mf = value3 & 0x20;
    r->xf = value3 & 0x10;
    r->db = data_bank;
    r->dp = (value5 << 8) | value4;
    r->i = value3 & 0x04;
    r->d = value3 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ED14C, SOM_RTS, "gen", ensure_parent_control_task, 0, L_B | L_X | L_Y | L_C | L_V, 3, 1, 0, 51, 22)
