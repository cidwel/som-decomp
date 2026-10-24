#include "som_c.h"

/* C29DDF pull_spell_target_and_test_lifetime_or_parent_offset   [class B, 101 bytes, 42 instructions]
 * Source: src/rom/pull_spell_target_and_test_lifetime_or_parent_offset.s
 * Documented in docs/boss-native-spell-pull-child.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void pull_spell_target_and_test_lifetime_or_parent_offset(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    r->x = RAM16(CURRENT_OBJECT_DP0 + dp);
    { const uint16_t sp_call = r->sp; JSR(c, 0x9DE3, 0xC29910); GUARD_JSR(c, sp_call, 0x9DE3); } /* set_eligible_spell_target_status_and_timer */
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9DE6, 0xC29E6F); GUARD_JSR(c, sp_call, 0x9DE6); } /* move_party_target_toward_parent_offset_with_fixed_point_vector */
    uint16_t x_ret = r->x;
    bool overflow_ret = r->v;
    uint16_t value = RAM16(OBJECT_AGE + x_ret);
    uint8_t a6;
    uint8_t a_hi6;
    uint16_t x6;
    uint16_t y6;
    bool zero6;
    bool negative6;
    bool overflow4;
    if (value >= 0x3C) {
        uint16_t current_object_dp02 = RAM16(CURRENT_OBJECT_DP0 + dp);
        r->a = 0x0124;
        r->x = current_object_dp02;
        r->c = value >= 0x3C;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9E3B, 0xC21394); GUARD_JSR(c, sp_call, 0x9E3B); } /* select_boss_animation_and_reset_frame_cursor */
        RAM16_SET(OBJECT_PHASE + current_object_dp02, (uint16_t)(RAM16(OBJECT_PHASE + current_object_dp02) + 1));
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9E41, 0xC29E55); GUARD_JSR(c, sp_call, 0x9E41); } /* release_eligible_pull_target_control24 */
        uint16_t a_all4 = r->a;
        uint16_t y_ret3 = r->y;
        bool zero_ret4 = r->z;
        bool negative_ret4 = r->n;
        a6 = (uint8_t)a_all4;
        a_hi6 = a_all4 >> 8;
        x6 = current_object_dp02;
        y6 = y_ret3;
        zero6 = zero_ret4;
        negative6 = negative_ret4;
        overflow4 = overflow_ret;
    } else {
        uint16_t value3 = RAM16(0x00BE + x_ret);
        uint8_t a5;
        uint8_t a_hi5;
        uint16_t x5;
        uint16_t y5;
        bool zero5;
        bool negative5;
        bool overflow3;
        if (value3 != 0) {
            uint16_t value4 = RAM16(0x00B2 + x_ret);
            uint16_t value5 = RAM16(0x00B0 + x_ret);
            uint16_t value6 = RAM16(0x0004 + value4);
            uint16_t value7 = RAM16(0x0032 + value5);
            uint8_t a2;
            uint8_t a_hi2;
            uint16_t x2;
            uint16_t y2;
            bool zero2;
            bool negative2;
            bool overflow1;
            if ((uint16_t)(value6 - 0x28) < value7) {
                uint16_t current_object_dp03 = RAM16(CURRENT_OBJECT_DP0 + dp);
                r->a = 0x0124;
                r->x = current_object_dp03;
                r->y = value4;
                r->c = (uint16_t)(value6 - 0x28) >= value7;
                r->v = ((value6 ^ 0x28) & (value6 ^ (uint16_t)(value6 - 0x28)) & 0x8000) != 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x9E3B, 0xC21394); GUARD_JSR(c, sp_call, 0x9E3B); } /* select_boss_animation_and_reset_frame_cursor */
                RAM16_SET(OBJECT_PHASE + current_object_dp03, (uint16_t)(RAM16(OBJECT_PHASE + current_object_dp03) + 1));
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x9E41, 0xC29E55); GUARD_JSR(c, sp_call, 0x9E41); } /* release_eligible_pull_target_control24 */
                uint16_t a_all6 = r->a;
                uint16_t y_ret4 = r->y;
                bool zero_ret6 = r->z;
                bool negative_ret6 = r->n;
                a2 = (uint8_t)a_all6;
                a_hi2 = a_all6 >> 8;
                x2 = current_object_dp03;
                y2 = y_ret4;
                zero2 = zero_ret6;
                negative2 = negative_ret6;
                overflow1 = ((value6 ^ 0x28) & (value6 ^ (uint16_t)(value6 - 0x28)) & 0x8000) != 0;
            } else {
                uint16_t value9 = RAM16(0x0002 + value4);
                uint16_t value10 = RAM16(0x002B + value5);
                uint8_t a1;
                uint8_t a_hi1;
                uint16_t x1;
                uint16_t y1;
                bool zero1;
                bool negative1;
                if ((uint16_t)(value9 - 0x50) < value10) {
                    a1 = (uint8_t)(value9 - 0x50);
                    a_hi1 = (uint16_t)(value9 - 0x50) >> 8;
                    x1 = value5;
                    y1 = value4;
                    zero1 = (uint16_t)(value9 - 0x50) == value10;
                    negative1 = (uint16_t)((uint16_t)(value9 - 0x50) - value10) & 0x8000;
                } else {
                    uint16_t current_object_dp04 = RAM16(CURRENT_OBJECT_DP0 + dp);
                    r->a = 0x0124;
                    r->x = current_object_dp04;
                    r->y = value4;
                    r->c = (uint16_t)(value9 - 0x50) >= value10;
                    r->v = ((value9 ^ 0x50) & (value9 ^ (uint16_t)(value9 - 0x50)) & 0x8000) != 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x9E3B, 0xC21394); GUARD_JSR(c, sp_call, 0x9E3B); } /* select_boss_animation_and_reset_frame_cursor */
                    RAM16_SET(OBJECT_PHASE + current_object_dp04, (uint16_t)(RAM16(OBJECT_PHASE + current_object_dp04) + 1));
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x9E41, 0xC29E55); GUARD_JSR(c, sp_call, 0x9E41); } /* release_eligible_pull_target_control24 */
                    uint16_t a_all8 = r->a;
                    uint16_t y_ret5 = r->y;
                    bool zero_ret8 = r->z;
                    bool negative_ret8 = r->n;
                    a1 = (uint8_t)a_all8;
                    a_hi1 = a_all8 >> 8;
                    x1 = current_object_dp04;
                    y1 = y_ret5;
                    zero1 = zero_ret8;
                    negative1 = negative_ret8;
                }
                a2 = a1;
                a_hi2 = a_hi1;
                x2 = x1;
                y2 = y1;
                zero2 = zero1;
                negative2 = negative1;
                overflow1 = ((value9 ^ 0x50) & (value9 ^ (uint16_t)(value9 - 0x50)) & 0x8000) != 0;
            }
            a5 = a2;
            a_hi5 = a_hi2;
            x5 = x2;
            y5 = y2;
            zero5 = zero2;
            negative5 = negative2;
            overflow3 = overflow1;
        } else {
            uint16_t value12 = RAM16(0x00B2 + x_ret);
            uint16_t value13 = RAM16(0x00B0 + x_ret);
            uint16_t value14 = RAM16(0x0004 + value12);
            uint16_t value15 = RAM16(0x0032 + value13);
            uint8_t a4;
            uint8_t a_hi4;
            uint16_t x4;
            uint16_t y4;
            bool zero4;
            bool negative4;
            bool overflow2;
            if ((uint16_t)(value14 - 0x28) < value15) {
                uint16_t current_object_dp05 = RAM16(CURRENT_OBJECT_DP0 + dp);
                r->a = 0x0124;
                r->x = current_object_dp05;
                r->y = value12;
                r->c = (uint16_t)(value14 - 0x28) >= value15;
                r->v = ((value14 ^ 0x28) & (value14 ^ (uint16_t)(value14 - 0x28)) & 0x8000) != 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x9E3B, 0xC21394); GUARD_JSR(c, sp_call, 0x9E3B); } /* select_boss_animation_and_reset_frame_cursor */
                RAM16_SET(OBJECT_PHASE + current_object_dp05, (uint16_t)(RAM16(OBJECT_PHASE + current_object_dp05) + 1));
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x9E41, 0xC29E55); GUARD_JSR(c, sp_call, 0x9E41); } /* release_eligible_pull_target_control24 */
                uint16_t a_all10 = r->a;
                uint16_t y_ret6 = r->y;
                bool zero_ret10 = r->z;
                bool negative_ret10 = r->n;
                a4 = (uint8_t)a_all10;
                a_hi4 = a_all10 >> 8;
                x4 = current_object_dp05;
                y4 = y_ret6;
                zero4 = zero_ret10;
                negative4 = negative_ret10;
                overflow2 = ((value14 ^ 0x28) & (value14 ^ (uint16_t)(value14 - 0x28)) & 0x8000) != 0;
            } else {
                uint16_t value17 = RAM16(0x0002 + value12);
                uint16_t value18 = RAM16(0x002B + value13);
                uint8_t a3;
                uint8_t a_hi3;
                uint16_t x3;
                uint16_t y3;
                bool zero3;
                bool negative3;
                if ((uint16_t)(value17 + 0x50) < value18) {
                    uint16_t current_object_dp06 = RAM16(CURRENT_OBJECT_DP0 + dp);
                    r->a = 0x0124;
                    r->x = current_object_dp06;
                    r->y = value12;
                    r->c = (uint16_t)(value17 + 0x50) >= value18;
                    r->v = ((value17 ^ (uint16_t)(value17 + 0x50)) & ((uint16_t)(value17 + 0x50) ^ 0x50) & 0x8000) != 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x9E3B, 0xC21394); GUARD_JSR(c, sp_call, 0x9E3B); } /* select_boss_animation_and_reset_frame_cursor */
                    RAM16_SET(OBJECT_PHASE + current_object_dp06, (uint16_t)(RAM16(OBJECT_PHASE + current_object_dp06) + 1));
                    r->mf = 0;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x9E41, 0xC29E55); GUARD_JSR(c, sp_call, 0x9E41); } /* release_eligible_pull_target_control24 */
                    uint16_t a_all12 = r->a;
                    uint16_t y_ret7 = r->y;
                    bool zero_ret12 = r->z;
                    bool negative_ret12 = r->n;
                    a3 = (uint8_t)a_all12;
                    a_hi3 = a_all12 >> 8;
                    x3 = current_object_dp06;
                    y3 = y_ret7;
                    zero3 = zero_ret12;
                    negative3 = negative_ret12;
                } else {
                    a3 = (uint8_t)(value17 + 0x50);
                    a_hi3 = (uint16_t)(value17 + 0x50) >> 8;
                    x3 = value13;
                    y3 = value12;
                    zero3 = (uint16_t)(value17 + 0x50) == value18;
                    negative3 = (uint16_t)((uint16_t)(value17 + 0x50) - value18) & 0x8000;
                }
                a4 = a3;
                a_hi4 = a_hi3;
                x4 = x3;
                y4 = y3;
                zero4 = zero3;
                negative4 = negative3;
                overflow2 = ((value17 ^ (uint16_t)(value17 + 0x50)) & ((uint16_t)(value17 + 0x50) ^ 0x50) & 0x8000) != 0;
            }
            a5 = a4;
            a_hi5 = a_hi4;
            x5 = x4;
            y5 = y4;
            zero5 = zero4;
            negative5 = negative4;
            overflow3 = overflow2;
        }
        a6 = a5;
        a_hi6 = a_hi5;
        x6 = x5;
        y6 = y5;
        zero6 = zero5;
        negative6 = negative5;
        overflow4 = overflow3;
    }
    r->a = (a_hi6 << 8) | a6;
    r->x = x6;
    r->y = y6;
    r->c = 0;
    r->z = zero6;
    r->n = negative6;
    r->v = overflow4;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29DDF, SOM_RTS, "gen", pull_spell_target_and_test_lifetime_or_parent_offset, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 101, 42)
