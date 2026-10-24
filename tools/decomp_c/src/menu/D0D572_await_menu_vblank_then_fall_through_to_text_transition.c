#include "som_c.h"

/* D0D572 await_menu_vblank_then_fall_through_to_text_transition   [class C, 95 bytes, 38 instructions]
 * Source: src/rom/await_menu_vblank_then_fall_through_to_text_transition.s
 * Documented in docs/event-menu-vblank.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void await_menu_vblank_then_fall_through_to_text_transition(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t a1 = a;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool zero1 = zero;
    bool negative1 = negative;
    bool overflow1 = overflow;
    for (;;) {
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = db;
        r->dp = dp;
        JSL(c, 0xD575, 0xC0693F); /* wait_menu_vblank_through_native_long_wrapper */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        uint8_t value = BUS8(c, (db << 0x10) + 0x1847);
        uint8_t a5;
        uint8_t a_hi5;
        uint16_t x5;
        uint16_t y5;
        bool carry5;
        bool zero5;
        bool negative5;
        bool overflow5;
        if (value != 0) {
            r->a = 0xD0;
            r->x = 0xD5D1;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0xD5B7, 0xD0D5D7); /* set_native_menu_dialogue_script_and_close_prior_window */
            BUS8_SET(c, (db << 0x10) + 0x1D13, 0);
            r->mf = 1;
            r->xf = 0;
            JSL(c, 0xD5C0, 0xC00092); /* run_native_dialogue_public_jump */
            uint16_t a_all3 = r->a;
            uint16_t x_ret3 = r->x;
            uint16_t y_ret2 = r->y;
            bool carry_ret3 = r->c;
            bool zero_ret3 = r->z;
            bool negative_ret3 = r->n;
            bool overflow_ret3 = r->v;
            uint8_t a2 = (uint8_t)a_all3;
            uint8_t a_hi2 = a_all3 >> 8;
            uint16_t x2 = x_ret3;
            uint16_t y2 = y_ret2;
            bool carry2 = carry_ret3;
            bool zero2 = zero_ret3;
            bool negative2 = negative_ret3;
            bool overflow2 = overflow_ret3;
            for (;;) {
                r->a = (a_hi2 << 8) | a2;
                r->x = x2;
                r->y = y2;
                r->c = carry2;
                r->z = zero2;
                r->n = negative2;
                r->v = overflow2;
                r->mf = 1;
                r->xf = 0;
                r->db = db;
                r->dp = dp;
                JSL(c, 0xD5C4, 0xC0693F); /* wait_menu_vblank_through_native_long_wrapper */
                uint16_t a_all4 = r->a;
                uint16_t x_ret4 = r->x;
                uint16_t y_ret3 = r->y;
                bool carry_ret4 = r->c;
                uint8_t value2 = BUS8(c, (db << 0x10) + 0x1D04);
                a2 = 1;
                a_hi2 = a_all4 >> 8;
                x2 = x_ret4;
                y2 = y_ret3;
                carry2 = carry_ret4;
                zero2 = (value2 & 1) == 0;
                negative2 = value2 & 0x80;
                overflow2 = value2 & 0x40;
                if (!((value2 & a2) != 0)) break;
            }
            a5 = a2;
            a_hi5 = a_hi2;
            x5 = x2;
            y5 = y2;
            carry5 = carry2;
            zero5 = zero2;
            negative5 = negative2;
            overflow5 = overflow2;
        } else {
            uint8_t value3 = BUS8(c, (db << 0x10) + 0x1D04);
            if ((value3 & 1) != 0) {
                a1 = value3;
                a_hi1 = a_all >> 8;
                x1 = x_ret;
                y1 = y_ret;
                carry1 = carry_ret;
                zero1 = (value3 & 1) == 0;
                negative1 = value3 & 0x80;
                overflow1 = overflow_ret;
                continue;
            }
            uint8_t value4 = BUS8(c, (db << 0x10) + 0x1D12);
            uint8_t a4;
            uint8_t a_hi4;
            uint16_t x4;
            uint16_t y4;
            bool carry4;
            bool zero4;
            bool negative4;
            bool overflow4;
            if ((value4 & 0x20) == 0) {
                r->a = 0xD0;
                r->x = 0xD5D1;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0xD5B7, 0xD0D5D7); /* set_native_menu_dialogue_script_and_close_prior_window */
                BUS8_SET(c, (db << 0x10) + 0x1D13, 0);
                r->mf = 1;
                r->xf = 0;
                JSL(c, 0xD5C0, 0xC00092); /* run_native_dialogue_public_jump */
                uint16_t a_all6 = r->a;
                uint16_t x_ret6 = r->x;
                uint16_t y_ret4 = r->y;
                bool carry_ret6 = r->c;
                bool zero_ret6 = r->z;
                bool negative_ret6 = r->n;
                bool overflow_ret6 = r->v;
                uint8_t a3 = (uint8_t)a_all6;
                uint8_t a_hi3 = a_all6 >> 8;
                uint16_t x3 = x_ret6;
                uint16_t y3 = y_ret4;
                bool carry3 = carry_ret6;
                bool zero3 = zero_ret6;
                bool negative3 = negative_ret6;
                bool overflow3 = overflow_ret6;
                for (;;) {
                    r->a = (a_hi3 << 8) | a3;
                    r->x = x3;
                    r->y = y3;
                    r->c = carry3;
                    r->z = zero3;
                    r->n = negative3;
                    r->v = overflow3;
                    r->mf = 1;
                    r->xf = 0;
                    r->db = db;
                    r->dp = dp;
                    JSL(c, 0xD5C4, 0xC0693F); /* wait_menu_vblank_through_native_long_wrapper */
                    uint16_t a_all7 = r->a;
                    uint16_t x_ret7 = r->x;
                    uint16_t y_ret5 = r->y;
                    bool carry_ret7 = r->c;
                    uint8_t value5 = BUS8(c, (db << 0x10) + 0x1D04);
                    a3 = 1;
                    a_hi3 = a_all7 >> 8;
                    x3 = x_ret7;
                    y3 = y_ret5;
                    carry3 = carry_ret7;
                    zero3 = (value5 & 1) == 0;
                    negative3 = value5 & 0x80;
                    overflow3 = value5 & 0x40;
                    if (!((value5 & a3) != 0)) break;
                }
                a4 = a3;
                a_hi4 = a_hi3;
                x4 = x3;
                y4 = y3;
                carry4 = carry3;
                zero4 = zero3;
                negative4 = negative3;
                overflow4 = overflow3;
            } else {
                uint8_t value6 = BUS8(c, (db << 0x10) + 0x1803);
                BUS8_SET(c, (db << 0x10) + 0x1803, value6 | 1);
                a4 = 1;
                a_hi4 = a_all >> 8;
                x4 = x_ret;
                y4 = y_ret;
                carry4 = carry_ret;
                zero4 = (value6 & 1) == 0;
                negative4 = 0;
                overflow4 = overflow_ret;
            }
            a5 = a4;
            a_hi5 = a_hi4;
            x5 = x4;
            y5 = y4;
            carry5 = carry4;
            zero5 = zero4;
            negative5 = negative4;
            overflow5 = overflow4;
        }
        a1 = a5;
        a_hi1 = a_hi5;
        x1 = x5;
        y1 = y5;
        carry1 = carry5;
        zero1 = zero5;
        negative1 = negative5;
        overflow1 = overflow5;
        break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = db;
    r->dp = dp;
    RETURN_RTL(c);
}
SOM_REGISTER(0xD0D572, SOM_RTL, "gen", await_menu_vblank_then_fall_through_to_text_transition, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 95, 38)
