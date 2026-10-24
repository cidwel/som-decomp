#include "som_c.h"

/* C246ED complete_native54_attack_animation_and_create_projectile   [class B, 162 bytes, 66 instructions]
 * Source: src/rom/complete_native54_attack_animation_and_create_projectile.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void complete_native54_attack_animation_and_create_projectile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0287);
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x46F1, 0xC24965); GUARD_JSR(c, sp_call, 0x46F1); } /* test_native54_negative_status_or_begin_hurt_shift */
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    if (carry_ret) {
        r->c = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value2 = RAM16(0x009E + x_ret);
    uint8_t a_hi1;
    if (value2 != 0) {
        a_hi1 = value2 >> 8;
    } else {
        if (RAM16(0x00BE + x_ret) != 0) {
            RAM16_SET(OBJECT_PHASE + x_ret, 0x0C);
            RAM8(0xF812 + y) = 0xC1;
            RAM8(0xF80E + y) = 0xDE;
            RAM8(0xF813 + y) = 0x40;
            r->a = 0x40;
            r->c = 0;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        RAM16_SET(OBJECT_PHASE + x_ret, 0x0C);
        if (RAM8(0x0076 + x_ret) != 0) {
            RAM8(OBJECT_PHASE + x_ret)++;
        }
        RAM8(0xF812 + y) = 0xC1;
        RAM8(0xF80E + y) = 0xDE;
        RAM8(0xF813 + y) = 0x40;
        a_hi1 = 0;
    }
    uint16_t value5 = RAM16(OBJECT_AGE + x_ret);
    if (value5 != 3) {
        r->a = value5;
        r->c = 0;
        r->z = value5 == 3;
        r->n = (uint16_t)(value5 - 3) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value6 = RAM16(0x0287);
    uint16_t value7 = RAM16(0x0042 + value6);
    r->a = (uint16_t)(value7 + 0x1C);
    r->x = value6;
    r->c = value7 + 0x1C > 0xFFFF;
    r->z = (uint16_t)(value7 + 0x1C) == 0;
    r->n = (uint16_t)(value7 + 0x1C) & 0x8000;
    r->v = (((uint16_t)(value7 + 0x1C) ^ 0x1C) & (value7 ^ (uint16_t)(value7 + 0x1C)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x474E, 0xC0006C); GUARD_JSL(c, sp_call, 0x474E); } /* boss_attack_row_public_jump */
    bool m_ret = r->mf;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    uint16_t value8 = RAM16(0x0287);
    if (m_ret) {
        RAM8(0x029B) = RAM8(0x00A9 + value8);
        RAM8(0x00B8 + value8) = 0;
        RAM8(0x0295) = RAM8(0x002B + value8);
        uint8_t value11 = RAM8(0x0032 + value8);
        RAM8(0x0297) = value11;
        RAM16_SET(0x0299, value8);
        r->a = (a_all2 >> 8 << 8) | value11;
        r->x = 0x4F7D;
        r->y = 0xA801;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x476D, 0xC20D53); GUARD_JSR(c, sp_call, 0x476D); } /* allocate_boss_object_pool_slot */
        uint16_t a_all3 = r->a;
        uint16_t x_ret3 = r->x;
        bool carry_ret3 = r->c;
        bool zero_ret3 = r->z;
        bool negative_ret3 = r->n;
        bool overflow_ret2 = r->v;
        bool m_flag;
        bool x_flag;
        uint8_t a1;
        uint8_t a_hi2;
        uint16_t x1;
        uint16_t y1;
        bool zero1;
        bool negative1;
        bool overflow1;
        if (carry_ret3) {
            m_flag = 0;
            x_flag = 0;
            a1 = (uint8_t)a_all3;
            a_hi2 = a_all3 >> 8;
            x1 = x_ret3;
            y1 = 0xA801;
            zero1 = zero_ret3;
            negative1 = negative_ret3;
            overflow1 = overflow_ret2;
        } else {
            RAM16_SET(0x002B + x_ret3, RAM16(0x0295));
            RAM16_SET(0x0032 + x_ret3, RAM16(0x0297));
            RAM16_SET(0x00B0 + x_ret3, RAM16(0x0299));
            RAM16_SET(0x00A9 + x_ret3, RAM16(0x029B));
            r->a = 0x3D;
            r->x = 0x0F;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x478C, 0xC230E3); GUARD_JSR(c, sp_call, 0x478C); } /* request_boss_sound_with_parameter_word */
            bool m_ret2 = r->mf;
            bool x_ret4 = r->xf;
            uint16_t a_all4 = r->a;
            uint16_t x_ret5 = r->x;
            uint16_t y_ret2 = r->y;
            bool zero_ret4 = r->z;
            bool negative_ret4 = r->n;
            bool overflow_ret3 = r->v;
            m_flag = m_ret2;
            x_flag = x_ret4;
            a1 = (uint8_t)a_all4;
            a_hi2 = a_all4 >> 8;
            x1 = x_ret5;
            y1 = y_ret2;
            zero1 = zero_ret4;
            negative1 = negative_ret4;
            overflow1 = overflow_ret3;
        }
        r->a = (a_hi2 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->c = 0;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow1;
        r->mf = m_flag;
        r->xf = x_flag;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        RAM16_SET(0x029B, RAM16(0x00A9 + value8));
        RAM16_SET(0x00B8 + value8, 0);
        RAM16_SET(0x0295, RAM16(0x002B + value8));
        uint16_t value18 = RAM16(0x0032 + value8);
        RAM16_SET(0x0297, value18);
        RAM16_SET(0x0299, value8);
        r->a = value18;
        r->x = 0x4F7D;
        r->y = 0xA801;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x476D, 0xC20D53); GUARD_JSR(c, sp_call, 0x476D); } /* allocate_boss_object_pool_slot */
        uint16_t a_all5 = r->a;
        uint16_t x_ret6 = r->x;
        bool carry_ret5 = r->c;
        bool zero_ret5 = r->z;
        bool negative_ret5 = r->n;
        bool overflow_ret4 = r->v;
        bool m_flag2;
        bool x_flag2;
        uint8_t a2;
        uint8_t a_hi3;
        uint16_t x2;
        uint16_t y2;
        bool zero2;
        bool negative2;
        bool overflow2;
        if (carry_ret5) {
            m_flag2 = 0;
            x_flag2 = 0;
            a2 = (uint8_t)a_all5;
            a_hi3 = a_all5 >> 8;
            x2 = x_ret6;
            y2 = 0xA801;
            zero2 = zero_ret5;
            negative2 = negative_ret5;
            overflow2 = overflow_ret4;
        } else {
            RAM16_SET(0x002B + x_ret6, RAM16(0x0295));
            RAM16_SET(0x0032 + x_ret6, RAM16(0x0297));
            RAM16_SET(0x00B0 + x_ret6, RAM16(0x0299));
            RAM16_SET(0x00A9 + x_ret6, RAM16(0x029B));
            r->a = 0x3D;
            r->x = 0x0F;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x478C, 0xC230E3); GUARD_JSR(c, sp_call, 0x478C); } /* request_boss_sound_with_parameter_word */
            bool m_ret3 = r->mf;
            bool x_ret7 = r->xf;
            uint16_t a_all6 = r->a;
            uint16_t x_ret8 = r->x;
            uint16_t y_ret3 = r->y;
            bool zero_ret6 = r->z;
            bool negative_ret6 = r->n;
            bool overflow_ret5 = r->v;
            m_flag2 = m_ret3;
            x_flag2 = x_ret7;
            a2 = (uint8_t)a_all6;
            a_hi3 = a_all6 >> 8;
            x2 = x_ret8;
            y2 = y_ret3;
            zero2 = zero_ret6;
            negative2 = negative_ret6;
            overflow2 = overflow_ret5;
        }
        r->a = (a_hi3 << 8) | a2;
        r->x = x2;
        r->y = y2;
        r->c = 0;
        r->z = zero2;
        r->n = negative2;
        r->v = overflow2;
        r->mf = m_flag2;
        r->xf = x_flag2;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC246ED, SOM_RTS, "gen", complete_native54_attack_animation_and_create_projectile, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 162, 66)
