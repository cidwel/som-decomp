#include "som_c.h"

/* C20A9A move_fractional_boss_axes_with_terrain_party_rollback_without_sliding   [class B, 99 bytes, 38 instructions]
 * Source: src/rom/move_fractional_boss_axes_with_terrain_party_rollback_without_sliding.s
 * Documented in docs/boss-fractional-motion.md
 * Entry: M=any X=16 bit DB=$7E D=any.
 * The code is width-agnostic (the store and the adds follow the accumulator width); the callee C215B7 only runs in range at M=16.  Callers read: ABXYCZNV.
 */
static void move_fractional_boss_axes_with_terrain_party_rollback_without_sliding(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    uint8_t a_hi_0ab9 = 0;
    uint16_t x_0ab9 = 0;
    uint16_t y_0ab9 = 0;
    uint8_t a_hi_0ab92 = 0;
    uint16_t x_0ab92 = 0;
    uint16_t y_0ab92 = 0;
    uint8_t a_hi_0acc = 0;
    uint16_t x_0acc = 0;
    uint16_t y_0acc = 0;
    uint8_t a_hi_0acc2 = 0;
    uint16_t x_0acc2 = 0;
    uint16_t y_0acc2 = 0;
    uint8_t a_hi_0ae9 = 0;
    uint16_t x_0ae9 = 0;
    uint16_t y_0ae9 = 0;
    uint8_t a_hi_0ae92 = 0;
    uint16_t x_0ae92 = 0;
    uint16_t y_0ae92 = 0;
    uint8_t a_0afc = 0;
    uint8_t a_hi_0afc = 0;
    uint16_t x_0afc = 0;
    uint16_t y_0afc = 0;
    bool carry_0afc = 0;
    bool zero_0afc = 0;
    bool negative_0afc = 0;
    bool overflow_0afc = 0;
    uint8_t a_0afc2 = 0;
    uint8_t a_hi_0afc2 = 0;
    uint16_t x_0afc2 = 0;
    uint16_t y_0afc2 = 0;
    bool carry_0afc2 = 0;
    bool zero_0afc2 = 0;
    bool negative_0afc2 = 0;
    bool overflow_0afc2 = 0;
    if (r->mf) {
        RAM8(0x00C3 + dp) = a;
        uint8_t value = RAM8(0x0029 + x);
        uint8_t value2 = RAM8(0x003A + x);
        RAM8(0x0029 + x) = (uint8_t)(value + value2);
        uint8_t value3 = RAM8(0x002B + x);
        uint8_t value4 = RAM8(0x003C + x);
        const uint8_t sum_hi = (uint8_t)(value3 + value4 + (value + value2 > 0xFF));
        RAM8(0x002B + x) = sum_hi;
        r->a = (a_hi << 8) | sum_hi;
        r->v = ((value3 ^ sum_hi) & (value4 ^ sum_hi) & 0x80) != 0;
    } else {
        /* the same code at M=16: the store and both adds are 16-bit */
        RAM16_SET(0x00C3 + dp, r->a);
        uint16_t value = RAM16(0x0029 + x);
        uint16_t value2 = RAM16(0x003A + x);
        RAM16_SET(0x0029 + x, (uint16_t)(value + value2));
        uint16_t value3 = RAM16(0x002B + x);
        uint16_t value4 = RAM16(0x003C + x);
        const uint16_t sum_hi = (uint16_t)(value3 + value4 + ((uint32_t)value + value2 > 0xFFFF));
        RAM16_SET(0x002B + x, sum_hi);
        r->a = sum_hi;
        r->v = ((value3 ^ sum_hi) & (value4 ^ sum_hi) & 0x8000) != 0;
    }
    { const uint16_t sp_call = r->sp; JSR(c, 0x0AB1, 0xC215B7); GUARD_JSR(c, sp_call, 0x0AB1); } /* prepare_boss_object_terrain */
    bool m_ret = r->mf;
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    if (carry_ret) {
        if (m_ret) {
            a_hi_0ab9 = a_all >> 8;
            x_0ab9 = x_ret;
            y_0ab9 = y_ret;
            goto shared_0AB9;
        } else {
            a_hi_0ab92 = a_all >> 8;
            x_0ab92 = x_ret;
            y_0ab92 = y_ret;
            goto shared_0AB9_1;
        }
    }
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0AB6, 0xC21723); GUARD_JSR(c, sp_call, 0x0AB6); } /* test_animation_movement_against_three_active_party_actors */
    bool m_ret2 = r->mf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    if (!carry_ret2) {
        if (m_ret2) {
            a_hi_0acc = a_all2 >> 8;
            x_0acc = x_ret2;
            y_0acc = y_ret2;
            goto shared_0ACC;
        } else {
            a_hi_0acc2 = a_all2 >> 8;
            x_0acc2 = x_ret2;
            y_0acc2 = y_ret2;
            goto shared_0ACC_1;
        }
    }
    if (m_ret2) {
        a_hi_0ab9 = a_all2 >> 8;
        x_0ab9 = x_ret2;
        y_0ab9 = y_ret2;
        goto shared_0AB9;
    } else {
        a_hi_0ab92 = a_all2 >> 8;
        x_0ab92 = x_ret2;
        y_0ab92 = y_ret2;
        goto shared_0AB9_1;
    }
    shared_0AB9:;
    uint8_t value5 = RAM8(0x0029 + x_0ab9);
    uint8_t value6 = RAM8(0x003A + x_0ab9);
    RAM8(0x0029 + x_0ab9) = (uint8_t)(value5 - value6);
    RAM8(0x002B + x_0ab9) = (uint8_t)(RAM8(0x002B + x_0ab9) - RAM8(0x003C + x_0ab9) - (value5 >= value6 ^ 1));
    a_hi_0acc = a_hi_0ab9;
    x_0acc = x_0ab9;
    y_0acc = y_0ab9;
    goto shared_0ACC;
    shared_0AB9_1:;
    uint16_t value9 = RAM16(0x0029 + x_0ab92);
    uint16_t value10 = RAM16(0x003A + x_0ab92);
    RAM16_SET(0x0029 + x_0ab92, (uint16_t)(value9 - value10));
    uint16_t value11 = RAM16(0x002B + x_0ab92);
    uint16_t value12 = RAM16(0x003C + x_0ab92);
    RAM16_SET(0x002B + x_0ab92, (uint16_t)(value11 - value12 - (value9 >= value10 ^ 1)));
    a_hi_0acc2 = (uint16_t)(value11 - value12 - (value9 >= value10 ^ 1)) >> 8;
    x_0acc2 = x_0ab92;
    y_0acc2 = y_0ab92;
    goto shared_0ACC_1;
    shared_0ACC:;
    uint8_t value13 = RAM8(0x0030 + x_0acc);
    uint8_t value14 = RAM8(0x003E + x_0acc);
    RAM8(0x0030 + x_0acc) = (uint8_t)(value13 + value14);
    uint8_t value15 = RAM8(0x0032 + x_0acc);
    uint8_t value16 = RAM8(0x0040 + x_0acc);
    RAM8(0x0032 + x_0acc) = (uint8_t)(value15 + value16 + (value13 + value14 > 0xFF));
    r->a = (a_hi_0acc << 8) | (uint8_t)(value15 + value16 + (value13 + value14 > 0xFF));
    r->x = x_0acc;
    r->y = y_0acc;
    r->v = ((value15 ^ (uint8_t)(value15 + value16 + (value13 + value14 > 0xFF))) & (value16 ^ (uint8_t)(value15 + value16 + (value13 + value14 > 0xFF))) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = dp;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0AE1, 0xC215B7); GUARD_JSR(c, sp_call, 0x0AE1); } /* prepare_boss_object_terrain */
    bool m_ret3 = r->mf;
    uint16_t a_all3 = r->a;
    uint16_t x_ret3 = r->x;
    uint16_t y_ret3 = r->y;
    bool carry_ret3 = r->c;
    if (carry_ret3) {
        if (m_ret3) {
            a_hi_0ae9 = a_all3 >> 8;
            x_0ae9 = x_ret3;
            y_0ae9 = y_ret3;
            goto shared_0AE9;
        } else {
            a_hi_0ae92 = a_all3 >> 8;
            x_0ae92 = x_ret3;
            y_0ae92 = y_ret3;
            goto shared_0AE9_1;
        }
    }
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0AE6, 0xC21723); GUARD_JSR(c, sp_call, 0x0AE6); } /* test_animation_movement_against_three_active_party_actors */
    bool m_ret4 = r->mf;
    uint16_t a_all4 = r->a;
    uint16_t x_ret4 = r->x;
    uint16_t y_ret4 = r->y;
    bool carry_ret4 = r->c;
    bool zero_ret4 = r->z;
    bool negative_ret4 = r->n;
    bool overflow_ret4 = r->v;
    if (!carry_ret4) {
        if (m_ret4) {
            a_0afc = (uint8_t)a_all4;
            a_hi_0afc = a_all4 >> 8;
            x_0afc = x_ret4;
            y_0afc = y_ret4;
            carry_0afc = carry_ret4;
            zero_0afc = zero_ret4;
            negative_0afc = negative_ret4;
            overflow_0afc = overflow_ret4;
            goto shared_0AFC;
        } else {
            a_0afc2 = (uint8_t)a_all4;
            a_hi_0afc2 = a_all4 >> 8;
            x_0afc2 = x_ret4;
            y_0afc2 = y_ret4;
            carry_0afc2 = carry_ret4;
            zero_0afc2 = zero_ret4;
            negative_0afc2 = negative_ret4;
            overflow_0afc2 = overflow_ret4;
            goto shared_0AFC_1;
        }
    }
    if (m_ret4) {
        a_hi_0ae9 = a_all4 >> 8;
        x_0ae9 = x_ret4;
        y_0ae9 = y_ret4;
        goto shared_0AE9;
    } else {
        a_hi_0ae92 = a_all4 >> 8;
        x_0ae92 = x_ret4;
        y_0ae92 = y_ret4;
        goto shared_0AE9_1;
    }
    shared_0ACC_1:;
    uint16_t value17 = RAM16(0x0030 + x_0acc2);
    uint16_t value18 = RAM16(0x003E + x_0acc2);
    RAM16_SET(0x0030 + x_0acc2, (uint16_t)(value17 + value18));
    uint16_t value19 = RAM16(0x0032 + x_0acc2);
    uint16_t value20 = RAM16(0x0040 + x_0acc2);
    RAM16_SET(0x0032 + x_0acc2, (uint16_t)(value19 + value20 + (value17 + value18 > 0xFFFF)));
    r->a = (uint16_t)(value19 + value20 + (value17 + value18 > 0xFFFF));
    r->x = x_0acc2;
    r->y = y_0acc2;
    r->v = ((value19 ^ (uint16_t)(value19 + value20 + (value17 + value18 > 0xFFFF))) & (value20 ^ (uint16_t)(value19 + value20 + (value17 + value18 > 0xFFFF))) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = dp;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0AE1, 0xC215B7); GUARD_JSR(c, sp_call, 0x0AE1); } /* prepare_boss_object_terrain */
    uint16_t a_all5 = r->a;
    uint16_t x_ret5 = r->x;
    uint16_t y_ret5 = r->y;
    bool carry_ret5 = r->c;
    if (carry_ret5) {
        a_hi_0ae92 = a_all5 >> 8;
        x_0ae92 = x_ret5;
        y_0ae92 = y_ret5;
        goto shared_0AE9_1;
    }
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0AE6, 0xC21723); GUARD_JSR(c, sp_call, 0x0AE6); } /* test_animation_movement_against_three_active_party_actors */
    uint16_t a_all6 = r->a;
    uint16_t x_ret6 = r->x;
    uint16_t y_ret6 = r->y;
    bool carry_ret6 = r->c;
    bool zero_ret6 = r->z;
    bool negative_ret6 = r->n;
    bool overflow_ret6 = r->v;
    if (!carry_ret6) {
        a_0afc2 = (uint8_t)a_all6;
        a_hi_0afc2 = a_all6 >> 8;
        x_0afc2 = x_ret6;
        y_0afc2 = y_ret6;
        carry_0afc2 = carry_ret6;
        zero_0afc2 = zero_ret6;
        negative_0afc2 = negative_ret6;
        overflow_0afc2 = overflow_ret6;
        goto shared_0AFC_1;
    }
    a_hi_0ae92 = a_all6 >> 8;
    x_0ae92 = x_ret6;
    y_0ae92 = y_ret6;
    goto shared_0AE9_1;
    shared_0AE9:;
    uint8_t value21 = RAM8(0x0030 + x_0ae9);
    uint8_t value22 = RAM8(0x003E + x_0ae9);
    RAM8(0x0030 + x_0ae9) = (uint8_t)(value21 - value22);
    uint8_t value23 = RAM8(0x0032 + x_0ae9);
    uint8_t value24 = RAM8(0x0040 + x_0ae9);
    RAM8(0x0032 + x_0ae9) = (uint8_t)(value23 - value24 - (value21 >= value22 ^ 1));
    a_0afc = (uint8_t)(value23 - value24 - (value21 >= value22 ^ 1));
    a_hi_0afc = a_hi_0ae9;
    x_0afc = x_0ae9;
    y_0afc = y_0ae9;
    carry_0afc = value23 - value24 >= (value21 >= value22 ^ 1);
    zero_0afc = (uint8_t)(value23 - value24 - (value21 >= value22 ^ 1)) == 0;
    negative_0afc = (uint8_t)(value23 - value24 - (value21 >= value22 ^ 1)) & 0x80;
    overflow_0afc = ((value23 ^ value24) & (value23 ^ (uint8_t)(value23 - value24 - (value21 >= value22 ^ 1))) & 0x80) != 0;
    goto shared_0AFC;
    shared_0AE9_1:;
    uint16_t value25 = RAM16(0x0030 + x_0ae92);
    uint16_t value26 = RAM16(0x003E + x_0ae92);
    RAM16_SET(0x0030 + x_0ae92, (uint16_t)(value25 - value26));
    uint16_t value27 = RAM16(0x0032 + x_0ae92);
    uint16_t value28 = RAM16(0x0040 + x_0ae92);
    RAM16_SET(0x0032 + x_0ae92, (uint16_t)(value27 - value28 - (value25 >= value26 ^ 1)));
    a_0afc2 = (uint8_t)(value27 - value28 - (value25 >= value26 ^ 1));
    a_hi_0afc2 = (uint16_t)(value27 - value28 - (value25 >= value26 ^ 1)) >> 8;
    x_0afc2 = x_0ae92;
    y_0afc2 = y_0ae92;
    carry_0afc2 = value27 - value28 >= (value25 >= value26 ^ 1);
    zero_0afc2 = (uint16_t)(value27 - value28 - (value25 >= value26 ^ 1)) == 0;
    negative_0afc2 = (uint16_t)(value27 - value28 - (value25 >= value26 ^ 1)) & 0x8000;
    overflow_0afc2 = ((value27 ^ value28) & (value27 ^ (uint16_t)(value27 - value28 - (value25 >= value26 ^ 1))) & 0x8000) != 0;
    goto shared_0AFC_1;
    shared_0AFC:;
    r->a = (a_hi_0afc << 8) | a_0afc;
    r->x = x_0afc;
    r->y = y_0afc;
    r->c = carry_0afc;
    r->z = zero_0afc;
    r->n = negative_0afc;
    r->v = overflow_0afc;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = dp;
    RETURN_RTS(c);
    shared_0AFC_1:;
    r->a = (a_hi_0afc2 << 8) | a_0afc2;
    r->x = x_0afc2;
    r->y = y_0afc2;
    r->c = carry_0afc2;
    r->z = zero_0afc2;
    r->n = negative_0afc2;
    r->v = overflow_0afc2;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = dp;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20A9A, SOM_RTS, "hand", move_fractional_boss_axes_with_terrain_party_rollback_without_sliding, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, 0, 99, 38)
