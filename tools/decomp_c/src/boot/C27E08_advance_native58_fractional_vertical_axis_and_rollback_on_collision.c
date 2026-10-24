#include "som_c.h"

/* C27E08 advance_native58_fractional_vertical_axis_and_rollback_on_collision   [class B, 49 bytes, 19 instructions]
 * Source: src/rom/advance_native58_fractional_vertical_axis_and_rollback_on_collision.s
 * Documented in docs/boss-native58-setup.md
 * Entry: M=any X=16 bit DB=$7E D=$0200.  Callers read: BYV.
 * The code is width-agnostic (the adds and subtracts follow the accumulator width); the real caller runs it at M=16, where the
 * callee C215B7 (`AND #$00FF`, `LDA #$7F00`) works in range.
 */
static void advance_native58_fractional_vertical_axis_and_rollback_on_collision(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    uint8_t a_hi_7e25 = 0;
    uint16_t x_7e25 = 0;
    uint16_t y_7e25 = 0;
    uint8_t a_hi_7e252 = 0;
    uint16_t x_7e252 = 0;
    uint16_t y_7e252 = 0;
    uint8_t a_hi_7e38 = 0;
    uint16_t y_7e38 = 0;
    bool overflow_7e38 = 0;
    uint8_t a_hi_7e382 = 0;
    uint16_t y_7e382 = 0;
    bool overflow_7e382 = 0;
    if (r->mf) {
        uint8_t value = RAM8(0x0030 + x);
        uint8_t value2 = RAM8(0x003E + x);
        RAM8(0x0030 + x) = (uint8_t)(value + value2);
        uint8_t value3 = RAM8(0x0032 + x);
        uint8_t value4 = RAM8(0x0040 + x);
        const uint8_t sum_hi = (uint8_t)(value3 + value4 + (value + value2 > 0xFF));
        RAM8(0x0032 + x) = sum_hi;
        r->a = (a_hi << 8) | sum_hi;
        r->v = ((value3 ^ sum_hi) & (value4 ^ sum_hi) & 0x80) != 0;
    } else {
        /* same code at M=16: the two adds are 16-bit (a 32-bit position in two words) */
        uint16_t value = RAM16(0x0030 + x);
        uint16_t value2 = RAM16(0x003E + x);
        RAM16_SET(0x0030 + x, (uint16_t)(value + value2));
        uint16_t value3 = RAM16(0x0032 + x);
        uint16_t value4 = RAM16(0x0040 + x);
        const uint16_t sum_hi = (uint16_t)(value3 + value4 + ((uint32_t)value + value2 > 0xFFFF));
        RAM16_SET(0x0032 + x, sum_hi);
        r->a = sum_hi;
        r->v = ((value3 ^ sum_hi) & (value4 ^ sum_hi) & 0x8000) != 0;
    }
    { const uint16_t sp_call = r->sp; JSR(c, 0x7E1D, 0xC215B7); GUARD_JSR(c, sp_call, 0x7E1D); } /* prepare_boss_object_terrain */
    bool m_ret = r->mf;
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    if (carry_ret) {
        if (m_ret) {
            a_hi_7e25 = a_all >> 8;
            x_7e25 = x_ret;
            y_7e25 = y_ret;
            goto shared_7E25;
        } else {
            a_hi_7e252 = a_all >> 8;
            x_7e252 = x_ret;
            y_7e252 = y_ret;
            goto shared_7E25_1;
        }
    }
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7E22, 0xC27E39); GUARD_JSR(c, sp_call, 0x7E22); } /* scan_native58_party_collision_and_mark_party_action_bytes */
    bool m_ret2 = r->mf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    if (!carry_ret2) {
        if (m_ret2) {
            a_hi_7e38 = a_all2 >> 8;
            y_7e38 = y_ret2;
            overflow_7e38 = overflow_ret2;
            goto shared_7E38;
        } else {
            a_hi_7e382 = a_all2 >> 8;
            y_7e382 = y_ret2;
            overflow_7e382 = overflow_ret2;
            goto shared_7E38_1;
        }
    }
    if (m_ret2) {
        a_hi_7e25 = a_all2 >> 8;
        x_7e25 = x_ret2;
        y_7e25 = y_ret2;
        goto shared_7E25;
    } else {
        a_hi_7e252 = a_all2 >> 8;
        x_7e252 = x_ret2;
        y_7e252 = y_ret2;
        goto shared_7E25_1;
    }
    shared_7E25:;
    uint8_t value5 = RAM8(0x0030 + x_7e25);
    uint8_t value6 = RAM8(0x003E + x_7e25);
    RAM8(0x0030 + x_7e25) = (uint8_t)(value5 - value6);
    uint8_t value7 = RAM8(0x0032 + x_7e25);
    uint8_t value8 = RAM8(0x0040 + x_7e25);
    RAM8(0x0032 + x_7e25) = (uint8_t)(value7 - value8 - (value5 >= value6 ^ 1));
    a_hi_7e38 = a_hi_7e25;
    y_7e38 = y_7e25;
    overflow_7e38 = ((value7 ^ value8) & (value7 ^ (uint8_t)(value7 - value8 - (value5 >= value6 ^ 1))) & 0x80) != 0;
    goto shared_7E38;
    shared_7E25_1:;
    uint16_t value9 = RAM16(0x0030 + x_7e252);
    uint16_t value10 = RAM16(0x003E + x_7e252);
    RAM16_SET(0x0030 + x_7e252, (uint16_t)(value9 - value10));
    uint16_t value11 = RAM16(0x0032 + x_7e252);
    uint16_t value12 = RAM16(0x0040 + x_7e252);
    RAM16_SET(0x0032 + x_7e252, (uint16_t)(value11 - value12 - (value9 >= value10 ^ 1)));
    a_hi_7e382 = (uint16_t)(value11 - value12 - (value9 >= value10 ^ 1)) >> 8;
    y_7e382 = y_7e252;
    overflow_7e382 = ((value11 ^ value12) & (value11 ^ (uint16_t)(value11 - value12 - (value9 >= value10 ^ 1))) & 0x8000) != 0;
    goto shared_7E38_1;
    shared_7E38:;
    r->a = (a_hi_7e38 << 8) | a;
    r->y = y_7e38;
    r->v = overflow_7e38;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
    shared_7E38_1:;
    r->a = (a_hi_7e382 << 8) | a;
    r->y = y_7e382;
    r->v = overflow_7e382;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27E08, SOM_RTS, "hand", advance_native58_fractional_vertical_axis_and_rollback_on_collision, 0, L_B | L_Y | L_V, 1, -1, 0, 49, 19)
