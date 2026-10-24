#include "som_c.h"

/* 7E86F1 cache_nearest_colour_sample   [class B, 216 bytes, 119 instructions]
 * Source: src/boot/cache_nearest_colour_sample.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$05BF.  Callers read: A.
 */
static void cache_nearest_colour_sample(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x05BF) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0E) + 0xB > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0xBF;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t value = BUS8(c, 0x000000 + y);
    RAM8(0x0007 + (uint16_t)(sp0 - 0x0E)) = value;
    uint8_t value2 = BUS8(c, 0x000001 + y);
    RAM8(0x0008 + (uint16_t)(sp0 - 0x0E)) = value2;
    uint8_t value3 = BUS8(c, 0x000002 + y);
    RAM8(0x0009 + (uint16_t)(sp0 - 0x0E)) = value3;
    RAM8(0x0000 + sp0 - 0x0E) = 0;
    RAM8(0x0000 + sp0 - 0x0F) = 0x7F;
    RAM8(0x0004 + (uint16_t)(sp0 - 0x0E)) = 0xF7;
    RAM8(0x0002 + (uint16_t)(sp0 - 0x0E)) = 0xFF;
    RAM8(0x0001 + (uint16_t)(sp0 - 0x0E)) = 0xE8;
    uint16_t value4 = RAM16(0x1001A);
    uint8_t a_hi1 = (uint16_t)(sp0 - 0x0E) >> 8;
    uint16_t y1 = value4;
    for (;;) {
        uint8_t value5 = RAM8(0x10000 + y1);
        uint8_t value6 = RAM8(0x0007 + (uint16_t)(sp0 - 0x0E));
        uint8_t a1;
        bool zero1;
        bool negative1;
        if (value5 >= value6) {
            a1 = (uint8_t)(value5 - value6);
            zero1 = (uint8_t)(value5 - value6) == 0;
            negative1 = (uint8_t)(value5 - value6) & 0x80;
        } else {
            a1 = (uint8_t)(((uint8_t)(value5 - value6) ^ 0xFF) + 1);
            zero1 = (uint8_t)(((uint8_t)(value5 - value6) ^ 0xFF) + 1) == 0;
            negative1 = (uint8_t)(((uint8_t)(value5 - value6) ^ 0xFF) + 1) & 0x80;
        }
        RAM8(0x0006 + (uint16_t)(sp0 - 0x0E)) = a1;
        RAM8(0x0000 + sp0 - 0x0F) = ((((negative1 << 7) | ((((value5 ^ value6) & (value5 ^ (uint8_t)(value5 - value6)) & 0x80) != 0) << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero1 << 1) | value5 >= value6;
        uint8_t value7 = RAM8(0x0006 + (uint16_t)(sp0 - 0x0E));
        BUS16_SET(c, 0x004202, (a1 << 8) | value7);
        RAM8(0x0000 + sp0 - 0x10) = a1;
        RAM8(0x0000 + sp0 - 0x11) = (uint8_t)((a1 << 8) | value7);
        uint16_t value8 = BUS16(c, 0x004216);
        RAM16_SET(0x000A + (uint16_t)(sp0 - 0x0E), value8);
        uint8_t value9 = BUS8(c, 0x7F0001 + y1);
        uint8_t value10 = RAM8(0x0008 + (uint16_t)(sp0 - 0x0E));
        uint8_t a2;
        bool zero2;
        bool negative2;
        if (value9 >= value10) {
            a2 = (uint8_t)(value9 - value10);
            zero2 = (uint8_t)(value9 - value10) == 0;
            negative2 = (uint8_t)(value9 - value10) & 0x80;
        } else {
            a2 = (uint8_t)(((uint8_t)(value9 - value10) ^ 0xFF) + 1);
            zero2 = (uint8_t)(((uint8_t)(value9 - value10) ^ 0xFF) + 1) == 0;
            negative2 = (uint8_t)(((uint8_t)(value9 - value10) ^ 0xFF) + 1) & 0x80;
        }
        RAM8(0x0006 + (uint16_t)(sp0 - 0x0E)) = a2;
        RAM8(0x0000 + sp0 - 0x0F) = ((((negative2 << 7) | ((((value9 ^ value10) & (value9 ^ (uint8_t)(value9 - value10)) & 0x80) != 0) << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero2 << 1) | value9 >= value10;
        uint8_t value11 = RAM8(0x0006 + (uint16_t)(sp0 - 0x0E));
        BUS16_SET(c, 0x004202, (a2 << 8) | value11);
        RAM8(0x0000 + sp0 - 0x10) = a2;
        RAM8(0x0000 + sp0 - 0x11) = (uint8_t)((a2 << 8) | value11);
        uint16_t value12 = BUS16(c, 0x004216);
        RAM16_SET(0x000A + (uint16_t)(sp0 - 0x0E), (uint16_t)(value12 + RAM16(0x000A + (uint16_t)(sp0 - 0x0E))));
        uint8_t value14 = BUS8(c, 0x7F0002 + y1);
        uint8_t value15 = RAM8(0x0009 + (uint16_t)(sp0 - 0x0E));
        uint8_t a3;
        bool zero3;
        bool negative3;
        if (value14 >= value15) {
            a3 = (uint8_t)(value14 - value15);
            zero3 = (uint8_t)(value14 - value15) == 0;
            negative3 = (uint8_t)(value14 - value15) & 0x80;
        } else {
            a3 = (uint8_t)(((uint8_t)(value14 - value15) ^ 0xFF) + 1);
            zero3 = (uint8_t)(((uint8_t)(value14 - value15) ^ 0xFF) + 1) == 0;
            negative3 = (uint8_t)(((uint8_t)(value14 - value15) ^ 0xFF) + 1) & 0x80;
        }
        RAM8(0x0006 + (uint16_t)(sp0 - 0x0E)) = a3;
        RAM8(0x0000 + sp0 - 0x0F) = ((((negative3 << 7) | ((((value14 ^ value15) & (value14 ^ (uint8_t)(value14 - value15)) & 0x80) != 0) << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero3 << 1) | value14 >= value15;
        uint8_t value16 = RAM8(0x0006 + (uint16_t)(sp0 - 0x0E));
        BUS16_SET(c, 0x004202, (a3 << 8) | value16);
        RAM8(0x0000 + sp0 - 0x10) = a3;
        RAM8(0x0000 + sp0 - 0x11) = (uint8_t)((a3 << 8) | value16);
        uint16_t value17 = BUS16(c, 0x004216);
        uint16_t value18 = RAM16(0x000A + (uint16_t)(sp0 - 0x0E));
        uint16_t value19 = RAM16(0x0002 + (uint16_t)(sp0 - 0x0E));
        uint8_t a_hi2;
        if ((uint16_t)(value17 + value18) >= value19) {
            a_hi2 = (uint16_t)(value17 + value18) >> 8;
        } else {
            RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x0E), (uint16_t)(value17 + value18));
            uint16_t value20 = RAM16(0x0001 + (uint16_t)(sp0 - 0x0E));
            RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x0E), value20);
            a_hi2 = value20 >> 8;
        }
        RAM8(0x0001 + (uint16_t)(sp0 - 0x0E))--;
        if (RAM8(0x0001 + (uint16_t)(sp0 - 0x0E)) != 0) {
            uint8_t a_hi1_next = (uint16_t)(y1 + 4) >> 8;
            uint16_t y1_next = (uint16_t)(y1 + 4);
            a_hi1 = a_hi1_next;
            y1 = y1_next;
            continue;
        }
        uint8_t a_hi1_next2 = (uint16_t)(y1 + 4) >> 8;
        uint16_t y1_next2 = (uint16_t)(y1 + 4);
        a_hi1 = a_hi1_next2;
        y1 = y1_next2;
        break;
    }
    uint8_t value21 = RAM8(0x0004 + (uint16_t)(sp0 - 0x0E));
    BUS8_SET(c, 0x7F8000 + x, (uint8_t)(0xF7 - value21));
    uint8_t value22 = RAM8(0x0000 + sp0 - 0x0E);
    RAM16_SET(0x0000 + sp0 - 4, (a_hi1 << 8) | (uint8_t)(0xF7 - value21));
    uint8_t value23 = RAM8(0x0000 + sp0 - 4);
    uint8_t value24 = RAM8(0x0000 + sp0 - 3);
    uint8_t value25 = RAM8(0x0000 + sp0 - 2);
    uint8_t value26 = RAM8(0x0000 + sp0 - 1);
    uint8_t value27 = RAM8(0x0000 + sp0);
    r->a = (value24 << 8) | value23;
    r->mf = value25 & 0x20;
    r->xf = value25 & 0x10;
    r->db = value22;
    r->dp = (value27 << 8) | value26;
    r->i = value25 & 0x04;
    r->d = value25 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E86F1, SOM_RTS, "gen", cache_nearest_colour_sample, 0, L_A, 18, 1, 0, 216, 119)
