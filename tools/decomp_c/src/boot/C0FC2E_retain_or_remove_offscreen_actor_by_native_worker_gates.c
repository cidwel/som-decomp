#include "som_c.h"

/* C0FC2E retain_or_remove_offscreen_actor_by_native_worker_gates   [class B, 94 bytes, 43 instructions]
 * Source: src/rom/retain_or_remove_offscreen_actor_by_native_worker_gates.s
 * Documented in docs/actor-charge-worker-offscreen.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void retain_or_remove_offscreen_actor_by_native_worker_gates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi_fc4e = 0;
    uint16_t x_fc4e = 0;
    uint16_t y_fc4e = 0;
    bool carry_fc4e = 0;
    bool overflow_fc4e = 0;
    uint8_t a_hi_fc4f = 0;
    uint16_t x_fc4f = 0;
    uint16_t y_fc4f = 0;
    bool overflow_fc4f = 0;
    uint8_t a_hi_fc5e = 0;
    uint16_t x_fc5e = 0;
    uint16_t y_fc5e = 0;
    bool carry_fc5e = 0;
    bool overflow_fc5e = 0;
    if ((RAM8(0xE044 + x) & 0x40) != 0) {
        a_hi_fc4e = a_hi;
        x_fc4e = x;
        y_fc4e = y;
        carry_fc4e = carry;
        overflow_fc4e = overflow;
        goto shared_FC4E;
    }
    if (RAM8(0x00D0) != 0) {
        a_hi_fc4e = a_hi;
        x_fc4e = x;
        y_fc4e = y;
        carry_fc4e = carry;
        overflow_fc4e = overflow;
        goto shared_FC4E;
    }
    uint16_t value3 = RAM16(0x003A);
    if (x == value3) {
        a_hi_fc4e = a_hi;
        x_fc4e = x;
        y_fc4e = y;
        carry_fc4e = x >= value3;
        overflow_fc4e = overflow;
        goto shared_FC4E;
    }
    uint8_t value4 = RAM8(0x00BC);
    uint8_t value5 = RAM8(0x00ED);
    if (!(value5 & 0x80)) {
        if (value4 >= 0x0A) {
            a_hi_fc4f = a_hi;
            x_fc4f = x;
            y_fc4f = y;
            overflow_fc4f = value5 & 0x40;
            goto shared_FC4F;
        }
        a_hi_fc4e = a_hi;
        x_fc4e = x;
        y_fc4e = y;
        carry_fc4e = value4 >= 0x0A;
        overflow_fc4e = value5 & 0x40;
        goto shared_FC4E;
    }
    if (value4 >= 4) {
        a_hi_fc4f = a_hi;
        x_fc4f = x;
        y_fc4f = y;
        overflow_fc4f = value5 & 0x40;
        goto shared_FC4F;
    }
    r->c = value4 >= 4;
    r->v = value5 & 0x40;
    RETURN_RTS(c);
    shared_FC4E:;
    r->a = (a_hi_fc4e << 8) | a;
    r->x = x_fc4e;
    r->y = y_fc4e;
    r->c = carry_fc4e;
    r->v = overflow_fc4e;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_FC4F:;
    RAM8(0xE043 + x_fc4f) = 0;
    uint16_t value6 = RAM16(0xE020 + x_fc4f);
    if (value6 & 0x8000) {
        if (value6 < 0xFFC0) {
            a_hi_fc5e = value6 >> 8;
            x_fc5e = x_fc4f;
            y_fc5e = y_fc4f;
            carry_fc5e = value6 >= 0xFFC0;
            overflow_fc5e = overflow_fc4f;
            goto shared_FC5E;
        }
        uint16_t value7 = RAM16(0xE022 + x_fc4f);
        if (value7 & 0x8000) {
            if (value7 < 0xFFC0) {
                a_hi_fc5e = value7 >> 8;
                x_fc5e = x_fc4f;
                y_fc5e = y_fc4f;
                carry_fc5e = value7 >= 0xFFC0;
                overflow_fc5e = overflow_fc4f;
                goto shared_FC5E;
            }
            r->a = value7;
            r->x = x_fc4f;
            r->y = y_fc4f;
            r->c = value7 >= 0xFFC0;
            r->v = overflow_fc4f;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if (value7 < 0x0120) {
            r->a = value7;
            r->x = x_fc4f;
            r->y = y_fc4f;
            r->c = value7 >= 0x0120;
            r->v = overflow_fc4f;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if (value7 >= 0x0120) {
            a_hi_fc5e = value7 >> 8;
            x_fc5e = x_fc4f;
            y_fc5e = y_fc4f;
            carry_fc5e = value7 >= 0x0120;
            overflow_fc5e = overflow_fc4f;
            goto shared_FC5E;
        }
        if (value7 < 0xFFC0) {
            a_hi_fc5e = value7 >> 8;
            x_fc5e = x_fc4f;
            y_fc5e = y_fc4f;
            carry_fc5e = value7 >= 0xFFC0;
            overflow_fc5e = overflow_fc4f;
            goto shared_FC5E;
        }
        r->a = value7;
        r->x = x_fc4f;
        r->y = y_fc4f;
        r->c = value7 >= 0xFFC0;
        r->v = overflow_fc4f;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    if (value6 < 0x0140) {
        uint16_t value8 = RAM16(0xE022 + x_fc4f);
        if (value8 & 0x8000) {
            if (value8 < 0xFFC0) {
                a_hi_fc5e = value8 >> 8;
                x_fc5e = x_fc4f;
                y_fc5e = y_fc4f;
                carry_fc5e = value8 >= 0xFFC0;
                overflow_fc5e = overflow_fc4f;
                goto shared_FC5E;
            }
            r->a = value8;
            r->x = x_fc4f;
            r->y = y_fc4f;
            r->c = value8 >= 0xFFC0;
            r->v = overflow_fc4f;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if (value8 < 0x0120) {
            r->a = value8;
            r->x = x_fc4f;
            r->y = y_fc4f;
            r->c = value8 >= 0x0120;
            r->v = overflow_fc4f;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            RETURN_RTS(c);
        }
        if (value8 >= 0x0120) {
            a_hi_fc5e = value8 >> 8;
            x_fc5e = x_fc4f;
            y_fc5e = y_fc4f;
            carry_fc5e = value8 >= 0x0120;
            overflow_fc5e = overflow_fc4f;
            goto shared_FC5E;
        }
        if (value8 < 0xFFC0) {
            a_hi_fc5e = value8 >> 8;
            x_fc5e = x_fc4f;
            y_fc5e = y_fc4f;
            carry_fc5e = value8 >= 0xFFC0;
            overflow_fc5e = overflow_fc4f;
            goto shared_FC5E;
        }
        r->a = value8;
        r->x = x_fc4f;
        r->y = y_fc4f;
        r->c = value8 >= 0xFFC0;
        r->v = overflow_fc4f;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    a_hi_fc5e = value6 >> 8;
    x_fc5e = x_fc4f;
    y_fc5e = y_fc4f;
    carry_fc5e = value6 >= 0x0140;
    overflow_fc5e = overflow_fc4f;
    goto shared_FC5E;
    shared_FC5E:;
    uint8_t value9 = RAM8(0xE032 + x_fc5e);
    if (value9 == 0) {
        RAM8(0xE043 + x_fc5e) = 1;
        r->a = (a_hi_fc5e << 8) | 1;
        r->x = x_fc5e;
        r->y = y_fc5e;
        r->c = carry_fc5e;
        r->v = overflow_fc5e;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    RAM8(0xE000 + x_fc5e) = 0;
    RAM8(0xE032 + x_fc5e) = 0;
    r->a = (a_hi_fc5e << 8) | value9;
    r->x = x_fc5e;
    r->y = y_fc5e;
    r->c = carry_fc5e;
    r->v = overflow_fc5e;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0FC2E, SOM_RTS, "gen", retain_or_remove_offscreen_actor_by_native_worker_gates, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 94, 43)
