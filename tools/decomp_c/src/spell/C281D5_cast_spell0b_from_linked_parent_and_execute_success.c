#include "som_c.h"

/* C281D5 cast_spell0b_from_linked_parent_and_execute_success   [class B, 56 bytes, 23 instructions]
 * Source: src/rom/cast_spell0b_from_linked_parent_and_execute_success.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void cast_spell0b_from_linked_parent_and_execute_success(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t a_820c = 0;
    uint8_t a_hi_820c = 0;
    uint8_t x_820c = 0;
    uint8_t y_820c = 0;
    bool carry_820c = 0;
    bool zero_820c = 0;
    bool negative_820c = 0;
    bool overflow_820c = 0;
    uint16_t direct_page_820c = 0;
    uint8_t data_bank_820c = 0;
    uint8_t a_820c2 = 0;
    uint8_t a_hi_820c2 = 0;
    uint16_t x_820c2 = 0;
    uint16_t y_820c2 = 0;
    bool carry_820c2 = 0;
    bool zero_820c2 = 0;
    bool negative_820c2 = 0;
    bool overflow_820c2 = 0;
    uint16_t direct_page_820c2 = 0;
    uint8_t data_bank_820c2 = 0;
    uint8_t a_820c3 = 0;
    uint8_t a_hi_820c3 = 0;
    uint8_t x_820c3 = 0;
    uint8_t y_820c3 = 0;
    bool carry_820c3 = 0;
    bool zero_820c3 = 0;
    bool negative_820c3 = 0;
    bool overflow_820c3 = 0;
    uint16_t direct_page_820c3 = 0;
    uint8_t data_bank_820c3 = 0;
    uint8_t a_820c4 = 0;
    uint8_t a_hi_820c4 = 0;
    uint16_t x_820c4 = 0;
    uint16_t y_820c4 = 0;
    bool carry_820c4 = 0;
    bool zero_820c4 = 0;
    bool negative_820c4 = 0;
    bool overflow_820c4 = 0;
    uint16_t direct_page_820c4 = 0;
    uint8_t data_bank_820c4 = 0;
    uint8_t value = RAM8(0x00B0 + RAM16(BATTLE_DEFENCE_WORK));
    RAM8(0x0395) = value;
    RAM8(0x0170 + ((a_hi << 8) | value)) = 0x0B;
    RAM8(0x0176 + ((a_hi << 8) | value)) = 1;
    RAM8(0x0177 + ((a_hi << 8) | value)) = 0;
    RAM8(0x0178 + ((a_hi << 8) | value)) = 4;
    RAM8(0x0179 + ((a_hi << 8) | value)) = 0;
    RAM8(0x017A + ((a_hi << 8) | value)) = 0;
    r->a = (a_hi << 8) | 4;
    r->x = (a_hi << 8) | value;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x81FC, 0xC0001B); GUARD_JSL(c, sp_call, 0x81FC); } /* cast_spell_public_jump */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    if ((a_all & 0xFF) != 0) {
        if (x_ret) {
            a_820c = a_all & 0xFF;
            a_hi_820c = 0;
            x_820c = (uint8_t)x_ret2;
            y_820c = (uint8_t)y_ret;
            carry_820c = carry_ret;
            zero_820c = (a_all & 0xFF) == 0;
            negative_820c = a_all & 0xFF & 0x8000;
            overflow_820c = overflow_ret;
            direct_page_820c = dp_ret;
            data_bank_820c = db_ret;
            goto shared_820C;
        } else {
            a_820c2 = a_all & 0xFF;
            a_hi_820c2 = 0;
            x_820c2 = x_ret2;
            y_820c2 = y_ret;
            carry_820c2 = carry_ret;
            zero_820c2 = (a_all & 0xFF) == 0;
            negative_820c2 = a_all & 0xFF & 0x8000;
            overflow_820c2 = overflow_ret;
            direct_page_820c2 = dp_ret;
            data_bank_820c2 = db_ret;
            goto shared_820C_1;
        }
    }
    uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
    if (x_ret) {
        r->a = value2 & 0x1FFF;
        r->x = (uint8_t)(value2 & 0x1FFF);
        r->y = (uint8_t)y_ret;
        r->z = (uint8_t)(value2 & 0x1FFF) == 0;
        r->n = (uint8_t)(value2 & 0x1FFF) & 0x80;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x820B, 0x01800F); GUARD_JSL(c, sp_call, 0x820B); } /* cast_actor_request_public_jump */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret = r->mf;
        bool x_ret3 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret4 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        bool overflow_ret2 = r->v;
        if (m_ret) {
            if (x_ret3) {
                a_820c3 = (uint8_t)a_all2;
                a_hi_820c3 = a_all2 >> 8;
                x_820c3 = (uint8_t)x_ret4;
                y_820c3 = (uint8_t)y_ret2;
                carry_820c3 = carry_ret2;
                zero_820c3 = zero_ret2;
                negative_820c3 = negative_ret2;
                overflow_820c3 = overflow_ret2;
                direct_page_820c3 = dp_ret2;
                data_bank_820c3 = db_ret2;
                goto shared_820C_2;
            } else {
                a_820c4 = (uint8_t)a_all2;
                a_hi_820c4 = a_all2 >> 8;
                x_820c4 = x_ret4;
                y_820c4 = y_ret2;
                carry_820c4 = carry_ret2;
                zero_820c4 = zero_ret2;
                negative_820c4 = negative_ret2;
                overflow_820c4 = overflow_ret2;
                direct_page_820c4 = dp_ret2;
                data_bank_820c4 = db_ret2;
                goto shared_820C_3;
            }
        } else {
            if (x_ret3) {
                a_820c = (uint8_t)a_all2;
                a_hi_820c = a_all2 >> 8;
                x_820c = (uint8_t)x_ret4;
                y_820c = (uint8_t)y_ret2;
                carry_820c = carry_ret2;
                zero_820c = zero_ret2;
                negative_820c = negative_ret2;
                overflow_820c = overflow_ret2;
                direct_page_820c = dp_ret2;
                data_bank_820c = db_ret2;
                goto shared_820C;
            } else {
                a_820c2 = (uint8_t)a_all2;
                a_hi_820c2 = a_all2 >> 8;
                x_820c2 = x_ret4;
                y_820c2 = y_ret2;
                carry_820c2 = carry_ret2;
                zero_820c2 = zero_ret2;
                negative_820c2 = negative_ret2;
                overflow_820c2 = overflow_ret2;
                direct_page_820c2 = dp_ret2;
                data_bank_820c2 = db_ret2;
                goto shared_820C_1;
            }
        }
    } else {
        r->a = value2 & 0x1FFF;
        r->x = value2 & 0x1FFF;
        r->z = (value2 & 0x1FFF) == 0;
        r->n = value2 & 0x1FFF & 0x8000;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x820B, 0x01800F); GUARD_JSL(c, sp_call, 0x820B); } /* cast_actor_request_public_jump */
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        bool m_ret2 = r->mf;
        bool x_ret5 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t x_ret6 = r->x;
        uint16_t y_ret3 = r->y;
        bool carry_ret3 = r->c;
        bool zero_ret3 = r->z;
        bool negative_ret3 = r->n;
        bool overflow_ret3 = r->v;
        if (m_ret2) {
            if (x_ret5) {
                a_820c3 = (uint8_t)a_all3;
                a_hi_820c3 = a_all3 >> 8;
                x_820c3 = (uint8_t)x_ret6;
                y_820c3 = (uint8_t)y_ret3;
                carry_820c3 = carry_ret3;
                zero_820c3 = zero_ret3;
                negative_820c3 = negative_ret3;
                overflow_820c3 = overflow_ret3;
                direct_page_820c3 = dp_ret3;
                data_bank_820c3 = db_ret3;
                goto shared_820C_2;
            } else {
                a_820c4 = (uint8_t)a_all3;
                a_hi_820c4 = a_all3 >> 8;
                x_820c4 = x_ret6;
                y_820c4 = y_ret3;
                carry_820c4 = carry_ret3;
                zero_820c4 = zero_ret3;
                negative_820c4 = negative_ret3;
                overflow_820c4 = overflow_ret3;
                direct_page_820c4 = dp_ret3;
                data_bank_820c4 = db_ret3;
                goto shared_820C_3;
            }
        } else {
            if (x_ret5) {
                a_820c = (uint8_t)a_all3;
                a_hi_820c = a_all3 >> 8;
                x_820c = (uint8_t)x_ret6;
                y_820c = (uint8_t)y_ret3;
                carry_820c = carry_ret3;
                zero_820c = zero_ret3;
                negative_820c = negative_ret3;
                overflow_820c = overflow_ret3;
                direct_page_820c = dp_ret3;
                data_bank_820c = db_ret3;
                goto shared_820C;
            } else {
                a_820c2 = (uint8_t)a_all3;
                a_hi_820c2 = a_all3 >> 8;
                x_820c2 = x_ret6;
                y_820c2 = y_ret3;
                carry_820c2 = carry_ret3;
                zero_820c2 = zero_ret3;
                negative_820c2 = negative_ret3;
                overflow_820c2 = overflow_ret3;
                direct_page_820c2 = dp_ret3;
                data_bank_820c2 = db_ret3;
                goto shared_820C_1;
            }
        }
    }
    shared_820C:;
    r->a = (a_hi_820c << 8) | a_820c;
    r->x = x_820c;
    r->y = y_820c;
    r->c = carry_820c;
    r->z = zero_820c;
    r->n = negative_820c;
    r->v = overflow_820c;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_820c;
    r->dp = direct_page_820c;
    RETURN_RTS(c);
    shared_820C_1:;
    r->a = (a_hi_820c2 << 8) | a_820c2;
    r->x = x_820c2;
    r->y = y_820c2;
    r->c = carry_820c2;
    r->z = zero_820c2;
    r->n = negative_820c2;
    r->v = overflow_820c2;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_820c2;
    r->dp = direct_page_820c2;
    RETURN_RTS(c);
    shared_820C_2:;
    r->a = (a_hi_820c3 << 8) | a_820c3;
    r->x = x_820c3;
    r->y = y_820c3;
    r->c = carry_820c3;
    r->z = zero_820c3;
    r->n = negative_820c3;
    r->v = overflow_820c3;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_820c3;
    r->dp = direct_page_820c3;
    RETURN_RTS(c);
    shared_820C_3:;
    r->a = (a_hi_820c4 << 8) | a_820c4;
    r->x = x_820c4;
    r->y = y_820c4;
    r->c = carry_820c4;
    r->z = zero_820c4;
    r->n = negative_820c4;
    r->v = overflow_820c4;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_820c4;
    r->dp = direct_page_820c4;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC281D5, SOM_RTS, "gen", cast_spell0b_from_linked_parent_and_execute_success, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 56, 23)
