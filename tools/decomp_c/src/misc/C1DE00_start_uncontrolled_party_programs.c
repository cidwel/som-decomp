#include "som_c.h"

static void start_uncontrolled_actor_program(SomCtx *c);
static void start_uncontrolled_actor_program_v2(SomCtx *c);

/* C1DE00 start_uncontrolled_party_programs   [class B, 39 bytes, 15 instructions]
 * Source: src/rom/start_uncontrolled_party_programs.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void start_uncontrolled_party_programs(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    r->x = 0;
    { const uint16_t sp_call = r->sp; JSR_LOCAL(c, 0xDE07, start_uncontrolled_actor_program); GUARD_JSR(c, sp_call, 0xDE07); }
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 0x0200;
    { const uint16_t sp_call = r->sp; JSR_LOCAL(c, 0xDE0D, start_uncontrolled_actor_program_v2); GUARD_JSR(c, sp_call, 0xDE0D); }
    uint8_t db_ret2 = r->db;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    uint8_t value = BUS8(c, (db_ret2 << 0x10) + 0xE400);
    bool m_flag3;
    bool x_flag3;
    uint8_t a_hi3;
    uint16_t x3;
    uint16_t y3;
    bool carry3;
    bool overflow3;
    if (value == 0) {
        m_flag3 = 1;
        x_flag3 = 0;
        a_hi3 = a_all2 >> 8;
        x3 = 0x0400;
        y3 = y_ret2;
        carry3 = carry_ret2;
        overflow3 = overflow_ret2;
    } else {
        bool m_flag2;
        bool x_flag2;
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        bool carry2;
        bool overflow2;
        if (value & 0x80) {
            m_flag2 = 1;
            x_flag2 = 0;
            a_hi2 = a_all2 >> 8;
            x2 = 0x0400;
            y2 = y_ret2;
            carry2 = carry_ret2;
            overflow2 = overflow_ret2;
        } else {
            uint8_t value2 = BUS8(c, (db_ret2 << 0x10) + 0xE42C);
            bool m_flag;
            bool x_flag;
            uint8_t a_hi1;
            uint16_t x1;
            uint16_t y1;
            bool carry1;
            bool overflow1;
            if (value2 != 0) {
                m_flag = 1;
                x_flag = 0;
                a_hi1 = a_all2 >> 8;
                x1 = 0x0400;
                y1 = y_ret2;
                carry1 = carry_ret2;
                overflow1 = overflow_ret2;
            } else {
                uint8_t value3 = BUS8(c, (db_ret2 << 0x10) + 0xE580);
                r->a = (a_all2 >> 8 << 8) | value3;
                r->x = 0x0400;
                r->z = value3 == 0;
                r->n = value3 & 0x80;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSL(c, 0xDE25, 0xC10020); GUARD_JSL(c, sp_call, 0xDE25); } /* set_actor_program_long */
                bool m_ret3 = r->mf;
                bool x_ret3 = r->xf;
                uint16_t a_all3 = r->a;
                uint16_t x_ret4 = r->x;
                uint16_t y_ret3 = r->y;
                bool carry_ret3 = r->c;
                bool overflow_ret3 = r->v;
                m_flag = m_ret3;
                x_flag = x_ret3;
                a_hi1 = a_all3 >> 8;
                x1 = x_ret4;
                y1 = y_ret3;
                carry1 = carry_ret3;
                overflow1 = overflow_ret3;
            }
            m_flag2 = m_flag;
            x_flag2 = x_flag;
            a_hi2 = a_hi1;
            x2 = x1;
            y2 = y1;
            carry2 = carry1;
            overflow2 = overflow1;
        }
        m_flag3 = m_flag2;
        x_flag3 = x_flag2;
        a_hi3 = a_hi2;
        x3 = x2;
        y3 = y2;
        carry3 = carry2;
        overflow3 = overflow2;
    }
    r->a = (a_hi3 << 8) | a;
    r->x = x3;
    r->y = y3;
    r->c = carry3;
    r->v = overflow3;
    r->mf = m_flag3;
    r->xf = x_flag3;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1DE00, SOM_RTS, "gen", start_uncontrolled_party_programs, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 39, 15)

