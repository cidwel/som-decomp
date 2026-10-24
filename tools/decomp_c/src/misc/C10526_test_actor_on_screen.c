#include "som_c.h"

/* C10526 test_actor_on_screen   [class B, 36 bytes, 16 instructions]
 * Source: src/rom/test_actor_on_screen.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void test_actor_on_screen(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x0000 + x);
    bool x_flag2;
    uint8_t a3;
    uint8_t a_hi2;
    bool carry2;
    bool zero3;
    bool negative3;
    bool overflow2;
    uint16_t direct_page2;
    if (value != 1) {
        x_flag2 = 0;
        a3 = value;
        a_hi2 = a_hi;
        carry2 = value >= 1;
        zero3 = value == 1;
        negative3 = (uint8_t)(value - 1) & 0x80;
        overflow2 = overflow;
        direct_page2 = dp;
    } else {
        uint16_t value2 = RAM16(0x0020 + x);
        bool x_flag;
        uint8_t a2;
        uint8_t a_hi1;
        bool carry1;
        bool zero2;
        bool negative2;
        bool overflow1;
        uint16_t direct_page;
        if (value2 >= 0x0100) {
            x_flag = 0;
            a2 = (uint8_t)value2 | 0xFF;
            a_hi1 = value2 >> 8;
            carry1 = value2 >= 0x0100;
            zero2 = ((uint8_t)value2 | 0xFF) == 0;
            negative2 = ((uint8_t)value2 | 0xFF) & 0x80;
            overflow1 = overflow;
            direct_page = dp;
        } else {
            r->a = value2;
            r->c = value2 >= 0x0100;
            r->z = value2 == 0x0100;
            r->n = (uint16_t)(value2 - 0x0100) & 0x8000;
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0539, 0xC10343); GUARD_JSR(c, sp_call, 0x0539); } /* read_actor_y_minus_height_x */
            uint16_t dp_ret = r->dp;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret = r->xf;
            uint16_t a_all = r->a;
            bool overflow_ret = r->v;
            uint8_t a1;
            bool zero1;
            bool negative1;
            if (a_all >= 0xE0) {
                a1 = (uint8_t)a_all | 0xFF;
                zero1 = ((uint8_t)a_all | 0xFF) == 0;
                negative1 = ((uint8_t)a_all | 0xFF) & 0x80;
            } else {
                a1 = 0;
                zero1 = 1;
                negative1 = 0;
            }
            x_flag = x_ret;
            a2 = a1;
            a_hi1 = a_all >> 8;
            carry1 = a_all >= 0xE0;
            zero2 = zero1;
            negative2 = negative1;
            overflow1 = overflow_ret;
            direct_page = dp_ret;
        }
        x_flag2 = x_flag;
        a3 = a2;
        a_hi2 = a_hi1;
        carry2 = carry1;
        zero3 = zero2;
        negative3 = negative2;
        overflow2 = overflow1;
        direct_page2 = direct_page;
    }
    r->a = (a_hi2 << 8) | a3;
    r->c = carry2;
    r->z = zero3;
    r->n = negative3;
    r->v = overflow2;
    r->mf = 1;
    r->xf = x_flag2;
    r->dp = direct_page2;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC10526, SOM_RTS, "gen", test_actor_on_screen, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 36, 16)
