#include "som_c.h"

/* 7ECB86 allocate_timer_registration   [class B, 68 bytes, 43 instructions]
 * Source: src/boot/allocate_timer_registration.s
 * Documented in docs/boot.md
 * Entry: M=any X=16 bit DB=$7F D=any.  Callers read: BXYCV.
 */
static void allocate_timer_registration(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, -1, 0)) return;
    const uint16_t sp0 = r->sp + 1;
    const uint8_t d_entry = r->d;
    const uint8_t m_entry = r->mf;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)((uint16_t)(sp0 - 6) + 1) + 0x1 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0 - 1) = dp >> 8;
    RAM8(0x0000 + sp0 - 2) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 3) = (((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 4) = a >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 7) = 0x7F;
    RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 6) + 1)) = (uint8_t)a;
    uint16_t value = RAM16(0x10302);
    RAM8(0x0000 + sp0 - 6) = ((((value >> 0x0F << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | ((value == 0) << 1) | carry;
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = value;
    uint16_t y1 = 0x20;
    for (;;) {
        uint8_t value2 = RAM8(0x10000 + x1);
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        if (value2 == 0) {
            BUS8_SET(c, 0x7F0001 + x1, RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 6) + 1)));
            RAM8(0x10000 + x1) = 1;
            a_hi2 = a_hi1;
            x2 = x1;
            y2 = y1;
        } else {
            if ((uint16_t)(y1 - 1) != 0) {
                uint8_t a_hi1_next = (uint16_t)(x1 + 4) >> 8;
                uint16_t x1_next = (uint16_t)(x1 + 4);
                uint16_t y1_next = (uint16_t)(y1 - 1);
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                y1 = y1_next;
                continue;
            }
            a_hi2 = (uint16_t)(x1 + 4) >> 8;
            x2 = 0;
            y2 = (uint16_t)(y1 - 1);
        }
        a_hi1 = a_hi2;
        x1 = x2;
        y1 = y2;
        break;
    }
    uint8_t value4 = RAM8(0x0000 + sp0 - 6);
    uint8_t value5 = RAM8(0x0000 + sp0 - 5);
    if (value4 & 0x20) {
        uint8_t value6 = RAM8(0x0000 + sp0 - 4);
        uint8_t value7 = RAM8(0x0000 + sp0 - 3);
        uint8_t value8 = RAM8(0x0000 + sp0 - 2);
        uint8_t value9 = RAM8(0x0000 + sp0 - 1);
        r->a = (a_hi1 << 8) | value6;
        r->x = x1;
        r->y = y1;
        r->c = value7 & 0x01;
        r->v = value7 & 0x40;
        r->mf = value7 & 0x20;
        r->xf = value7 & 0x10;
        r->db = value5;
        r->dp = (value9 << 8) | value8;
        r->i = value7 & 0x04;
        r->d = value7 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint8_t value10 = RAM8(0x0000 + sp0 - 4);
        uint8_t value11 = RAM8(0x0000 + sp0 - 3);
        uint8_t value12 = RAM8(0x0000 + sp0 - 2);
        uint8_t value13 = RAM8(0x0000 + sp0 - 1);
        uint8_t value14 = RAM8(0x0000 + sp0);
        r->a = (value11 << 8) | value10;
        r->x = x1;
        r->y = y1;
        r->c = value12 & 0x01;
        r->v = value12 & 0x40;
        r->mf = value12 & 0x20;
        r->xf = value12 & 0x10;
        r->db = value5;
        r->dp = (value14 << 8) | value13;
        r->i = value12 & 0x04;
        r->d = value12 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        r->sp += 1;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7ECB86, SOM_RTS, "gen", allocate_timer_registration, SOM_UNWINDS, L_B | L_X | L_Y | L_C | L_V, 8, -1, 0, 68, 43)
