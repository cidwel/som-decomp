#include "som_c.h"

/* 7E8FC7 allocate_transfer_descriptor   [class B, 159 bytes, 86 instructions]
 * Source: src/boot/allocate_transfer_descriptor.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: ABXYCV.
 */
static void allocate_transfer_descriptor_m16x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 7) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = a >> 8;
    RAM8(0x0000 + sp0 - 7) = (uint8_t)a;
    uint8_t a_hi1 = a >> 8;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value = RAM16(0x10064);
        uint8_t a_hi2 = a_hi1;
        uint16_t x1 = value;
        uint16_t y1 = 0x20;
        bool carry1 = 0;
        bool overflow2 = overflow1;
        for (;;) {
            if (RAM8(0x1000F + x1) != 0) {
                if ((uint16_t)(y1 - 1) != 0) {
                    uint8_t a_hi2_next = (uint16_t)(x1 + 0x10) >> 8;
                    uint16_t x1_next = (uint16_t)(x1 + 0x10);
                    uint16_t y1_next = (uint16_t)(y1 - 1);
                    bool carry1_next = x1 + 0x10 > 0xFFFF;
                    bool overflow2_next = ((x1 ^ (uint16_t)(x1 + 0x10)) & ((uint16_t)(x1 + 0x10) ^ 0x10) & 0x8000) != 0;
                    a_hi2 = a_hi2_next;
                    x1 = x1_next;
                    y1 = y1_next;
                    carry1 = carry1_next;
                    overflow2 = overflow2_next;
                    continue;
                }
                uint8_t a_hi2_next2 = (uint16_t)(x1 + 0x10) >> 8;
                uint16_t x1_next2 = (uint16_t)(x1 + 0x10);
                uint16_t y1_next2 = (uint16_t)(y1 - 1);
                bool carry1_next2 = x1 + 0x10 > 0xFFFF;
                bool overflow2_next2 = ((x1 ^ (uint16_t)(x1 + 0x10)) & ((uint16_t)(x1 + 0x10) ^ 0x10) & 0x8000) != 0;
                a_hi2 = a_hi2_next2;
                x1 = x1_next2;
                y1 = y1_next2;
                carry1 = carry1_next2;
                overflow2 = overflow2_next2;
                break;
            }
            uint8_t value3 = RAM8(0x0000 + sp0 - 7);
            uint8_t value4 = RAM8(0x0000 + sp0 - 6);
            RAM8(0x1000F + x1) = (uint8_t)((value4 << 8) | value3);
            RAM8(0x1000D + x1) = value4;
            RAM8(0x0000 + sp0 - 6) = x1 >> 8;
            RAM8(0x0000 + sp0 - 7) = (uint8_t)x1;
            uint8_t a_hi5;
            bool overflow5;
            if (value4 == 0) {
                a_hi5 = (uint8_t)((value4 << 8) | value3);
                overflow5 = overflow2;
            } else {
                uint8_t a_hi4;
                bool overflow4;
                if (value4 == 0x20) {
                    uint16_t value5 = RAM16(0x10068);
                    RAM8(0x10000 + (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value5))++;
                    a_hi4 = (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value5) >> 8;
                    overflow4 = ((((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) ^ (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value5)) & (value5 ^ (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value5)) & 0x8000) != 0;
                } else {
                    uint8_t a_hi3;
                    bool overflow3;
                    if (value4 >= 0x20) {
                        a_hi3 = (uint8_t)((value4 << 8) | value3);
                        overflow3 = overflow2;
                    } else {
                        uint16_t value6 = RAM16(0x10068);
                        RAM8(0x10000 + (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value6))++;
                        a_hi3 = (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value6) >> 8;
                        overflow3 = ((((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) ^ (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value6)) & (value6 ^ (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value6)) & 0x8000) != 0;
                    }
                    a_hi4 = a_hi3;
                    overflow4 = overflow3;
                }
                a_hi5 = a_hi4;
                overflow5 = overflow4;
            }
            uint8_t value7 = RAM8(0x1000F + x1);
            RAM8(0x10000 + x1) = RAM8(0x5EB4 + (uint8_t)((value7 & 7) - 1));
            RAM8(0x10009 + x1) = RAM8(0x5EB9 + (uint8_t)((value7 & 7) - 1));
            RAM8(0x10001 + x1) = RAM8(0x5EBE + (uint8_t)((value7 & 7) - 1));
            uint8_t value11 = RAM8(0x1000F + x1);
            uint8_t a_hi6;
            uint16_t x2;
            if (value11 != 5) {
                a_hi6 = 0;
                x2 = x1;
            } else {
                r->x = x1;
                r->y = x1;
                r->c = value11 >= 5;
                r->z = value11 == 5;
                r->n = (uint8_t)(value11 - 5) & 0x80;
                r->v = overflow5;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7F;
                r->dp = (uint16_t)(sp0 - 5);
                r->sp -= 6;
                JSR(c, 0x905F, 0x7E8F8F); /* reserve_highest_free_hdma_channel */
                r->sp += 6;
                uint16_t a_all = r->a;
                uint16_t x_ret = r->x;
                a_hi6 = a_all >> 8;
                x2 = x_ret;
            }
            uint8_t value13 = RAM8(0x0000 + sp0 - 3);
            uint8_t value14 = RAM8(0x0000 + sp0 - 1);
            uint8_t value15 = RAM8(0x0000 + sp0);
            r->a = (a_hi6 << 8) | value13;
            r->x = x2;
            r->y = x1;
            r->c = carry;
            r->v = overflow;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7F;
            r->dp = (value15 << 8) | value14;
            RETURN_RTS(c);
        }
        uint8_t value16 = RAM8(0x0000 + sp0 - 6);
        if ((uint8_t)(value16 + 1) != 0) {
            r->a = (a_hi2 << 8) | (uint8_t)(value16 + 1);
            r->y = y1;
            r->c = carry1;
            r->z = (uint8_t)(value16 + 1) == 0;
            r->n = (uint8_t)(value16 + 1) & 0x80;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7F;
            r->dp = (uint16_t)(sp0 - 5);
            r->sp -= 8;
            JSR(c, 0x8FFD, 0x7E9164); /* prepare_transfer_pass */
            r->sp += 8;
            r->x = 1;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 8;
            JSR(c, 0x9003, 0x7EABE7); /* receive_with_supplied_delay */
            r->sp += 8;
            uint16_t a_all3 = r->a;
            bool overflow_ret3 = r->v;
            a_hi1 = a_all3 >> 8;
            overflow1 = overflow_ret3;
            continue;
        }
        uint8_t value19 = RAM8(0x0000 + sp0 - 3);
        uint8_t value20 = RAM8(0x0000 + sp0 - 1);
        uint8_t value21 = RAM8(0x0000 + sp0);
        r->a = (a_hi2 << 8) | value19;
        r->x = 0;
        r->y = y1;
        r->c = carry;
        r->v = overflow;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7F;
        r->dp = (value21 << 8) | value20;
        RETURN_RTS(c);
    }
}

