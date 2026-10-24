#include "som_c.h"

/* C11945 actor_script_explicit_slot_distance_unequal_class_1   [class B, 43 bytes, 20 instructions]
 * Source: src/rom/actor_script_explicit_slot_distance_unequal_class_1.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void actor_script_explicit_slot_distance_unequal_class_1(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint8_t value2 = BUS8(c, 0xD04F16 + RAM16(0x0144 + y));
    uint8_t value3 = RAM8(0x0000 + (uint16_t)((((uint8_t)(value2 << 1) << 8) | 0) + 0xE000));
    bool m_flag2;
    bool x_flag2;
    uint8_t a2;
    uint8_t a_hi2;
    uint16_t x2;
    bool carry2;
    bool zero2;
    bool negative2;
    bool overflow2;
    uint16_t direct_page2;
    if (value3 != 1) {
        r->a = ((uint16_t)((((uint8_t)(value2 << 1) << 8) | 0) + 0xE000) >> 8 << 8) | value3;
        r->x = (uint16_t)((((uint8_t)(value2 << 1) << 8) | 0) + 0xE000);
        r->c = value3 >= 1;
        r->z = value3 == 1;
        r->n = (uint8_t)(value3 - 1) & 0x80;
        r->v = (((((uint8_t)(value2 << 1) << 8) | 0) ^ (uint16_t)((((uint8_t)(value2 << 1) << 8) | 0) + 0xE000)) & ((uint16_t)((((uint8_t)(value2 << 1) << 8) | 0) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x196E, 0xC1028D); GUARD_JSR(c, sp_call, 0x196E); } /* jump_actor_script_after_2_bytes */
        uint16_t dp_ret = r->dp;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        bool carry_ret = r->c;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        bool overflow_ret = r->v;
        m_flag2 = m_ret;
        x_flag2 = x_ret;
        a2 = (uint8_t)a_all;
        a_hi2 = a_all >> 8;
        x2 = x_ret2;
        carry2 = carry_ret;
        zero2 = zero_ret;
        negative2 = negative_ret;
        overflow2 = overflow_ret;
        direct_page2 = dp_ret;
    } else {
        r->a = ((uint16_t)((((uint8_t)(value2 << 1) << 8) | 0) + 0xE000) >> 8 << 8) | value3;
        r->x = (uint16_t)((((uint8_t)(value2 << 1) << 8) | 0) + 0xE000);
        r->c = value3 >= 1;
        r->z = value3 == 1;
        r->n = (uint8_t)(value3 - 1) & 0x80;
        r->v = (((((uint8_t)(value2 << 1) << 8) | 0) ^ (uint16_t)((((uint8_t)(value2 << 1) << 8) | 0) + 0xE000)) & ((uint16_t)((((uint8_t)(value2 << 1) << 8) | 0) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1962, 0xC10358); GUARD_JSR(c, sp_call, 0x1962); } /* classify_actor_squared_distance */
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all2 = r->a;
        bool m_flag;
        bool x_flag;
        uint8_t a1;
        uint8_t a_hi1;
        uint16_t x1;
        bool carry1;
        bool zero1;
        bool negative1;
        bool overflow1;
        uint16_t direct_page;
        if ((uint8_t)a_all2 == 1) {
            r->c = (uint8_t)a_all2 >= 1;
            r->z = (uint8_t)a_all2 == 1;
            r->n = (uint8_t)((uint8_t)a_all2 - 1) & 0x80;
            { const uint16_t sp_call = r->sp; JSR(c, 0x196E, 0xC1028D); GUARD_JSR(c, sp_call, 0x196E); } /* jump_actor_script_after_2_bytes */
            uint16_t dp_ret2 = r->dp;
            bool m_ret2 = r->mf;
            bool x_ret4 = r->xf;
            uint16_t a_all3 = r->a;
            uint16_t x_ret5 = r->x;
            bool carry_ret3 = r->c;
            bool zero_ret3 = r->z;
            bool negative_ret3 = r->n;
            bool overflow_ret3 = r->v;
            m_flag = m_ret2;
            x_flag = x_ret4;
            a1 = (uint8_t)a_all3;
            a_hi1 = a_all3 >> 8;
            x1 = x_ret5;
            carry1 = carry_ret3;
            zero1 = zero_ret3;
            negative1 = negative_ret3;
            overflow1 = overflow_ret3;
            direct_page = dp_ret2;
        } else {
            r->c = (uint8_t)a_all2 >= 1;
            r->z = (uint8_t)a_all2 == 1;
            r->n = (uint8_t)((uint8_t)a_all2 - 1) & 0x80;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1969, 0xC1021B); GUARD_JSR(c, sp_call, 0x1969); } /* skip_actor_script_after_2_bytes */
            uint16_t dp_ret3 = r->dp;
            bool m_ret3 = r->mf;
            bool x_ret6 = r->xf;
            uint16_t a_all4 = r->a;
            uint16_t x_ret7 = r->x;
            bool carry_ret4 = r->c;
            bool zero_ret4 = r->z;
            bool negative_ret4 = r->n;
            bool overflow_ret4 = r->v;
            m_flag = m_ret3;
            x_flag = x_ret6;
            a1 = (uint8_t)a_all4;
            a_hi1 = a_all4 >> 8;
            x1 = x_ret7;
            carry1 = carry_ret4;
            zero1 = zero_ret4;
            negative1 = negative_ret4;
            overflow1 = overflow_ret4;
            direct_page = dp_ret3;
        }
        m_flag2 = m_flag;
        x_flag2 = x_flag;
        a2 = a1;
        a_hi2 = a_hi1;
        x2 = x1;
        carry2 = carry1;
        zero2 = zero1;
        negative2 = negative1;
        overflow2 = overflow1;
        direct_page2 = direct_page;
    }
    r->a = (a_hi2 << 8) | a2;
    r->x = x2;
    r->c = carry2;
    r->z = zero2;
    r->n = negative2;
    r->v = overflow2;
    r->mf = m_flag2;
    r->xf = x_flag2;
    r->dp = direct_page2;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC11945, SOM_RTS, "gen", actor_script_explicit_slot_distance_unequal_class_1, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 43, 20)
