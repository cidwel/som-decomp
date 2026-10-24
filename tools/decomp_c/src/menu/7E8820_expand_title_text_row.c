#include "som_c.h"

/* 7E8820 expand_title_text_row   [class B, 78 bytes, 44 instructions]
 * Source: src/boot/expand_title_text_row.s
 * Entry: M=any X=16 bit DB=$7F D=any.  Callers read: ABXYCV.
 */
static void expand_title_text_row(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t m_entry = r->mf;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = (((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    uint8_t value = RAM8(0x59F8 + x);
    uint8_t a_hi3;
    uint16_t x2;
    uint16_t y4;
    if (value == 0) {
        a_hi3 = (uint16_t)(sp0 - 5) >> 8;
        x2 = 0;
        y4 = y;
    } else {
        RAM8(0x0001 + (uint16_t)(sp0 - 5)) = value;
        RAM8(0x0002 + (uint16_t)(sp0 - 5)) = value;
        uint16_t y1 = y;
        do {
            RAM8(0x10000 + y1) = 0x60;
            RAM8(0x0001 + (uint16_t)(sp0 - 5))--;
            y1 = (uint16_t)(y1 + 2);
        } while (RAM8(0x0001 + (uint16_t)(sp0 - 5)) != 0);
        uint8_t a_hi1 = (uint16_t)(sp0 - 5) >> 8;
        uint16_t x1 = x;
        uint16_t y2 = y1;
        for (;;) {
            uint8_t value2 = RAM8(0x59F8 + (uint16_t)(x1 + 1));
            if (value2 != 0) {
                uint8_t a1;
                if (value2 != 0x20) {
                    a1 = value2;
                } else {
                    a1 = 0x60;
                }
                RAM8(0x10000 + y2) = a1;
                RAM8(0x0002 + (uint16_t)(sp0 - 5))++;
                x1 = (uint16_t)(x1 + 1);
                y2 = (uint16_t)(y2 + 2);
                continue;
            }
            x1 = (uint16_t)(x1 + 1);
            break;
        }
        uint8_t a_hi2 = a_hi1;
        uint16_t y3 = y2;
        for (;;) {
            if (RAM8(0x0002 + (uint16_t)(sp0 - 5)) < 0x20) {
                RAM8(0x10000 + y3) = 0x60;
                RAM8(0x0002 + (uint16_t)(sp0 - 5))++;
                y3 = (uint16_t)(y3 + 2);
                continue;
            }
            break;
        }
        a_hi3 = a_hi2;
        x2 = (uint16_t)(x1 + 1);
        y4 = y3;
    }
    uint8_t value5 = RAM8(0x0000 + sp0 - 3);
    uint8_t value6 = RAM8(0x0000 + sp0 - 2);
    uint8_t value7 = RAM8(0x0000 + sp0 - 1);
    uint8_t value8 = RAM8(0x0000 + sp0);
    r->a = (a_hi3 << 8) | value5;
    r->x = x2;
    r->y = y4;
    r->c = value6 & 0x01;
    r->v = value6 & 0x40;
    r->mf = value6 & 0x20;
    r->xf = value6 & 0x10;
    r->dp = (value8 << 8) | value7;
    r->i = value6 & 0x04;
    r->d = value6 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E8820, SOM_RTS, "gen", expand_title_text_row, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 5, -1, 0, 78, 44)
