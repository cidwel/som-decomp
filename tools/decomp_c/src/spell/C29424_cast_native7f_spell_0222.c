#include "som_c.h"

/* C29424 cast_native7f_spell_0222   [class C, 63 bytes, 25 instructions]
 * Source: src/rom/cast_native7f_spell_0222.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void cast_native7f_spell_0222(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_9445 = 0;
    uint8_t a_hi_9445 = 0;
    uint16_t y_9445 = 0;
    bool carry_9445 = 0;
    bool overflow_9445 = 0;
    uint8_t a_9462 = 0;
    uint8_t a_hi_9462 = 0;
    uint8_t x_9462 = 0;
    uint8_t y_9462 = 0;
    bool carry_9462 = 0;
    bool zero_9462 = 0;
    bool negative_9462 = 0;
    bool overflow_9462 = 0;
    uint16_t direct_page_9462 = 0;
    uint8_t data_bank_9462 = 0;
    uint8_t a_94622 = 0;
    uint8_t a_hi_94622 = 0;
    uint16_t x_94622 = 0;
    uint16_t y_94622 = 0;
    bool carry_94622 = 0;
    bool zero_94622 = 0;
    bool negative_94622 = 0;
    bool overflow_94622 = 0;
    uint16_t direct_page_94622 = 0;
    uint8_t data_bank_94622 = 0;
    uint8_t a_94623 = 0;
    uint8_t a_hi_94623 = 0;
    uint8_t x_94623 = 0;
    uint8_t y_94623 = 0;
    bool carry_94623 = 0;
    bool zero_94623 = 0;
    bool negative_94623 = 0;
    bool overflow_94623 = 0;
    uint16_t direct_page_94623 = 0;
    uint8_t data_bank_94623 = 0;
    uint8_t a_94624 = 0;
    uint8_t a_hi_94624 = 0;
    uint16_t x_94624 = 0;
    uint16_t y_94624 = 0;
    bool carry_94624 = 0;
    bool zero_94624 = 0;
    bool negative_94624 = 0;
    bool overflow_94624 = 0;
    uint16_t direct_page_94624 = 0;
    uint8_t data_bank_94624 = 0;
    a_9445 = 0x22;
    a_hi_9445 = 2;
    y_9445 = y;
    carry_9445 = carry;
    overflow_9445 = overflow;
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    r->a = (a_hi_9445 << 8) | a_9445;
    r->x = battle_defence_work;
    r->y = y_9445;
    r->c = carry_9445;
    r->z = battle_defence_work == 0;
    r->n = battle_defence_work & 0x8000;
    r->v = overflow_9445;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0300;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9449, 0xC2396D); GUARD_JSR(c, sp_call, 0x9449); } /* prepare_boss_spell_targets */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x944D, 0xC0001B); GUARD_JSL(c, sp_call, 0x944D); } /* cast_spell_public_jump */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret2 = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret3 = r->x;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    if ((a_all2 & 0xFF) != 0) {
        if (x_ret2) {
            a_9462 = a_all2 & 0xFF;
            a_hi_9462 = 0;
            x_9462 = (uint8_t)x_ret3;
            y_9462 = (uint8_t)y_ret2;
            carry_9462 = carry_ret2;
            zero_9462 = (a_all2 & 0xFF) == 0;
            negative_9462 = a_all2 & 0xFF & 0x8000;
            overflow_9462 = overflow_ret2;
            direct_page_9462 = dp_ret;
            data_bank_9462 = db_ret;
            goto shared_9462;
        } else {
            a_94622 = a_all2 & 0xFF;
            a_hi_94622 = 0;
            x_94622 = x_ret3;
            y_94622 = y_ret2;
            carry_94622 = carry_ret2;
            zero_94622 = (a_all2 & 0xFF) == 0;
            negative_94622 = a_all2 & 0xFF & 0x8000;
            overflow_94622 = overflow_ret2;
            direct_page_94622 = dp_ret;
            data_bank_94622 = db_ret;
            goto shared_9462_1;
        }
    }
    if (x_ret2) {
        uint8_t value = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        BUS16_SET(c, (db_ret << 0x10) + 0x60 + value, 0);
        uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        r->a = value2 & 0x1FFF;
        r->x = (uint8_t)(value2 & 0x1FFF);
        r->y = (uint8_t)y_ret2;
        r->z = (uint8_t)(value2 & 0x1FFF) == 0;
        r->n = (uint8_t)(value2 & 0x1FFF) & 0x80;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x9461, 0x01800F); GUARD_JSL(c, sp_call, 0x9461); } /* cast_actor_request_public_jump */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret = r->mf;
        bool x_ret4 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t x_ret5 = r->x;
        uint16_t y_ret3 = r->y;
        bool carry_ret3 = r->c;
        bool zero_ret3 = r->z;
        bool negative_ret3 = r->n;
        bool overflow_ret3 = r->v;
        if (m_ret) {
            if (x_ret4) {
                a_94623 = (uint8_t)a_all3;
                a_hi_94623 = a_all3 >> 8;
                x_94623 = (uint8_t)x_ret5;
                y_94623 = (uint8_t)y_ret3;
                carry_94623 = carry_ret3;
                zero_94623 = zero_ret3;
                negative_94623 = negative_ret3;
                overflow_94623 = overflow_ret3;
                direct_page_94623 = dp_ret2;
                data_bank_94623 = db_ret2;
                goto shared_9462_2;
            } else {
                a_94624 = (uint8_t)a_all3;
                a_hi_94624 = a_all3 >> 8;
                x_94624 = x_ret5;
                y_94624 = y_ret3;
                carry_94624 = carry_ret3;
                zero_94624 = zero_ret3;
                negative_94624 = negative_ret3;
                overflow_94624 = overflow_ret3;
                direct_page_94624 = dp_ret2;
                data_bank_94624 = db_ret2;
                goto shared_9462_3;
            }
        } else {
            if (x_ret4) {
                a_9462 = (uint8_t)a_all3;
                a_hi_9462 = a_all3 >> 8;
                x_9462 = (uint8_t)x_ret5;
                y_9462 = (uint8_t)y_ret3;
                carry_9462 = carry_ret3;
                zero_9462 = zero_ret3;
                negative_9462 = negative_ret3;
                overflow_9462 = overflow_ret3;
                direct_page_9462 = dp_ret2;
                data_bank_9462 = db_ret2;
                goto shared_9462;
            } else {
                a_94622 = (uint8_t)a_all3;
                a_hi_94622 = a_all3 >> 8;
                x_94622 = x_ret5;
                y_94622 = y_ret3;
                carry_94622 = carry_ret3;
                zero_94622 = zero_ret3;
                negative_94622 = negative_ret3;
                overflow_94622 = overflow_ret3;
                direct_page_94622 = dp_ret2;
                data_bank_94622 = db_ret2;
                goto shared_9462_1;
            }
        }
    } else {
        uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        BUS16_SET(c, (db_ret << 0x10) + 0x60 + value3, 0);
        uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        r->a = value4 & 0x1FFF;
        r->x = value4 & 0x1FFF;
        r->z = (value4 & 0x1FFF) == 0;
        r->n = value4 & 0x1FFF & 0x8000;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x9461, 0x01800F); GUARD_JSL(c, sp_call, 0x9461); } /* cast_actor_request_public_jump */
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        bool m_ret2 = r->mf;
        bool x_ret6 = r->xf;
        uint16_t a_all4 = r->a;
        uint16_t x_ret7 = r->x;
        uint16_t y_ret4 = r->y;
        bool carry_ret4 = r->c;
        bool zero_ret4 = r->z;
        bool negative_ret4 = r->n;
        bool overflow_ret4 = r->v;
        if (m_ret2) {
            if (x_ret6) {
                a_94623 = (uint8_t)a_all4;
                a_hi_94623 = a_all4 >> 8;
                x_94623 = (uint8_t)x_ret7;
                y_94623 = (uint8_t)y_ret4;
                carry_94623 = carry_ret4;
                zero_94623 = zero_ret4;
                negative_94623 = negative_ret4;
                overflow_94623 = overflow_ret4;
                direct_page_94623 = dp_ret3;
                data_bank_94623 = db_ret3;
                goto shared_9462_2;
            } else {
                a_94624 = (uint8_t)a_all4;
                a_hi_94624 = a_all4 >> 8;
                x_94624 = x_ret7;
                y_94624 = y_ret4;
                carry_94624 = carry_ret4;
                zero_94624 = zero_ret4;
                negative_94624 = negative_ret4;
                overflow_94624 = overflow_ret4;
                direct_page_94624 = dp_ret3;
                data_bank_94624 = db_ret3;
                goto shared_9462_3;
            }
        } else {
            if (x_ret6) {
                a_9462 = (uint8_t)a_all4;
                a_hi_9462 = a_all4 >> 8;
                x_9462 = (uint8_t)x_ret7;
                y_9462 = (uint8_t)y_ret4;
                carry_9462 = carry_ret4;
                zero_9462 = zero_ret4;
                negative_9462 = negative_ret4;
                overflow_9462 = overflow_ret4;
                direct_page_9462 = dp_ret3;
                data_bank_9462 = db_ret3;
                goto shared_9462;
            } else {
                a_94622 = (uint8_t)a_all4;
                a_hi_94622 = a_all4 >> 8;
                x_94622 = x_ret7;
                y_94622 = y_ret4;
                carry_94622 = carry_ret4;
                zero_94622 = zero_ret4;
                negative_94622 = negative_ret4;
                overflow_94622 = overflow_ret4;
                direct_page_94622 = dp_ret3;
                data_bank_94622 = db_ret3;
                goto shared_9462_1;
            }
        }
    }
    shared_9462:;
    r->a = (a_hi_9462 << 8) | a_9462;
    r->x = x_9462;
    r->y = y_9462;
    r->c = carry_9462;
    r->z = zero_9462;
    r->n = negative_9462;
    r->v = overflow_9462;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_9462;
    r->dp = direct_page_9462;
    RETURN_RTS(c);
    shared_9462_1:;
    r->a = (a_hi_94622 << 8) | a_94622;
    r->x = x_94622;
    r->y = y_94622;
    r->c = carry_94622;
    r->z = zero_94622;
    r->n = negative_94622;
    r->v = overflow_94622;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_94622;
    r->dp = direct_page_94622;
    RETURN_RTS(c);
    shared_9462_2:;
    r->a = (a_hi_94623 << 8) | a_94623;
    r->x = x_94623;
    r->y = y_94623;
    r->c = carry_94623;
    r->z = zero_94623;
    r->n = negative_94623;
    r->v = overflow_94623;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_94623;
    r->dp = direct_page_94623;
    RETURN_RTS(c);
    shared_9462_3:;
    r->a = (a_hi_94624 << 8) | a_94624;
    r->x = x_94624;
    r->y = y_94624;
    r->c = carry_94624;
    r->z = zero_94624;
    r->n = negative_94624;
    r->v = overflow_94624;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_94624;
    r->dp = direct_page_94624;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29424, SOM_RTS, "gen", cast_native7f_spell_0222, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 63, 25)
