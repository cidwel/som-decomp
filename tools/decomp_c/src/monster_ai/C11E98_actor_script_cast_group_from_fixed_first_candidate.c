#include "som_c.h"

/* C11E98 actor_script_cast_group_from_fixed_first_candidate   [class B, 159 bytes, 72 instructions]
 * Source: src/rom/actor_script_cast_group_from_fixed_first_candidate.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_cast_group_from_fixed_first_candidate(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t y = r->y;
    uint8_t a_hi_1eae = 0;
    uint16_t y_1eae = 0;
    bool overflow_1eae = 0;
    uint8_t a_hi_1eab = 0;
    uint16_t x_1eab = 0;
    uint16_t y_1eab = 0;
    bool carry_1eab = 0;
    bool zero_1eab = 0;
    bool negative_1eab = 0;
    bool overflow_1eab = 0;
    uint8_t a_1ecc = 0;
    uint8_t a_hi_1ecc = 0;
    uint16_t y_1ecc = 0;
    bool carry_1ecc = 0;
    bool overflow_1ecc = 0;
    uint8_t a_hi_1efb = 0;
    uint16_t x_1efb = 0;
    uint16_t y_1efb = 0;
    bool carry_1efb = 0;
    bool overflow_1efb = 0;
    uint16_t direct_page_1efb = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1E9A, 0xC11E2C); GUARD_JSR(c, sp_call, 0x1E9A); } /* actor_script_compare_mp_to_spell_argument_cost */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    if (carry_ret) {
        a_hi_1eae = a_all >> 8;
        y_1eae = y;
        overflow_1eae = overflow_ret;
        goto shared_1EAE;
    }
    uint8_t value = RAM8(0x0060 + y);
    if (value == 0xE0) {
        a_hi_1eab = a_all >> 8;
        x_1eab = x_ret;
        y_1eab = y;
        carry_1eab = value >= 0xE0;
        zero_1eab = value == 0xE0;
        negative_1eab = (uint8_t)(value - 0xE0) & 0x80;
        overflow_1eab = overflow_ret;
        goto shared_1EAB;
    }
    uint8_t value2 = RAM8(0x0190 + y);
    if ((value2 & 0x80) == 0) {
        a_hi_1eae = a_all >> 8;
        y_1eae = y;
        overflow_1eae = overflow_ret;
        goto shared_1EAE;
    }
    a_hi_1eab = a_all >> 8;
    x_1eab = x_ret;
    y_1eab = y;
    carry_1eab = value >= 0xE0;
    zero_1eab = (value2 & 0x80) == 0;
    negative_1eab = value2 & 0x80 & 0x80;
    overflow_1eab = overflow_ret;
    shared_1EAB:;
    r->a = (a_hi_1eab << 8) | a;
    r->x = x_1eab;
    r->y = y_1eab;
    r->c = carry_1eab;
    r->z = zero_1eab;
    r->n = negative_1eab;
    r->v = overflow_1eab;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = dp;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1F31, 0xC12534); GUARD_JSR(c, sp_call, 0x1F31); } /* write_actor_facing_fallback_command */
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all3 = r->a;
    r->a = (a_all3 >> 8 << 8) | 3;
    r->z = 0;
    r->n = 0;
    TAIL_CALL(c, 0xC10111, SOM_RTS); /* advance_actor_script_and_yield */
    shared_1EAE:;
    RAM8(0x0176 + y_1eae) = 0;
    RAM8(0x0177 + y_1eae) = 0;
    RAM8(0x0178 + y_1eae) = 0;
    RAM8(0x0179 + y_1eae) = 0;
    RAM8(0x017A + y_1eae) = 0;
    RAM8(0x0000 + sp0) = y_1eae >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)y_1eae;
    RAM8(0x0000 + sp0 - 2) = 3;
    uint8_t value3 = RAM8(0x01AD + y_1eae);
    if (value3 == 3) {
        a_1ecc = 3;
        a_hi_1ecc = a_hi_1eae;
        y_1ecc = y_1eae;
        carry_1ecc = value3 <= 3;
        overflow_1ecc = overflow_1eae;
        goto shared_1ECC;
    }
    if (value3 <= 3) {
        uint8_t a_hi1 = a_hi_1eae;
        uint16_t x1 = 0xE000;
        uint16_t y1 = y_1eae;
        bool carry1 = value3 <= 3;
        bool zero1 = value3 == 3;
        bool overflow1 = overflow_1eae;
        uint16_t direct_page = dp;
        for (;;) {
            r->a = (a_hi1 << 8) | a;
            r->x = x1;
            r->y = y1;
            r->c = carry1;
            r->z = zero1;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = direct_page;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1EE8, 0xC1054A); GUARD_JSR(c, sp_call, 0x1EE8); } /* test_actor_target_eligibility */
            r->sp += 3;
            uint16_t dp_ret = r->dp;
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all2 = r->a;
            uint16_t x_ret2 = r->x;
            bool carry_ret2 = r->c;
            bool zero_ret2 = r->z;
            bool overflow_ret2 = r->v;
            if (!zero_ret2) {
                uint8_t value4 = RAM8(0x0000 + sp0 - 2);
                RAM8(0x0000 + sp0 - 2) = (uint8_t)(value4 - 1);
                if ((uint8_t)(value4 - 1) != 0) {
                    a_hi1 = a_all2 >> 8;
                    x1 = x_ret2;
                    carry1 = carry_ret2;
                    zero1 = (uint8_t)(value4 - 1) == 0;
                    overflow1 = overflow_ret2;
                    direct_page = dp_ret;
                    continue;
                }
                a_hi1 = a_all2 >> 8;
                x1 = x_ret2;
                carry1 = carry_ret2;
                zero1 = (uint8_t)(value4 - 1) == 0;
                overflow1 = overflow_ret2;
                direct_page = dp_ret;
                break;
            }
            uint8_t value5 = RAM8(0x0000 + sp0 - 2);
            RAM8(0x0178 + y1) = (uint8_t)(4 - value5);
            uint8_t value6 = RAM8(0x0000 + sp0 - 2);
            RAM8(0x0000 + sp0 - 2) = (uint8_t)(value6 - 1);
            if ((uint8_t)(value6 - 1) != 0) {
                a_hi1 = a_all2 >> 8;
                x1 = x_ret2;
                y1 = (uint16_t)(y1 + 1);
                carry1 = value5 <= 4;
                zero1 = (uint8_t)(value6 - 1) == 0;
                overflow1 = ((value5 ^ 4) & ((uint8_t)(4 - value5) ^ 4) & 0x80) != 0;
                direct_page = dp_ret;
                continue;
            }
            a_hi1 = a_all2 >> 8;
            x1 = x_ret2;
            y1 = (uint16_t)(y1 + 1);
            carry1 = value5 <= 4;
            zero1 = (uint8_t)(value6 - 1) == 0;
            overflow1 = ((value5 ^ 4) & ((uint8_t)(4 - value5) ^ 4) & 0x80) != 0;
            direct_page = dp_ret;
            break;
        }
        uint8_t value8 = RAM8(0x0000 + sp0 - 1);
        uint8_t value9 = RAM8(0x0000 + sp0);
        a_hi_1efb = a_hi1;
        x_1efb = x1;
        y_1efb = (value9 << 8) | value8;
        carry_1efb = carry1;
        overflow_1efb = overflow1;
        direct_page_1efb = direct_page;
        goto shared_1EFB;
    }
    a_1ecc = 3;
    a_hi_1ecc = a_hi_1eae;
    y_1ecc = y_1eae;
    carry_1ecc = value3 <= 3;
    overflow_1ecc = overflow_1eae;
    goto shared_1ECC;
    shared_1ECC:;
    uint8_t a1 = a_1ecc;
    uint8_t a_hi2 = a_hi_1ecc;
    uint16_t x2 = 0xE600;
    uint16_t y2 = y_1ecc;
    bool carry2 = carry_1ecc;
    bool zero2 = 0;
    bool negative1 = 1;
    bool overflow2 = overflow_1ecc;
    uint16_t direct_page2 = dp;
    for (;;) {
        r->a = (a_hi2 << 8) | a1;
        r->x = x2;
        r->y = y2;
        r->c = carry2;
        r->z = zero2;
        r->n = negative1;
        r->v = overflow2;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = direct_page2;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1ED1, 0xC1058B); GUARD_JSR(c, sp_call, 0x1ED1); } /* reject_ineligible_or_nonmonster_actor */
        r->sp += 3;
        uint16_t dp_ret3 = r->dp;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all4 = r->a;
        uint16_t x_ret3 = r->x;
        bool carry_ret4 = r->c;
        bool overflow_ret4 = r->v;
        if (carry_ret4) {
            uint8_t value10 = RAM8(0x0000 + sp0 - 2);
            RAM8(0x0000 + sp0 - 2) = (uint8_t)(value10 - 1);
            if ((uint8_t)(value10 - 1) != 0) {
                a1 = (uint8_t)(value10 - 1);
                a_hi2 = a_all4 >> 8;
                x2 = x_ret3;
                carry2 = carry_ret4;
                zero2 = (uint8_t)(value10 - 1) == 0;
                negative1 = (uint8_t)(value10 - 1) & 0x80;
                overflow2 = overflow_ret4;
                direct_page2 = dp_ret3;
                continue;
            }
            a1 = (uint8_t)(value10 - 1);
            a_hi2 = a_all4 >> 8;
            x2 = x_ret3;
            carry2 = carry_ret4;
            zero2 = (uint8_t)(value10 - 1) == 0;
            negative1 = (uint8_t)(value10 - 1) & 0x80;
            overflow2 = overflow_ret4;
            direct_page2 = dp_ret3;
            break;
        }
        uint8_t value11 = RAM8(0x0000 + sp0 - 2);
        RAM8(0x0178 + y2) = (uint8_t)(7 - value11);
        uint8_t value12 = RAM8(0x0000 + sp0 - 2);
        RAM8(0x0000 + sp0 - 2) = (uint8_t)(value12 - 1);
        if ((uint8_t)(value12 - 1) != 0) {
            a1 = (uint8_t)(value12 - 1);
            a_hi2 = a_all4 >> 8;
            x2 = x_ret3;
            y2 = (uint16_t)(y2 + 1);
            carry2 = value11 <= 7;
            zero2 = (uint8_t)(value12 - 1) == 0;
            negative1 = (uint8_t)(value12 - 1) & 0x80;
            overflow2 = ((value11 ^ 7) & ((uint8_t)(7 - value11) ^ 7) & 0x80) != 0;
            direct_page2 = dp_ret3;
            continue;
        }
        a1 = (uint8_t)(value12 - 1);
        a_hi2 = a_all4 >> 8;
        x2 = x_ret3;
        y2 = (uint16_t)(y2 + 1);
        carry2 = value11 <= 7;
        zero2 = (uint8_t)(value12 - 1) == 0;
        negative1 = (uint8_t)(value12 - 1) & 0x80;
        overflow2 = ((value11 ^ 7) & ((uint8_t)(7 - value11) ^ 7) & 0x80) != 0;
        direct_page2 = dp_ret3;
        break;
    }
    uint8_t value14 = RAM8(0x0000 + sp0 - 1);
    uint8_t value15 = RAM8(0x0000 + sp0);
    a_hi_1efb = a_hi2;
    x_1efb = x2;
    y_1efb = (value15 << 8) | value14;
    carry_1efb = carry2;
    overflow_1efb = overflow2;
    direct_page_1efb = direct_page2;
    goto shared_1EFB;
    shared_1EFB:;
    uint8_t value16 = RAM8(0x0178 + y_1efb);
    if (value16 == 0) {
        r->a = (a_hi_1efb << 8) | value16;
        r->x = x_1efb;
        r->y = y_1efb;
        r->c = carry_1efb;
        r->z = value16 == 0;
        r->n = value16 & 0x80;
        r->v = overflow_1efb;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = direct_page_1efb;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1F31, 0xC12534); GUARD_JSR(c, sp_call, 0x1F31); } /* write_actor_facing_fallback_command */
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all5 = r->a;
        r->a = (a_all5 >> 8 << 8) | 3;
        r->z = 0;
        r->n = 0;
        TAIL_CALL(c, 0xC10111, SOM_RTS); /* advance_actor_script_and_yield */
    }
    RAM8(0x0176 + y_1efb)++;
    if (RAM8(0x0179 + y_1efb) == 0) {
        RAM8(0x0140 + y_1efb) = 0x44;
        uint16_t value18 = RAM16(0x0144 + y_1efb);
        uint8_t value19 = BUS8(c, 0xD04F16 + value18);
        RAM8(0x0141 + y_1efb) = value19;
        uint8_t value20 = BUS8(c, 0xD04F17 + value18);
        RAM8(0x0170 + y_1efb) = value20;
        r->a = (a_hi_1efb << 8) | value20;
        r->x = value18;
        r->y = y_1efb;
        r->c = carry_1efb;
        r->z = value20 == 0;
        r->n = value20 & 0x80;
        r->v = overflow_1efb;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = direct_page_1efb;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1F2C, 0xC11E16); GUARD_JSR(c, sp_call, 0x1F2C); } /* actor_script_call_native_cast_preserving_context */
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all6 = r->a;
        r->a = (a_all6 >> 8 << 8) | 3;
        r->z = 0;
        r->n = 0;
        TAIL_CALL(c, 0xC10111, SOM_RTS); /* advance_actor_script_and_yield */
    }
    RAM8(0x0176 + y_1efb)++;
    if (RAM8(0x017A + y_1efb) == 0) {
        RAM8(0x0140 + y_1efb) = 0x44;
        uint16_t value22 = RAM16(0x0144 + y_1efb);
        uint8_t value23 = BUS8(c, 0xD04F16 + value22);
        RAM8(0x0141 + y_1efb) = value23;
        uint8_t value24 = BUS8(c, 0xD04F17 + value22);
        RAM8(0x0170 + y_1efb) = value24;
        r->a = (a_hi_1efb << 8) | value24;
        r->x = value22;
        r->y = y_1efb;
        r->c = carry_1efb;
        r->z = value24 == 0;
        r->n = value24 & 0x80;
        r->v = overflow_1efb;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = direct_page_1efb;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1F2C, 0xC11E16); GUARD_JSR(c, sp_call, 0x1F2C); } /* actor_script_call_native_cast_preserving_context */
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all7 = r->a;
        r->a = (a_all7 >> 8 << 8) | 3;
        r->z = 0;
        r->n = 0;
        TAIL_CALL(c, 0xC10111, SOM_RTS); /* advance_actor_script_and_yield */
    }
    RAM8(0x0176 + y_1efb)++;
    RAM8(0x0140 + y_1efb) = 0x44;
    uint16_t value25 = RAM16(0x0144 + y_1efb);
    uint8_t value26 = BUS8(c, 0xD04F16 + value25);
    RAM8(0x0141 + y_1efb) = value26;
    uint8_t value27 = BUS8(c, 0xD04F17 + value25);
    RAM8(0x0170 + y_1efb) = value27;
    r->a = (a_hi_1efb << 8) | value27;
    r->x = value25;
    r->y = y_1efb;
    r->c = carry_1efb;
    r->z = value27 == 0;
    r->n = value27 & 0x80;
    r->v = overflow_1efb;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = direct_page_1efb;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1F2C, 0xC11E16); GUARD_JSR(c, sp_call, 0x1F2C); } /* actor_script_call_native_cast_preserving_context */
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all8 = r->a;
    r->a = (a_all8 >> 8 << 8) | 3;
    r->z = 0;
    r->n = 0;
    TAIL_CALL(c, 0xC10111, SOM_RTS); /* advance_actor_script_and_yield */
}
SOM_REGISTER(0xC11E98, SOM_RTS, "gen", actor_script_cast_group_from_fixed_first_candidate, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 1, 0, 159, 72)
