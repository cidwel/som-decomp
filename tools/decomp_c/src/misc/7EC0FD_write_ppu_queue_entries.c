#include "som_c.h"

/* 7EC0FD write_ppu_queue_entries   [class B, 142 bytes, 77 instructions]
 * Source: src/boot/write_ppu_queue_entries.s
 * Documented in docs/boot.md
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: BXYCZNV.
 */
static void write_ppu_queue_entries(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t m_entry = r->mf;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = (((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 7) = db;
    RAM8(0x0000 + sp0 - 8) = 0x7F;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), 0x2100);
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), 0);
    uint8_t a_hi1 = 0;
    uint16_t x1 = x;
    uint16_t y1 = 0x02DA;
    for (;;) {
        uint16_t value = BUS16(c, 0x7F0001 + y1);
        if ((value & 0xFF) != 0) {
            uint16_t value2 = RAM16(0x102D6);
            RAM8(0x0000 + sp0 - 8) = (uint16_t)((value & 0xFF) + value2) >> 8;
            RAM8(0x0000 + sp0 - 9) = (uint8_t)((value & 0xFF) + value2);
            uint16_t value3 = BUS16(c, 0x7F0000 + (uint16_t)((value & 0xFF) + value2));
            uint16_t value4 = BUS16(c, 0x7F0002 + (uint16_t)((value & 0xFF) + value2));
            BUS8_SET(c, (RAM8(0x0003 + (uint16_t)(sp0 - 7)) << 0x10) + RAM16(0x0001 + (uint16_t)(sp0 - 7)) + (value3 & 0xFF), (uint8_t)value4);
            uint8_t value5 = RAM8(0x603E + (value3 & 0xFF));
            uint8_t a_hi2;
            if (value5 == 0) {
                a_hi2 = value4 >> 8;
            } else {
                uint16_t y2;
                if (value5 != 1) {
                    y2 = value3 & 0xFF;
                } else {
                    y2 = (value3 & 0xFF) + 1;
                }
                BUS8_SET(c, (RAM8(0x0003 + (uint16_t)(sp0 - 7)) << 0x10) + RAM16(0x0001 + (uint16_t)(sp0 - 7)) + y2, value4 >> 8);
                a_hi2 = value5;
            }
            uint8_t value6 = RAM8(0x0000 + sp0 - 9);
            uint8_t value7 = RAM8(0x0000 + sp0 - 8);
            a_hi1 = a_hi2;
            x1 = value3 & 0xFF;
            y1 = (value7 << 8) | value6;
            continue;
        }
        a_hi1 = 0;
        break;
    }
    uint8_t a_hi3 = a_hi1;
    uint16_t x2 = x1;
    uint16_t y3 = 0x02DE;
    for (;;) {
        uint16_t value8 = BUS16(c, 0x7F0001 + y3);
        if ((value8 & 0xFF) != 0) {
            uint16_t value9 = RAM16(0x102D6);
            RAM8(0x0000 + sp0 - 8) = (uint16_t)((value8 & 0xFF) + value9) >> 8;
            RAM8(0x0000 + sp0 - 9) = (uint8_t)((value8 & 0xFF) + value9);
            uint16_t value10 = BUS16(c, 0x7F0000 + (uint16_t)((value8 & 0xFF) + value9));
            uint16_t value11 = BUS16(c, 0x7F0002 + (uint16_t)((value8 & 0xFF) + value9));
            BUS8_SET(c, (RAM8(0x0003 + (uint16_t)(sp0 - 7)) << 0x10) + RAM16(0x0001 + (uint16_t)(sp0 - 7)) + (value10 & 0xFF), (uint8_t)value11);
            uint8_t value12 = RAM8(0x603E + (value10 & 0xFF));
            uint8_t a_hi4;
            if (value12 == 0) {
                a_hi4 = value11 >> 8;
            } else {
                uint16_t y4;
                if (value12 != 1) {
                    y4 = value10 & 0xFF;
                } else {
                    y4 = (value10 & 0xFF) + 1;
                }
                BUS8_SET(c, (RAM8(0x0003 + (uint16_t)(sp0 - 7)) << 0x10) + RAM16(0x0001 + (uint16_t)(sp0 - 7)) + y4, value11 >> 8);
                a_hi4 = value12;
            }
            uint8_t value13 = RAM8(0x0000 + sp0 - 9);
            uint8_t value14 = RAM8(0x0000 + sp0 - 8);
            a_hi3 = a_hi4;
            x2 = value10 & 0xFF;
            y3 = (value14 << 8) | value13;
            continue;
        }
        a_hi3 = 0;
        break;
    }
    uint8_t value15 = RAM8(0x0000 + sp0 - 7);
    uint8_t value19 = RAM8(0x0000 + sp0 - 3);
    uint8_t value20 = RAM8(0x0000 + sp0 - 2);
    uint8_t value21 = RAM8(0x0000 + sp0 - 1);
    uint8_t value22 = RAM8(0x0000 + sp0);
    r->a = (a_hi3 << 8) | value19;
    r->x = x2;
    r->y = y3;
    r->c = value20 & 0x01;
    r->z = ((value22 << 8) | value21) == 0;
    r->n = ((value22 << 8) | value21) & 0x8000;
    r->v = value20 & 0x40;
    r->mf = value20 & 0x20;
    r->xf = value20 & 0x10;
    r->db = value15;
    r->dp = (value22 << 8) | value21;
    r->i = value20 & 0x04;
    r->d = value20 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC0FD, SOM_RTS, "gen", write_ppu_queue_entries, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 10, -1, 0, 142, 77)
