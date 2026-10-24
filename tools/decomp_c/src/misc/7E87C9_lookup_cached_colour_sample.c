#include "som_c.h"

/* 7E87C9 lookup_cached_colour_sample   [class A, 22 bytes, 12 instructions]
 * Source: src/boot/lookup_cached_colour_sample.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$05BF.  Callers read: A.
 */
static void lookup_cached_colour_sample(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x05BF) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0xBF;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->y = x;
    r->z = x == 0;
    r->n = x & 0x8000;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x87D2, 0x7E83E2); GUARD_JSR(c, sp_call, 0x87D2); } /* quantize_component_cube_index */
    r->sp += 3;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    if (m_ret) {
        uint8_t value = BUS8(c, 0x7F8000 + x_ret2);
        bool m_flag;
        bool x_flag;
        uint8_t a1;
        if (value != 0) {
            m_flag = 1;
            x_flag = x_ret;
            a1 = value;
        } else {
            r->a = (a_all >> 8 << 8) | value;
            r->z = value == 0;
            r->n = value & 0x80;
            r->mf = 1;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSR(c, 0x87DB, 0x7E86F1); GUARD_JSR(c, sp_call, 0x87DB); } /* cache_nearest_colour_sample */
            r->sp += 3;
            bool m_ret2 = r->mf;
            bool x_ret3 = r->xf;
            uint16_t a_all2 = r->a;
            m_flag = m_ret2;
            x_flag = x_ret3;
            a1 = (uint8_t)a_all2;
        }
        uint8_t value2 = RAM8(0x0000 + sp0 - 2);
        uint8_t value3 = RAM8(0x0000 + sp0 - 1);
        uint8_t value4 = RAM8(0x0000 + sp0);
        r->a = (a_hi << 8) | a1;
        r->mf = value2 & 0x20;
        r->xf = value2 & 0x10;
        r->dp = (value4 << 8) | value3;
        r->i = value2 & 0x04;
        r->d = value2 & 0x08;
        RETURN_RTS(c);
    } else {
        uint16_t value5 = BUS16(c, 0x7F8000 + x_ret2);
        bool m_flag2;
        bool x_flag2;
        uint8_t a2;
        if (value5 != 0) {
            m_flag2 = 0;
            x_flag2 = x_ret;
            a2 = (uint8_t)value5;
        } else {
            r->a = value5;
            r->z = value5 == 0;
            r->n = value5 & 0x8000;
            r->mf = 0;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSR(c, 0x87DB, 0x7E86F1); GUARD_JSR(c, sp_call, 0x87DB); } /* cache_nearest_colour_sample */
            r->sp += 3;
            bool m_ret3 = r->mf;
            bool x_ret4 = r->xf;
            uint16_t a_all3 = r->a;
            m_flag2 = m_ret3;
            x_flag2 = x_ret4;
            a2 = (uint8_t)a_all3;
        }
        uint8_t value6 = RAM8(0x0000 + sp0 - 2);
        uint8_t value7 = RAM8(0x0000 + sp0 - 1);
        uint8_t value8 = RAM8(0x0000 + sp0);
        r->a = (a_hi << 8) | a2;
        r->mf = value6 & 0x20;
        r->xf = value6 & 0x10;
        r->dp = (value8 << 8) | value7;
        r->i = value6 & 0x04;
        r->d = value6 & 0x08;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7E87C9, SOM_RTS, "gen", lookup_cached_colour_sample, 0, L_A, 3, 1, 0, 22, 12)
