#include "som_c.h"

/* 7ED5F3 allocate_vram_pages   [class B, 133 bytes, 79 instructions]
 * Source: src/boot/allocate_vram_pages.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7F D=any.  Callers read: ABYV.
 */
static void allocate_vram_pages(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 0x0B) = 0x7F;
    RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x0D) = 0x7F;
    RAM8(0x0002 + (uint16_t)(sp0 - 0x0B)) = (uint8_t)value;
    RAM8(0x0004 + (uint16_t)(sp0 - 0x0B)) = value >> 8;
    RAM8(0x0005 + (uint16_t)(sp0 - 0x0B)) = value >> 0x0C;
    RAM8(0x0006 + (uint16_t)(sp0 - 0x0B)) = 0;
    RAM8(0x0001 + (uint16_t)(sp0 - 0x0B)) = 0x20;
    uint8_t value2 = RAM8(0x0005 + (uint16_t)(sp0 - 0x0B));
    uint16_t value3 = RAM16(0x1032C);
    uint8_t a1 = value2;
    uint8_t a_hi1 = (uint8_t)value;
    for (;;) {
        if (!(a1 & 0x01)) {
            RAM8(0x0001 + (uint16_t)(sp0 - 0x0B)) >>= 1;
            a1 = a1 >> 1;
            continue;
        }
        a1 = a1 >> 1;
        break;
    }
    uint8_t a2 = a1;
    uint8_t a_hi2 = a_hi1;
    uint16_t x1 = value3;
    for (;;) {
        uint8_t value5 = RAM8(0x10000 + x1);
        uint8_t a_hi4;
        if (value5 != 0) {
            uint16_t value6 = RAM16(0x0005 + (uint16_t)(sp0 - 0x0B));
            RAM8(0x0001 + (uint16_t)(sp0 - 0x0B))--;
            if (RAM8(0x0001 + (uint16_t)(sp0 - 0x0B)) != 0) {
                uint8_t a2_next = (uint8_t)(x1 + value6);
                uint8_t a_hi2_next = (uint16_t)(x1 + value6) >> 8;
                uint16_t x1_next = (uint16_t)(x1 + value6);
                a2 = a2_next;
                a_hi2 = a_hi2_next;
                x1 = x1_next;
                continue;
            }
            a_hi4 = (uint16_t)(x1 + value6) >> 8;
        } else {
            RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0B), x1);
            RAM8(0x0003 + (uint16_t)(sp0 - 0x0B)) = RAM8(0x0002 + (uint16_t)(sp0 - 0x0B));
            uint8_t a_hi3 = a_hi2;
            uint16_t x2 = x1;
            for (;;) {
                RAM8(0x0003 + (uint16_t)(sp0 - 0x0B))--;
                if (RAM8(0x0003 + (uint16_t)(sp0 - 0x0B)) != 0) {
                    if (RAM8(0x10000 + (uint16_t)(x2 + 1)) == 0) {
                        x2 = (uint16_t)(x2 + 1);
                        continue;
                    }
                    x2 = (uint16_t)(x2 + 1);
                    break;
                }
                RAM8(0x0001 + (uint16_t)(sp0 - 0x0B)) = RAM8(0x0002 + (uint16_t)(sp0 - 0x0B));
                uint16_t value9 = RAM16(0x0007 + (uint16_t)(sp0 - 0x0B));
                uint8_t value10 = RAM8(0x0004 + (uint16_t)(sp0 - 0x0B));
                uint16_t x3 = value9;
                do {
                    RAM8(0x10000 + x3) = value10;
                    RAM8(0x0001 + (uint16_t)(sp0 - 0x0B))--;
                    x3 = (uint16_t)(x3 + 1);
                } while (RAM8(0x0001 + (uint16_t)(sp0 - 0x0B)) != 0);
                uint16_t value11 = RAM16(0x0007 + (uint16_t)(sp0 - 0x0B));
                uint16_t value12 = RAM16(0x1032C);
                a2 = (uint8_t)(value11 - value12);
                a_hi2 = (uint16_t)(value11 - value12) >> 8;
                x1 = x3;
                goto leave_loop_7ED627;
            }
            uint16_t value14 = RAM16(0x0007 + (uint16_t)(sp0 - 0x0B));
            uint16_t value15 = RAM16(0x0005 + (uint16_t)(sp0 - 0x0B));
            RAM8(0x0001 + (uint16_t)(sp0 - 0x0B))--;
            if (RAM8(0x0001 + (uint16_t)(sp0 - 0x0B)) != 0) {
                a2 = (uint8_t)(value14 + value15);
                a_hi2 = (uint16_t)(value14 + value15) >> 8;
                x1 = (uint16_t)(value14 + value15);
                continue;
            }
            a_hi4 = (uint16_t)(value14 + value15) >> 8;
        }
        a2 = 0xFF;
        a_hi2 = a_hi4;
        break;
    }
    leave_loop_7ED627:;
    RAM16_SET(0x0000 + sp0 - 4, (a_hi2 << 8) | a2);
    uint8_t value16 = RAM8(0x0000 + sp0 - 4);
    uint8_t value17 = RAM8(0x0000 + sp0 - 3);
    uint8_t value18 = RAM8(0x0000 + sp0 - 1);
    uint8_t value19 = RAM8(0x0000 + sp0);
    r->a = (value17 << 8) | value16;
    r->y = y;
    r->v = overflow;
    r->dp = (value19 << 8) | value18;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ED5F3, SOM_RTS, "gen", allocate_vram_pages, 0, L_A | L_B | L_Y | L_V, 14, 1, 0, 133, 79)