/* C1DE11 start_uncontrolled_actor_program   [class A, 22 bytes, 9 instructions]
 * Source: src/rom/start_uncontrolled_party_programs.s
 * Subroutine of start_uncontrolled_party_programs, translated in place.
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void start_uncontrolled_actor_program(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xE000 + x);
    bool m_flag3;
    bool x_flag3;
    uint8_t a3;
    uint8_t a_hi3;
    uint16_t x3;
    uint16_t y3;
    bool carry3;
    bool zero3;
    bool negative3;
    bool overflow3;
    if (value == 0) {
        m_flag3 = 1;
        x_flag3 = 0;
        a3 = value;
        a_hi3 = a_hi;
        x3 = x;
        y3 = y;
        carry3 = carry;
        zero3 = value == 0;
        negative3 = value & 0x80;
        overflow3 = overflow;
    } else {
        bool m_flag2;
        bool x_flag2;
        uint8_t a2;
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        bool carry2;
        bool zero2;
        bool negative2;
        bool overflow2;
        if (value & 0x80) {
            m_flag2 = 1;
            x_flag2 = 0;
            a2 = value;
            a_hi2 = a_hi;
            x2 = x;
            y2 = y;
            carry2 = carry;
            zero2 = value == 0;
            negative2 = value & 0x80;
            overflow2 = overflow;
        } else {
            uint8_t value2 = RAM8(0xE02C + x);
            bool m_flag;
            bool x_flag;
            uint8_t a1;
            uint8_t a_hi1;
            uint16_t x1;
            uint16_t y1;
            bool carry1;
            bool zero1;
            bool negative1;
            bool overflow1;
            if (value2 != 0) {
                m_flag = 1;
                x_flag = 0;
                a1 = value2;
                a_hi1 = a_hi;
                x1 = x;
                y1 = y;
                carry1 = carry;
                zero1 = value2 == 0;
                negative1 = value2 & 0x80;
                overflow1 = overflow;
            } else {
                uint8_t value3 = RAM8(0xE180 + x);
                r->a = (a_hi << 8) | value3;
                r->z = value3 == 0;
                r->n = value3 & 0x80;
                { const uint16_t sp_call = r->sp; JSL(c, 0xDE25, 0xC10020); GUARD_JSL(c, sp_call, 0xDE25); } /* set_actor_program_long */
                bool m_ret = r->mf;
                bool x_ret = r->xf;
                uint16_t a_all = r->a;
                uint16_t x_ret2 = r->x;
                uint16_t y_ret = r->y;
                bool carry_ret = r->c;
                bool zero_ret = r->z;
                bool negative_ret = r->n;
                bool overflow_ret = r->v;
                m_flag = m_ret;
                x_flag = x_ret;
                a1 = (uint8_t)a_all;
                a_hi1 = a_all >> 8;
                x1 = x_ret2;
                y1 = y_ret;
                carry1 = carry_ret;
                zero1 = zero_ret;
                negative1 = negative_ret;
                overflow1 = overflow_ret;
            }
            m_flag2 = m_flag;
            x_flag2 = x_flag;
            a2 = a1;
            a_hi2 = a_hi1;
            x2 = x1;
            y2 = y1;
            carry2 = carry1;
            zero2 = zero1;
            negative2 = negative1;
            overflow2 = overflow1;
        }
        m_flag3 = m_flag2;
        x_flag3 = x_flag2;
        a3 = a2;
        a_hi3 = a_hi2;
        x3 = x2;
        y3 = y2;
        carry3 = carry2;
        zero3 = zero2;
        negative3 = negative2;
        overflow3 = overflow2;
    }
    r->a = (a_hi3 << 8) | a3;
    r->x = x3;
    r->y = y3;
    r->c = carry3;
    r->z = zero3;
    r->n = negative3;
    r->v = overflow3;
    r->mf = m_flag3;
    r->xf = x_flag3;
    RETURN_RTS(c);
}

