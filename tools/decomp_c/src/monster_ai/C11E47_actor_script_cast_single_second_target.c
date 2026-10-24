#include "som_c.h"

/* C11E47 actor_script_cast_single_second_target   [class B, 81 bytes, 31 instructions]
 * Source: src/rom/actor_script_cast_single_second_target.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_cast_single_second_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint8_t a = r->a & 0xFF;
    const uint16_t y = r->y;
    uint8_t a_hi_1e90 = 0;
    uint8_t x_1e90 = 0;
    uint8_t y_1e90 = 0;
    bool carry_1e90 = 0;
    bool zero_1e90 = 0;
    bool negative_1e90 = 0;
    bool overflow_1e90 = 0;
    uint16_t direct_page_1e90 = 0;
    uint8_t a_hi_1e902 = 0;
    uint16_t x_1e902 = 0;
    uint16_t y_1e902 = 0;
    bool carry_1e902 = 0;
    bool zero_1e902 = 0;
    bool negative_1e902 = 0;
    bool overflow_1e902 = 0;
    uint16_t direct_page_1e902 = 0;
    uint8_t a_hi_1e93 = 0;
    uint8_t x_1e93 = 0;
    uint8_t y_1e93 = 0;
    bool carry_1e93 = 0;
    bool overflow_1e93 = 0;
    uint16_t direct_page_1e93 = 0;
    uint8_t data_bank_1e93 = 0;
    uint8_t a_hi_1e932 = 0;
    uint16_t x_1e932 = 0;
    uint16_t y_1e932 = 0;
    bool carry_1e932 = 0;
    bool overflow_1e932 = 0;
    uint16_t direct_page_1e932 = 0;
    uint8_t data_bank_1e932 = 0;
    uint8_t a_hi_1e933 = 0;
    uint8_t x_1e933 = 0;
    uint8_t y_1e933 = 0;
    bool carry_1e933 = 0;
    bool overflow_1e933 = 0;
    uint16_t direct_page_1e933 = 0;
    uint8_t data_bank_1e933 = 0;
    uint8_t a_hi_1e934 = 0;
    uint16_t x_1e934 = 0;
    uint16_t y_1e934 = 0;
    bool carry_1e934 = 0;
    bool overflow_1e934 = 0;
    uint16_t direct_page_1e934 = 0;
    uint8_t data_bank_1e934 = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1E49, 0xC105BA); GUARD_JSR(c, sp_call, 0x1E49); } /* resolve_visible_second_actor_target */
    uint16_t dp_ret = r->dp;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool negative_ret = r->n;
    bool overflow_ret = r->v;
    if (!zero_ret) {
        if (x_ret) {
            a_hi_1e90 = a_all >> 8;
            x_1e90 = (uint8_t)x_ret2;
            y_1e90 = (uint8_t)y;
            carry_1e90 = carry_ret;
            zero_1e90 = zero_ret;
            negative_1e90 = negative_ret;
            overflow_1e90 = overflow_ret;
            direct_page_1e90 = dp_ret;
            goto shared_1E90;
        } else {
            a_hi_1e902 = a_all >> 8;
            x_1e902 = x_ret2;
            y_1e902 = y;
            carry_1e902 = carry_ret;
            zero_1e902 = zero_ret;
            negative_1e902 = negative_ret;
            overflow_1e902 = overflow_ret;
            direct_page_1e902 = dp_ret;
            goto shared_1E90_1;
        }
    }
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1E4E, 0xC11E2C); GUARD_JSR(c, sp_call, 0x1E4E); } /* actor_script_compare_mp_to_spell_argument_cost */
    bool x_ret3 = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret4 = r->x;
    bool carry_ret2 = r->c;
    bool zero_ret2 = r->z;
    bool negative_ret2 = r->n;
    bool overflow_ret2 = r->v;
    if (!carry_ret2) {
        if (x_ret3) {
            a_hi_1e90 = a_all2 >> 8;
            x_1e90 = (uint8_t)x_ret4;
            y_1e90 = (uint8_t)y;
            carry_1e90 = carry_ret2;
            zero_1e90 = zero_ret2;
            negative_1e90 = negative_ret2;
            overflow_1e90 = overflow_ret2;
            direct_page_1e90 = dp_ret;
            goto shared_1E90;
        } else {
            a_hi_1e902 = a_all2 >> 8;
            x_1e902 = x_ret4;
            y_1e902 = y;
            carry_1e902 = carry_ret2;
            zero_1e902 = zero_ret2;
            negative_1e902 = negative_ret2;
            overflow_1e902 = overflow_ret2;
            direct_page_1e902 = dp_ret;
            goto shared_1E90_1;
        }
    }
    uint8_t value = RAM8(0x0190 + y);
    if ((value & 0x80) != 0) {
        if (x_ret3) {
            a_hi_1e90 = a_all2 >> 8;
            x_1e90 = (uint8_t)x_ret4;
            y_1e90 = (uint8_t)y;
            carry_1e90 = carry_ret2;
            zero_1e90 = (value & 0x80) == 0;
            negative_1e90 = value & 0x80 & 0x80;
            overflow_1e90 = overflow_ret2;
            direct_page_1e90 = dp_ret;
            goto shared_1E90;
        } else {
            a_hi_1e902 = a_all2 >> 8;
            x_1e902 = x_ret4;
            y_1e902 = y;
            carry_1e902 = carry_ret2;
            zero_1e902 = (value & 0x80) == 0;
            negative_1e902 = value & 0x80 & 0x80;
            overflow_1e902 = overflow_ret2;
            direct_page_1e902 = dp_ret;
            goto shared_1E90_1;
        }
    }
    uint8_t value2 = RAM8(0x0060 + y);
    if (value2 == 0xE0) {
        if (x_ret3) {
            a_hi_1e90 = a_all2 >> 8;
            x_1e90 = (uint8_t)x_ret4;
            y_1e90 = (uint8_t)y;
            carry_1e90 = value2 >= 0xE0;
            zero_1e90 = value2 == 0xE0;
            negative_1e90 = (uint8_t)(value2 - 0xE0) & 0x80;
            overflow_1e90 = overflow_ret2;
            direct_page_1e90 = dp_ret;
            goto shared_1E90;
        } else {
            a_hi_1e902 = a_all2 >> 8;
            x_1e902 = x_ret4;
            y_1e902 = y;
            carry_1e902 = value2 >= 0xE0;
            zero_1e902 = value2 == 0xE0;
            negative_1e902 = (uint8_t)(value2 - 0xE0) & 0x80;
            overflow_1e902 = overflow_ret2;
            direct_page_1e902 = dp_ret;
            goto shared_1E90_1;
        }
    }
    RAM8(0x0140 + y) = 0x44;
    if (x_ret3) {
        uint8_t value3 = RAM8(0x0144 + (uint8_t)y);
        uint8_t value4 = BUS8(c, 0xD04F16 + value3);
        RAM8(0x0141 + (uint8_t)y) = value4;
        uint8_t value5 = BUS8(c, 0xD04F17 + value3);
        RAM8(0x0170 + (uint8_t)y) = value5;
        RAM8(0x0177 + (uint8_t)y) = 0;
        RAM8(0x0178 + (uint8_t)y) = (uint8_t)(RAM8(0x01AD + (uint8_t)y) + 1);
        RAM8(0x0179 + (uint8_t)y) = 0;
        RAM8(0x017A + (uint8_t)y) = 0;
        RAM8(0x0176 + (uint8_t)y) = 1;
        r->a = (a_all2 >> 8 << 8) | 1;
        r->x = (uint8_t)y;
        r->y = (uint8_t)y;
        r->c = value2 >= 0xE0;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1E8D, 0xC11E16); GUARD_JSR(c, sp_call, 0x1E8D); } /* actor_script_call_native_cast_preserving_context */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret5 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t x_ret6 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret3 = r->c;
        bool overflow_ret3 = r->v;
        if (m_ret) {
            if (x_ret5) {
                a_hi_1e93 = a_all3 >> 8;
                x_1e93 = (uint8_t)x_ret6;
                y_1e93 = (uint8_t)y_ret;
                carry_1e93 = carry_ret3;
                overflow_1e93 = overflow_ret3;
                direct_page_1e93 = dp_ret2;
                data_bank_1e93 = db_ret;
                goto shared_1E93;
            } else {
                a_hi_1e932 = a_all3 >> 8;
                x_1e932 = x_ret6;
                y_1e932 = y_ret;
                carry_1e932 = carry_ret3;
                overflow_1e932 = overflow_ret3;
                direct_page_1e932 = dp_ret2;
                data_bank_1e932 = db_ret;
                goto shared_1E93_1;
            }
        } else {
            if (x_ret5) {
                a_hi_1e933 = a_all3 >> 8;
                x_1e933 = (uint8_t)x_ret6;
                y_1e933 = (uint8_t)y_ret;
                carry_1e933 = carry_ret3;
                overflow_1e933 = overflow_ret3;
                direct_page_1e933 = dp_ret2;
                data_bank_1e933 = db_ret;
                goto shared_1E93_2;
            } else {
                a_hi_1e934 = a_all3 >> 8;
                x_1e934 = x_ret6;
                y_1e934 = y_ret;
                carry_1e934 = carry_ret3;
                overflow_1e934 = overflow_ret3;
                direct_page_1e934 = dp_ret2;
                data_bank_1e934 = db_ret;
                goto shared_1E93_3;
            }
        }
    } else {
        uint16_t value7 = RAM16(0x0144 + y);
        uint8_t value8 = BUS8(c, 0xD04F16 + value7);
        RAM8(0x0141 + y) = value8;
        uint8_t value9 = BUS8(c, 0xD04F17 + value7);
        RAM8(0x0170 + y) = value9;
        RAM8(0x0177 + y) = 0;
        RAM8(0x0178 + y) = (uint8_t)(RAM8(0x01AD + y) + 1);
        RAM8(0x0179 + y) = 0;
        RAM8(0x017A + y) = 0;
        RAM8(0x0176 + y) = 1;
        r->a = (a_all2 >> 8 << 8) | 1;
        r->x = y;
        r->c = value2 >= 0xE0;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1E8D, 0xC11E16); GUARD_JSR(c, sp_call, 0x1E8D); } /* actor_script_call_native_cast_preserving_context */
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret2 = r->mf;
        bool x_ret7 = r->xf;
        uint16_t a_all4 = r->a;
        uint16_t x_ret8 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret4 = r->c;
        bool overflow_ret4 = r->v;
        if (m_ret2) {
            if (x_ret7) {
                a_hi_1e93 = a_all4 >> 8;
                x_1e93 = (uint8_t)x_ret8;
                y_1e93 = (uint8_t)y_ret2;
                carry_1e93 = carry_ret4;
                overflow_1e93 = overflow_ret4;
                direct_page_1e93 = dp_ret3;
                data_bank_1e93 = db_ret2;
                goto shared_1E93;
            } else {
                a_hi_1e932 = a_all4 >> 8;
                x_1e932 = x_ret8;
                y_1e932 = y_ret2;
                carry_1e932 = carry_ret4;
                overflow_1e932 = overflow_ret4;
                direct_page_1e932 = dp_ret3;
                data_bank_1e932 = db_ret2;
                goto shared_1E93_1;
            }
        } else {
            if (x_ret7) {
                a_hi_1e933 = a_all4 >> 8;
                x_1e933 = (uint8_t)x_ret8;
                y_1e933 = (uint8_t)y_ret2;
                carry_1e933 = carry_ret4;
                overflow_1e933 = overflow_ret4;
                direct_page_1e933 = dp_ret3;
                data_bank_1e933 = db_ret2;
                goto shared_1E93_2;
            } else {
                a_hi_1e934 = a_all4 >> 8;
                x_1e934 = x_ret8;
                y_1e934 = y_ret2;
                carry_1e934 = carry_ret4;
                overflow_1e934 = overflow_ret4;
                direct_page_1e934 = dp_ret3;
                data_bank_1e934 = db_ret2;
                goto shared_1E93_3;
            }
        }
    }
    shared_1E90:;
    r->a = (a_hi_1e90 << 8) | a;
    r->x = x_1e90;
    r->y = y_1e90;
    r->c = carry_1e90;
    r->z = zero_1e90;
    r->n = negative_1e90;
    r->v = overflow_1e90;
    r->mf = 1;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = direct_page_1e90;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1E92, 0xC12534); GUARD_JSR(c, sp_call, 0x1E92); } /* write_actor_facing_fallback_command */
    uint16_t dp_ret4 = r->dp;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret9 = r->xf;
    uint16_t a_all5 = r->a;
    bool carry_ret5 = r->c;
    bool overflow_ret5 = r->v;
    if (x_ret9) {
        a_hi_1e93 = a_all5 >> 8;
        x_1e93 = x_1e90;
        y_1e93 = y_1e90;
        carry_1e93 = carry_ret5;
        overflow_1e93 = overflow_ret5;
        direct_page_1e93 = dp_ret4;
        data_bank_1e93 = 0x7E;
        goto shared_1E93;
    } else {
        a_hi_1e932 = a_all5 >> 8;
        x_1e932 = x_1e90;
        y_1e932 = y_1e90;
        carry_1e932 = carry_ret5;
        overflow_1e932 = overflow_ret5;
        direct_page_1e932 = dp_ret4;
        data_bank_1e932 = 0x7E;
        goto shared_1E93_1;
    }
    shared_1E90_1:;
    r->a = (a_hi_1e902 << 8) | a;
    r->x = x_1e902;
    r->y = y_1e902;
    r->c = carry_1e902;
    r->z = zero_1e902;
    r->n = negative_1e902;
    r->v = overflow_1e902;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = direct_page_1e902;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1E92, 0xC12534); GUARD_JSR(c, sp_call, 0x1E92); } /* write_actor_facing_fallback_command */
    uint16_t dp_ret5 = r->dp;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret10 = r->xf;
    uint16_t a_all6 = r->a;
    bool carry_ret6 = r->c;
    bool overflow_ret6 = r->v;
    if (x_ret10) {
        a_hi_1e93 = a_all6 >> 8;
        x_1e93 = (uint8_t)x_1e902;
        y_1e93 = (uint8_t)y_1e902;
        carry_1e93 = carry_ret6;
        overflow_1e93 = overflow_ret6;
        direct_page_1e93 = dp_ret5;
        data_bank_1e93 = 0x7E;
        goto shared_1E93;
    } else {
        a_hi_1e932 = a_all6 >> 8;
        x_1e932 = x_1e902;
        y_1e932 = y_1e902;
        carry_1e932 = carry_ret6;
        overflow_1e932 = overflow_ret6;
        direct_page_1e932 = dp_ret5;
        data_bank_1e932 = 0x7E;
        goto shared_1E93_1;
    }
    shared_1E93:;
    r->a = (a_hi_1e93 << 8) | 3;
    r->x = x_1e93;
    r->y = y_1e93;
    r->c = carry_1e93;
    r->z = 0;
    r->n = 0;
    r->v = overflow_1e93;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_1e93;
    r->dp = direct_page_1e93;
    TAIL_CALL(c, 0xC10111, SOM_RTS); /* advance_actor_script_and_yield */
    shared_1E93_1:;
    r->a = (a_hi_1e932 << 8) | 3;
    r->x = x_1e932;
    r->y = y_1e932;
    r->c = carry_1e932;
    r->z = 0;
    r->n = 0;
    r->v = overflow_1e932;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_1e932;
    r->dp = direct_page_1e932;
    TAIL_CALL(c, 0xC10111, SOM_RTS); /* advance_actor_script_and_yield */
    shared_1E93_2:;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_1E93_3:;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
}
SOM_REGISTER(0xC11E47, SOM_RTS, "gen", actor_script_cast_single_second_target, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 81, 31)
