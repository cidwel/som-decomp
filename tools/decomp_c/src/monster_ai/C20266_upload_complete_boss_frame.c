#include "som_c.h"

/* C20266 upload_complete_boss_frame   [class D, 253 bytes, 107 instructions]
 * Source: src/rom/upload_complete_boss_frame.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: nothing.
 */
static void upload_complete_boss_frame(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x02CA);
    uint8_t a_hi2;
    uint8_t y2;
    bool carry2;
    bool overflow2;
    if (value == 0) {
        a_hi2 = 2;
        y2 = (uint8_t)y;
        carry2 = carry;
        overflow2 = overflow;
    } else {
        BUS8_SET(c, 0x004360, 1);
        BUS8_SET(c, 0x004370, 1);
        BUS8_SET(c, 0x004361, 0x18);
        BUS8_SET(c, 0x004371, 0x18);
        BUS8_SET(c, 0x004364, 0x7F);
        BUS8_SET(c, 0x004374, 0x7F);
        uint8_t a_hi1 = 2;
        uint8_t y1 = 0;
        bool carry1 = carry;
        bool overflow1 = overflow;
        for (;;) {
            BUS16_SET(c, 0x004365, 0x40);
            BUS16_SET(c, 0x004375, 0x40);
            uint16_t value2 = RAM16(0x0E7D + (uint8_t)(y1 << 1 << 1));
            BUS16_SET(c, 0x004362, value2);
            BUS16_SET(c, 0x004372, (uint16_t)(value2 + 0x0200));
            uint16_t value3 = RAM16(0x0E7F + (uint8_t)(y1 << 1 << 1));
            BUS16_SET(c, 0x002116, value3);
            BUS8_SET(c, 0x00420B, 0x40);
            BUS16_SET(c, 0x002116, (uint16_t)(value3 + 0x0100));
            BUS8_SET(c, 0x00420B, 0x80);
            uint8_t value4 = RAM8(0x02CA);
            uint8_t a_hi1_next = (uint16_t)(value3 + 0x0100) >> 8;
            uint8_t y1_next = (uint8_t)(y1 + 1);
            bool carry1_next = (uint8_t)(y1 + 1) >= value4;
            bool overflow1_next = ((value3 ^ (uint16_t)(value3 + 0x0100)) & ((uint16_t)(value3 + 0x0100) ^ 0x0100) & 0x8000) != 0;
            a_hi1 = a_hi1_next;
            y1 = y1_next;
            carry1 = carry1_next;
            overflow1 = overflow1_next;
            if (!(y1 != value4)) break;
        }
        a_hi2 = a_hi1;
        y2 = y1;
        carry2 = carry1;
        overflow2 = overflow1;
    }
    uint16_t value5 = RAM16(0x0FAE);
    uint8_t a4;
    uint8_t a_hi6;
    uint8_t y6;
    bool carry6;
    bool overflow6;
    if (value5 == 0) {
        a4 = (uint8_t)value5;
        a_hi6 = value5 >> 8;
        y6 = y2;
        carry6 = carry2;
        overflow6 = overflow2;
    } else {
        uint8_t a3;
        uint8_t a_hi5;
        uint8_t y5;
        bool carry5;
        bool overflow5;
        if ((value5 & 2) != 0) {
            r->xf = 1;
            r->dp = 0x0200;
            r->sp -= 4;
            JSR(c, 0x02EB, 0xC20439); /* upload_boss_mode7_matrix_and_tile_rows */
            r->sp += 4;
            uint16_t a_all = r->a;
            uint8_t y_ret = r->y;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            a3 = (uint8_t)a_all;
            a_hi5 = a_all >> 8;
            y5 = y_ret;
            carry5 = carry_ret;
            overflow5 = overflow_ret;
        } else {
            uint16_t value6 = RAM16(0x0FBE);
            uint8_t a2;
            uint8_t a_hi4;
            uint8_t y4;
            bool carry4;
            bool overflow4;
            if ((uint16_t)(value6 + 0x0120) & 0x8000) {
                a2 = (uint8_t)(value6 + 0x0120);
                a_hi4 = (uint16_t)(value6 + 0x0120) >> 8;
                y4 = y2;
                carry4 = value6 + 0x0120 > 0xFFFF;
                overflow4 = ((value6 ^ (uint16_t)(value6 + 0x0120)) & ((uint16_t)(value6 + 0x0120) ^ 0x0120) & 0x8000) != 0;
            } else {
                uint8_t a1;
                uint8_t a_hi3;
                uint8_t y3;
                bool carry3;
                bool overflow3;
                if (!((uint16_t)((uint16_t)(value6 + 0x0120) - 0x01C0) & 0x8000)) {
                    a1 = (uint8_t)((uint16_t)(value6 + 0x0120) - 0x01C0);
                    a_hi3 = (uint16_t)((uint16_t)(value6 + 0x0120) - 0x01C0) >> 8;
                    y3 = y2;
                    carry3 = (uint16_t)(value6 + 0x0120) >= 0x01C0;
                    overflow3 = (((uint16_t)(value6 + 0x0120) ^ 0x01C0) & ((uint16_t)(value6 + 0x0120) ^ (uint16_t)((uint16_t)(value6 + 0x0120) - 0x01C0)) & 0x8000) != 0;
                } else {
                    r->xf = 1;
                    r->dp = 0x0200;
                    r->sp -= 4;
                    JSR(c, 0x02E6, 0xC203D1); /* upload_boss_sixteen_tile_rows */
                    r->sp += 4;
                    uint16_t a_all2 = r->a;
                    uint8_t y_ret2 = r->y;
                    bool carry_ret2 = r->c;
                    bool overflow_ret2 = r->v;
                    a1 = (uint8_t)a_all2;
                    a_hi3 = a_all2 >> 8;
                    y3 = y_ret2;
                    carry3 = carry_ret2;
                    overflow3 = overflow_ret2;
                }
                a2 = a1;
                a_hi4 = a_hi3;
                y4 = y3;
                carry4 = carry3;
                overflow4 = overflow3;
            }
            a3 = a2;
            a_hi5 = a_hi4;
            y5 = y4;
            carry5 = carry4;
            overflow5 = overflow4;
        }
        RAM16_SET(0x0FAE, 0);
        a4 = a3;
        a_hi6 = a_hi5;
        y6 = y5;
        carry6 = carry5;
        overflow6 = overflow5;
    }
    uint8_t value7 = RAM8(0x0352);
    uint8_t a5;
    uint8_t a_hi7;
    if (value7 == 0) {
        a5 = a4;
        a_hi7 = a_hi6;
    } else {
        BUS8_SET(c, 0x004370, 0);
        BUS8_SET(c, 0x004371, 0x19);
        BUS8_SET(c, 0x004374, 0x7F);
        BUS16_SET(c, 0x004375, 0x0800);
        BUS16_SET(c, 0x004372, RAM16(0x0353));
        uint16_t value9 = RAM16(0x0355);
        BUS16_SET(c, 0x002116, value9);
        BUS8_SET(c, 0x00420B, 0x80);
        RAM8(0x0352) = 0;
        a5 = (uint8_t)value9;
        a_hi7 = value9 >> 8;
    }
    uint8_t value10 = RAM8(0x0351);
    uint8_t a7;
    uint8_t a_hi9;
    if (value10 == 0) {
        a7 = a5;
        a_hi9 = a_hi7;
    } else {
        uint16_t value11 = RAM16(0x1D04);
        uint8_t a6;
        uint8_t a_hi8;
        if ((value11 & 0x40) != 0) {
            a6 = (uint8_t)value11;
            a_hi8 = value11 >> 8;
        } else {
            BUS8_SET(c, 0x004370, 1);
            BUS8_SET(c, 0x004371, 0x18);
            BUS8_SET(c, 0x004374, 0x7F);
            BUS16_SET(c, 0x004375, 0x0800);
            BUS16_SET(c, 0x004372, 0x6000);
            BUS16_SET(c, 0x002116, 0x6200);
            BUS8_SET(c, 0x00420B, 0x80);
            RAM8(0x0351) = 0;
            a6 = 0;
            a_hi8 = 0x62;
        }
        a7 = a6;
        a_hi9 = a_hi8;
    }
    BUS8_SET(c, 0x004370, 1);
    r->a = (a_hi9 << 8) | a7;
    r->x = 1;
    r->y = y6;
    r->c = carry6;
    r->v = overflow6;
    r->mf = 0;
    r->xf = 1;
    r->dp = 0x0200;
    r->sp -= 4;
    JSR(c, 0x035E, 0xC2300B); /* draw_boss_frame_random_number */
    r->sp += 4;
    r->mf = 0;
    r->xf = 0;
    r->dp = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC20266, SOM_RTL, "gen", upload_complete_boss_frame, 0, 0, 5, 0, 0, 253, 107)