/* C1DE11 start_uncontrolled_actor_program_v2   [class A, 22 bytes, 9 instructions]
 * Source: src/rom/start_uncontrolled_party_programs.s
 * Subroutine of start_uncontrolled_party_programs, translated in place.
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void start_uncontrolled_actor_program_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t value = BUS8(c, (db << 0x10) + 0xE000 + x);
    bool m_flag3;
    bool x_flag3;
    uint8_t a3;
    uint8_t a_hi3;
    uint16_t x3;
    uint16_t y3;
    bool carry3;
    bool zero3;
    bool negative3;
    bool overflow3;
    if (value == 0) {
        m_flag3 = 1;
        x_flag3 = 0;
        a3 = value;
        a_hi3 = a_hi;
        x3 = x;
        y3 = y;
        carry3 = carry;
        zero3 = value == 0;
        negative3 = value & 0x80;
        overflow3 = overflow;
    } else {
        bool m_flag2;
        bool x_flag2;
        uint8_t a2;
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        bool carry2;
        bool zero2;
        bool negative2;
        bool overflow2;
        if (value & 0x80) {
            m_flag2 = 1;
            x_flag2 = 0;
            a2 = value;
            a_hi2 = a_hi;
            x2 = x;
            y2 = y;
            carry2 = carry;
            zero2 = value == 0;
            negative2 = value & 0x80;
            overflow2 = overflow;
        } else {
            uint8_t value2 = BUS8(c, (db << 0x10) + 0xE02C + x);
            bool m_flag;
            bool x_flag;
            uint8_t a1;
            uint8_t a_hi1;
            uint16_t x1;
            uint16_t y1;
            bool carry1;
            bool zero1;
            bool negative1;
            bool overflow1;
            if (value2 != 0) {
                m_flag = 1;
                x_flag = 0;
                a1 = value2;
                a_hi1 = a_hi;
                x1 = x;
                y1 = y;
                carry1 = carry;
                zero1 = value2 == 0;
                negative1 = value2 & 0x80;
                overflow1 = overflow;
            } else {
                uint8_t value3 = BUS8(c, (db << 0x10) + 0xE180 + x);
                r->a = (a_hi << 8) | value3;
                r->z = value3 == 0;
                r->n = value3 & 0x80;
                { const uint16_t sp_call = r->sp; JSL(c, 0xDE25, 0xC10020); GUARD_JSL(c, sp_call, 0xDE25); } /* set_actor_program_long */
                bool m_ret = r->mf;
                bool x_ret = r->xf;
                uint16_t a_all = r->a;
                uint16_t x_ret2 = r->x;
                uint16_t y_ret = r->y;
                bool carry_ret = r->c;
                bool zero_ret = r->z;
                bool negative_ret = r->n;
                bool overflow_ret = r->v;
                m_flag = m_ret;
                x_flag = x_ret;
                a1 = (uint8_t)a_all;
                a_hi1 = a_all >> 8;
                x1 = x_ret2;
                y1 = y_ret;
                carry1 = carry_ret;
                zero1 = zero_ret;
                negative1 = negative_ret;
                overflow1 = overflow_ret;
            }
            m_flag2 = m_flag;
            x_flag2 = x_flag;
            a2 = a1;
            a_hi2 = a_hi1;
            x2 = x1;
            y2 = y1;
            carry2 = carry1;
            zero2 = zero1;
            negative2 = negative1;
            overflow2 = overflow1;
        }
        m_flag3 = m_flag2;
        x_flag3 = x_flag2;
        a3 = a2;
        a_hi3 = a_hi2;
        x3 = x2;
        y3 = y2;
        carry3 = carry2;
        zero3 = zero2;
        negative3 = negative2;
        overflow3 = overflow2;
    }
    r->a = (a_hi3 << 8) | a3;
    r->x = x3;
    r->y = y3;
    r->c = carry3;
    r->z = zero3;
    r->n = negative3;
    r->v = overflow3;
    r->mf = m_flag3;
    r->xf = x_flag3;
    RETURN_RTS(c);
}
