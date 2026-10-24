#include "som_c.h"

/* C1054A test_actor_target_eligibility   [class B, 52 bytes, 25 instructions]
 * Source: src/rom/test_actor_target_eligibility.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void test_actor_target_eligibility(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x0000 + x);
    bool x_flag3;
    uint8_t a5;
    uint8_t a_hi4;
    bool carry3;
    bool zero5;
    bool negative5;
    bool overflow3;
    uint16_t direct_page3;
    if (value != 1) {
        x_flag3 = 0;
        a5 = value;
        a_hi4 = a_hi;
        carry3 = value >= 1;
        zero5 = value == 1;
        negative5 = (uint8_t)(value - 1) & 0x80;
        overflow3 = overflow;
        direct_page3 = dp;
    } else {
        RAM8(0x0000 + sp0) = x >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
        uint16_t value2 = RAM16(0x0000 + sp0 - 1);
        bool x_flag2;
        uint8_t a4;
        uint8_t a_hi3;
        bool carry2;
        bool zero4;
        bool negative4;
        bool overflow2;
        uint16_t direct_page2;
        if (y == value2) {
            x_flag2 = 0;
            a4 = (uint8_t)y | 0xFF;
            a_hi3 = y >> 8;
            carry2 = y >= value2;
            zero4 = ((uint8_t)y | 0xFF) == 0;
            negative4 = ((uint8_t)y | 0xFF) & 0x80;
            overflow2 = overflow;
            direct_page2 = dp;
        } else {
            uint16_t value3 = RAM16(0x0020 + x);
            bool x_flag;
            uint8_t a3;
            uint8_t a_hi2;
            bool carry1;
            bool zero3;
            bool negative3;
            bool overflow1;
            uint16_t direct_page;
            if (value3 >= 0x0100) {
                x_flag = 0;
                a3 = (uint8_t)value3 | 0xFF;
                a_hi2 = value3 >> 8;
                carry1 = value3 >= 0x0100;
                zero3 = ((uint8_t)value3 | 0xFF) == 0;
                negative3 = ((uint8_t)value3 | 0xFF) & 0x80;
                overflow1 = overflow;
                direct_page = dp;
            } else {
                r->a = value3;
                r->c = value3 >= 0x0100;
                r->z = value3 == 0x0100;
                r->n = (uint16_t)(value3 - 0x0100) & 0x8000;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x0564, 0xC10343); GUARD_JSR(c, sp_call, 0x0564); } /* read_actor_y_minus_height_x */
                uint16_t dp_ret = r->dp;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret = r->xf;
                uint16_t a_all = r->a;
                bool overflow_ret = r->v;
                uint8_t a2;
                uint8_t a_hi1;
                bool zero2;
                bool negative2;
                if (a_all >= 0xE0) {
                    a2 = (uint8_t)a_all | 0xFF;
                    a_hi1 = a_all >> 8;
                    zero2 = ((uint8_t)a_all | 0xFF) == 0;
                    negative2 = ((uint8_t)a_all | 0xFF) & 0x80;
                } else {
                    uint16_t value4 = RAM16(0x0190 + x);
                    uint8_t a1;
                    bool zero1;
                    bool negative1;
                    if ((value4 & 0x8460) != 0) {
                        a1 = (uint8_t)(value4 & 0x8460) | 0xFF;
                        zero1 = ((uint8_t)(value4 & 0x8460) | 0xFF) == 0;
                        negative1 = ((uint8_t)(value4 & 0x8460) | 0xFF) & 0x80;
                    } else {
                        a1 = 0;
                        zero1 = 1;
                        negative1 = 0;
                    }
                    a2 = a1;
                    a_hi1 = (value4 & 0x8460) >> 8;
                    zero2 = zero1;
                    negative2 = negative1;
                }
                x_flag = x_ret;
                a3 = a2;
                a_hi2 = a_hi1;
                carry1 = a_all >= 0xE0;
                zero3 = zero2;
                negative3 = negative2;
                overflow1 = overflow_ret;
                direct_page = dp_ret;
            }
            x_flag2 = x_flag;
            a4 = a3;
            a_hi3 = a_hi2;
            carry2 = carry1;
            zero4 = zero3;
            negative4 = negative3;
            overflow2 = overflow1;
            direct_page2 = direct_page;
        }
        x_flag3 = x_flag2;
        a5 = a4;
        a_hi4 = a_hi3;
        carry3 = carry2;
        zero5 = zero4;
        negative5 = negative4;
        overflow3 = overflow2;
        direct_page3 = direct_page2;
    }
    r->a = (a_hi4 << 8) | a5;
    r->c = carry3;
    r->z = zero5;
    r->n = negative5;
    r->v = overflow3;
    r->mf = 1;
    r->xf = x_flag3;
    r->dp = direct_page3;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1054A, SOM_RTS, "gen", test_actor_target_eligibility, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 52, 25)
