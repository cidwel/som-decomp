#include "som_c.h"

/* C1E339 write_party_hud_numbers   [class D, 48 bytes, 19 instructions]
 * Source: src/rom/write_party_hud_numbers.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void write_party_hud_numbers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t event_flag_bytes = RAM8(EVENT_FLAG_BYTES);
    if (event_flag_bytes != 0) {
        BUS8_SET(c, 0x002115, 0);
        uint8_t value = RAM8(0x0A55);
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool carry1;
        bool overflow1;
        if (value == 0) {
            a_hi1 = a_hi;
            x1 = x;
            y1 = y;
            carry1 = carry;
            overflow1 = overflow;
        } else {
            r->a = (a_hi << 8) | value;
            r->x = 0;
            r->z = 1;
            r->n = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xE351, 0xC1E369); GUARD_JSR(c, sp_call, 0xE351); } /* write_actor_hud_hp */
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all = r->a;
            uint16_t y_ret = r->y;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            a_hi1 = a_all >> 8;
            x1 = 0;
            y1 = y_ret;
            carry1 = carry_ret;
            overflow1 = overflow_ret;
        }
        uint8_t value2 = RAM8(0x0A65);
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        bool carry2;
        bool overflow2;
        if (value2 == 0) {
            a_hi2 = a_hi1;
            x2 = x1;
            y2 = y1;
            carry2 = carry1;
            overflow2 = overflow1;
        } else {
            r->a = (a_hi1 << 8) | value2;
            r->x = 0x0200;
            r->y = y1;
            r->c = carry1;
            r->z = 0;
            r->n = 0;
            r->v = overflow1;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xE35C, 0xC1E369); GUARD_JSR(c, sp_call, 0xE35C); } /* write_actor_hud_hp */
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all2 = r->a;
            uint16_t y_ret2 = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            a_hi2 = a_all2 >> 8;
            x2 = 0x0200;
            y2 = y_ret2;
            carry2 = carry_ret2;
            overflow2 = overflow_ret2;
        }
        uint8_t value3 = RAM8(0x0A75);
        bool x_flag;
        uint8_t a1;
        uint8_t a_hi3;
        uint16_t x3;
        uint16_t y3;
        bool carry3;
        bool zero1;
        bool negative1;
        bool overflow3;
        if (value3 == 0) {
            x_flag = 0;
            a1 = value3;
            a_hi3 = a_hi2;
            x3 = x2;
            y3 = y2;
            carry3 = carry2;
            zero1 = value3 == 0;
            negative1 = value3 & 0x80;
            overflow3 = overflow2;
        } else {
            r->a = (a_hi2 << 8) | value3;
            r->x = 0x0400;
            r->y = y2;
            r->c = carry2;
            r->z = 0;
            r->n = 0;
            r->v = overflow2;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xE367, 0xC1E369); GUARD_JSR(c, sp_call, 0xE367); } /* write_actor_hud_hp */
            bool x_ret = r->xf;
            uint16_t a_all3 = r->a;
            uint16_t y_ret3 = r->y;
            bool carry_ret3 = r->c;
            bool zero_ret3 = r->z;
            bool negative_ret3 = r->n;
            bool overflow_ret3 = r->v;
            x_flag = x_ret;
            a1 = (uint8_t)a_all3;
            a_hi3 = a_all3 >> 8;
            x3 = 0x0400;
            y3 = y_ret3;
            carry3 = carry_ret3;
            zero1 = zero_ret3;
            negative1 = negative_ret3;
            overflow3 = overflow_ret3;
        }
        r->a = (a_hi3 << 8) | a1;
        r->x = x3;
        r->y = y3;
        r->c = carry3;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow3;
        r->mf = 1;
        r->xf = x_flag;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    SET_A8(r, event_flag_bytes);
    r->z = event_flag_bytes == 0;
    r->n = event_flag_bytes & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E339, SOM_RTS, "gen", write_party_hud_numbers, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 48, 19)