/* 7E8FC7 allocate_transfer_descriptor   [class B, 159 bytes, 86 instructions]
 * Source: src/boot/allocate_transfer_descriptor.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7F D=any.  Callers read: ABXYCV.
 */
static void allocate_transfer_descriptor_m8x16(SomCtx *c)
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
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 7) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = a_hi;
    RAM8(0x0000 + sp0 - 7) = (uint8_t)((a_hi << 8) | a);
    uint8_t a_hi1 = a_hi;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value = RAM16(0x10064);
        uint8_t a_hi2 = a_hi1;
        uint16_t x1 = value;
        uint16_t y1 = 0x20;
        bool carry1 = 0;
        bool overflow2 = overflow1;
        for (;;) {
            if (RAM8(0x1000F + x1) != 0) {
                if ((uint16_t)(y1 - 1) != 0) {
                    uint8_t a_hi2_next = (uint16_t)(x1 + 0x10) >> 8;
                    uint16_t x1_next = (uint16_t)(x1 + 0x10);
                    uint16_t y1_next = (uint16_t)(y1 - 1);
                    bool carry1_next = x1 + 0x10 > 0xFFFF;
                    bool overflow2_next = ((x1 ^ (uint16_t)(x1 + 0x10)) & ((uint16_t)(x1 + 0x10) ^ 0x10) & 0x8000) != 0;
                    a_hi2 = a_hi2_next;
                    x1 = x1_next;
                    y1 = y1_next;
                    carry1 = carry1_next;
                    overflow2 = overflow2_next;
                    continue;
                }
                uint8_t a_hi2_next2 = (uint16_t)(x1 + 0x10) >> 8;
                uint16_t x1_next2 = (uint16_t)(x1 + 0x10);
                uint16_t y1_next2 = (uint16_t)(y1 - 1);
                bool carry1_next2 = x1 + 0x10 > 0xFFFF;
                bool overflow2_next2 = ((x1 ^ (uint16_t)(x1 + 0x10)) & ((uint16_t)(x1 + 0x10) ^ 0x10) & 0x8000) != 0;
                a_hi2 = a_hi2_next2;
                x1 = x1_next2;
                y1 = y1_next2;
                carry1 = carry1_next2;
                overflow2 = overflow2_next2;
                break;
            }
            uint8_t value3 = RAM8(0x0000 + sp0 - 7);
            uint8_t value4 = RAM8(0x0000 + sp0 - 6);
            RAM8(0x1000F + x1) = (uint8_t)((value4 << 8) | value3);
            RAM8(0x1000D + x1) = value4;
            RAM8(0x0000 + sp0 - 6) = x1 >> 8;
            RAM8(0x0000 + sp0 - 7) = (uint8_t)x1;
            uint8_t a_hi5;
            bool overflow5;
            if (value4 == 0) {
                a_hi5 = (uint8_t)((value4 << 8) | value3);
                overflow5 = overflow2;
            } else {
                uint8_t a_hi4;
                bool overflow4;
                if (value4 == 0x20) {
                    uint16_t value5 = RAM16(0x10068);
                    RAM8(0x10000 + (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value5))++;
                    a_hi4 = (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value5) >> 8;
                    overflow4 = ((((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) ^ (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value5)) & (value5 ^ (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value5)) & 0x8000) != 0;
                } else {
                    uint8_t a_hi3;
                    bool overflow3;
                    if (value4 >= 0x20) {
                        a_hi3 = (uint8_t)((value4 << 8) | value3);
                        overflow3 = overflow2;
                    } else {
                        uint16_t value6 = RAM16(0x10068);
                        RAM8(0x10000 + (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value6))++;
                        a_hi3 = (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value6) >> 8;
                        overflow3 = ((((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) ^ (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value6)) & (value6 ^ (uint16_t)(((((uint8_t)((value4 << 8) | value3) << 8) | (uint8_t)(value4 - 1)) & 0xFF) + value6)) & 0x8000) != 0;
                    }
                    a_hi4 = a_hi3;
                    overflow4 = overflow3;
                }
                a_hi5 = a_hi4;
                overflow5 = overflow4;
            }
            uint8_t value7 = RAM8(0x1000F + x1);
            RAM8(0x10000 + x1) = RAM8(0x5EB4 + (uint8_t)((value7 & 7) - 1));
            RAM8(0x10009 + x1) = RAM8(0x5EB9 + (uint8_t)((value7 & 7) - 1));
            RAM8(0x10001 + x1) = RAM8(0x5EBE + (uint8_t)((value7 & 7) - 1));
            uint8_t value11 = RAM8(0x1000F + x1);
            uint8_t a_hi6;
            uint16_t x2;
            if (value11 != 5) {
                a_hi6 = 0;
                x2 = x1;
            } else {
                r->x = x1;
                r->y = x1;
                r->c = value11 >= 5;
                r->z = value11 == 5;
                r->n = (uint8_t)(value11 - 5) & 0x80;
                r->v = overflow5;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7F;
                r->dp = (uint16_t)(sp0 - 5);
                r->sp -= 6;
                JSR(c, 0x905F, 0x7E8F8F); /* reserve_highest_free_hdma_channel */
                r->sp += 6;
                uint16_t a_all = r->a;
                uint16_t x_ret = r->x;
                a_hi6 = a_all >> 8;
                x2 = x_ret;
            }
            uint8_t value13 = RAM8(0x0000 + sp0 - 3);
            uint8_t value14 = RAM8(0x0000 + sp0 - 1);
            uint8_t value15 = RAM8(0x0000 + sp0);
            r->a = (a_hi6 << 8) | value13;
            r->x = x2;
            r->y = x1;
            r->c = carry;
            r->v = overflow;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7F;
            r->dp = (value15 << 8) | value14;
            RETURN_RTS(c);
        }
        uint8_t value16 = RAM8(0x0000 + sp0 - 6);
        if ((uint8_t)(value16 + 1) != 0) {
            r->a = (a_hi2 << 8) | (uint8_t)(value16 + 1);
            r->y = y1;
            r->c = carry1;
            r->z = (uint8_t)(value16 + 1) == 0;
            r->n = (uint8_t)(value16 + 1) & 0x80;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7F;
            r->dp = (uint16_t)(sp0 - 5);
            r->sp -= 8;
            JSR(c, 0x8FFD, 0x7E9164); /* prepare_transfer_pass */
            r->sp += 8;
            r->x = 1;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 8;
            JSR(c, 0x9003, 0x7EABE7); /* receive_with_supplied_delay */
            r->sp += 8;
            uint16_t a_all3 = r->a;
            bool overflow_ret3 = r->v;
            a_hi1 = a_all3 >> 8;
            overflow1 = overflow_ret3;
            continue;
        }
        uint8_t value19 = RAM8(0x0000 + sp0 - 3);
        uint8_t value20 = RAM8(0x0000 + sp0 - 1);
        uint8_t value21 = RAM8(0x0000 + sp0);
        r->a = (a_hi2 << 8) | value19;
        r->x = 0;
        r->y = y1;
        r->c = carry;
        r->v = overflow;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7F;
        r->dp = (value21 << 8) | value20;
        RETURN_RTS(c);
    }
}

/* Entered with M16/X16, M8/X16 accumulator/index widths: one body per width pair. */
static void allocate_transfer_descriptor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (r->mf == 0 && r->xf == 0) { allocate_transfer_descriptor_m16x16(c); return; }
    if (r->mf == 1 && r->xf == 0) { allocate_transfer_descriptor_m8x16(c); return; }
    c->fail = 3;
}
SOM_REGISTER(0x7E8FC7, SOM_RTS, "gen", allocate_transfer_descriptor, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 8, -1, -1, 159, 86)
