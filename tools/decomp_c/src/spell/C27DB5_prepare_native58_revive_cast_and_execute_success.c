#include "som_c.h"

/* C27DB5 prepare_native58_revive_cast_and_execute_success   [class B, 50 bytes, 20 instructions]
 * Source: src/rom/prepare_native58_revive_cast_and_execute_success.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0200.  Callers read: YCV.
 */
static void prepare_native58_revive_cast_and_execute_success(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t y_7de6 = 0;
    bool carry_7de6 = 0;
    bool overflow_7de6 = 0;
    uint16_t direct_page_7de6 = 0;
    uint8_t data_bank_7de6 = 0;
    uint16_t y_7de62 = 0;
    bool carry_7de62 = 0;
    bool overflow_7de62 = 0;
    uint16_t direct_page_7de62 = 0;
    uint8_t data_bank_7de62 = 0;
    uint8_t y_7de63 = 0;
    bool carry_7de63 = 0;
    bool overflow_7de63 = 0;
    uint16_t direct_page_7de63 = 0;
    uint8_t data_bank_7de63 = 0;
    uint16_t y_7de64 = 0;
    bool carry_7de64 = 0;
    bool overflow_7de64 = 0;
    uint16_t direct_page_7de64 = 0;
    uint8_t data_bank_7de64 = 0;
    uint16_t value = RAM16(0x0287);
    RAM8(0x0170 + value) = 0x21;
    RAM8(0x0176 + value) = 1;
    RAM8(0x0177 + value) = 0;
    uint8_t value2 = RAM8(0x0295);
    RAM8(0x0178 + value) = value2;
    RAM8(0x0179 + value) = 0;
    RAM8(0x017A + value) = 0;
    r->a = (a_hi << 8) | value2;
    r->x = value;
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7DD6, 0xC0001B); GUARD_JSL(c, sp_call, 0x7DD6); } /* cast_spell_public_jump */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    if ((a_all & 0xFF) != 0) {
        if (x_ret) {
            y_7de6 = (uint8_t)y_ret;
            carry_7de6 = carry_ret;
            overflow_7de6 = overflow_ret;
            direct_page_7de6 = dp_ret;
            data_bank_7de6 = db_ret;
            goto shared_7DE6;
        } else {
            y_7de62 = y_ret;
            carry_7de62 = carry_ret;
            overflow_7de62 = overflow_ret;
            direct_page_7de62 = dp_ret;
            data_bank_7de62 = db_ret;
            goto shared_7DE6_1;
        }
    }
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
    if (x_ret) {
        r->a = value3 & 0x1FFF;
        r->x = (uint8_t)(value3 & 0x1FFF);
        r->y = (uint8_t)y_ret;
        r->z = (uint8_t)(value3 & 0x1FFF) == 0;
        r->n = (uint8_t)(value3 & 0x1FFF) & 0x80;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x7DE5, 0x01800F); GUARD_JSL(c, sp_call, 0x7DE5); } /* cast_actor_request_public_jump */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret = r->mf;
        bool x_ret3 = r->xf;
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        if (m_ret) {
            if (x_ret3) {
                y_7de63 = (uint8_t)y_ret2;
                carry_7de63 = carry_ret2;
                overflow_7de63 = overflow_ret2;
                direct_page_7de63 = dp_ret2;
                data_bank_7de63 = db_ret2;
                goto shared_7DE6_2;
            } else {
                y_7de64 = y_ret2;
                carry_7de64 = carry_ret2;
                overflow_7de64 = overflow_ret2;
                direct_page_7de64 = dp_ret2;
                data_bank_7de64 = db_ret2;
                goto shared_7DE6_3;
            }
        } else {
            if (x_ret3) {
                y_7de6 = (uint8_t)y_ret2;
                carry_7de6 = carry_ret2;
                overflow_7de6 = overflow_ret2;
                direct_page_7de6 = dp_ret2;
                data_bank_7de6 = db_ret2;
                goto shared_7DE6;
            } else {
                y_7de62 = y_ret2;
                carry_7de62 = carry_ret2;
                overflow_7de62 = overflow_ret2;
                direct_page_7de62 = dp_ret2;
                data_bank_7de62 = db_ret2;
                goto shared_7DE6_1;
            }
        }
    } else {
        r->a = value3 & 0x1FFF;
        r->x = value3 & 0x1FFF;
        r->z = (value3 & 0x1FFF) == 0;
        r->n = value3 & 0x1FFF & 0x8000;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x7DE5, 0x01800F); GUARD_JSL(c, sp_call, 0x7DE5); } /* cast_actor_request_public_jump */
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        bool m_ret2 = r->mf;
        bool x_ret5 = r->xf;
        uint16_t y_ret3 = r->y;
        bool carry_ret3 = r->c;
        bool overflow_ret3 = r->v;
        if (m_ret2) {
            if (x_ret5) {
                y_7de63 = (uint8_t)y_ret3;
                carry_7de63 = carry_ret3;
                overflow_7de63 = overflow_ret3;
                direct_page_7de63 = dp_ret3;
                data_bank_7de63 = db_ret3;
                goto shared_7DE6_2;
            } else {
                y_7de64 = y_ret3;
                carry_7de64 = carry_ret3;
                overflow_7de64 = overflow_ret3;
                direct_page_7de64 = dp_ret3;
                data_bank_7de64 = db_ret3;
                goto shared_7DE6_3;
            }
        } else {
            if (x_ret5) {
                y_7de6 = (uint8_t)y_ret3;
                carry_7de6 = carry_ret3;
                overflow_7de6 = overflow_ret3;
                direct_page_7de6 = dp_ret3;
                data_bank_7de6 = db_ret3;
                goto shared_7DE6;
            } else {
                y_7de62 = y_ret3;
                carry_7de62 = carry_ret3;
                overflow_7de62 = overflow_ret3;
                direct_page_7de62 = dp_ret3;
                data_bank_7de62 = db_ret3;
                goto shared_7DE6_1;
            }
        }
    }
    shared_7DE6:;
    r->y = y_7de6;
    r->c = carry_7de6;
    r->v = overflow_7de6;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_7de6;
    r->dp = direct_page_7de6;
    RETURN_RTS(c);
    shared_7DE6_1:;
    r->y = y_7de62;
    r->c = carry_7de62;
    r->v = overflow_7de62;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_7de62;
    r->dp = direct_page_7de62;
    RETURN_RTS(c);
    shared_7DE6_2:;
    r->y = y_7de63;
    r->c = carry_7de63;
    r->v = overflow_7de63;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_7de63;
    r->dp = direct_page_7de63;
    RETURN_RTS(c);
    shared_7DE6_3:;
    r->y = y_7de64;
    r->c = carry_7de64;
    r->v = overflow_7de64;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_7de64;
    r->dp = direct_page_7de64;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27DB5, SOM_RTS, "gen", prepare_native58_revive_cast_and_execute_success, 0, L_Y | L_C | L_V, 1, 1, 0, 50, 20)
