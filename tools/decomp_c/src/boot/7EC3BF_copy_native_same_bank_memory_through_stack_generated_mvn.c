#include "som_c.h"

/* 7EC3BF copy_native_same_bank_memory_through_stack_generated_mvn   [class C, 143 bytes, 84 instructions]
 * Source: src/boot/copy_native_same_bank_memory_through_stack_generated_mvn.s
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: BXYCV.
 */
static void copy_native_same_bank_memory_through_stack_generated_mvn(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t m_entry = r->mf;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    if ((uint32_t)(uint16_t)(sp0 - 9) + 0x6 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = (((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    if (value != 0) {
        if (value < 0x15) {
            uint16_t x4;
            uint16_t y4;
            if ((value & 1) == 0) {
                RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), value >> 1);
                uint8_t a_hi1 = value >> 1 >> 8;
                uint16_t x1 = x;
                uint16_t y1 = y;
                do {
                    uint16_t value2 = BUS16_RDP(c, (db << 0x10) + x1);
                    BUS16_SET(c, (db << 0x10) + y1, value2);
                    RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), (uint16_t)(RAM16(0x0005 + (uint16_t)(sp0 - 9)) - 1));
                    a_hi1 = value2 >> 8;
                    x1 = (uint16_t)(x1 + 2);
                    y1 = (uint16_t)(y1 + 2);
                } while (RAM16(0x0005 + (uint16_t)(sp0 - 9)) != 0);
                x4 = x1;
                y4 = y1;
            } else {
                RAM8(0x0000 + sp0 - 9) = value >> 8;
                RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)value;
                uint8_t value3 = BUS8_RDP(c, (db << 0x10) + x);
                BUS8_SET(c, (db << 0x10) + y, value3);
                uint8_t value4 = RAM8(0x0000 + sp0 - 0x0A);
                uint8_t value5 = RAM8(0x0000 + sp0 - 9);
                uint16_t x3;
                uint16_t y3;
                if ((uint16_t)(((value5 << 8) | value4) - 1) == 0) {
                    x3 = (uint16_t)(x + 1);
                    y3 = (uint16_t)(y + 1);
                } else {
                    RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), (uint16_t)(((value5 << 8) | value4) - 1) >> 1);
                    uint8_t a_hi2 = (uint16_t)(((value5 << 8) | value4) - 1) >> 1 >> 8;
                    uint16_t x2 = (uint16_t)(x + 1);
                    uint16_t y2 = (uint16_t)(y + 1);
                    do {
                        uint16_t value6 = BUS16_RDP(c, (db << 0x10) + x2);
                        BUS16_SET(c, (db << 0x10) + y2, value6);
                        RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), (uint16_t)(RAM16(0x0005 + (uint16_t)(sp0 - 9)) - 1));
                        a_hi2 = value6 >> 8;
                        x2 = (uint16_t)(x2 + 2);
                        y2 = (uint16_t)(y2 + 2);
                    } while (RAM16(0x0005 + (uint16_t)(sp0 - 9)) != 0);
                    x3 = x2;
                    y3 = y2;
                }
                x4 = x3;
                y4 = y3;
            }
            uint8_t value7 = RAM8(0x0000 + sp0 - 2);
            uint8_t value8 = RAM8(0x0000 + sp0 - 1);
            uint8_t value9 = RAM8(0x0000 + sp0);
            r->a = (uint16_t)((uint16_t)(sp0 - 9) + 6);
            r->x = x4;
            r->y = y4;
            r->c = value7 & 0x01;
            r->v = value7 & 0x40;
            r->mf = value7 & 0x20;
            r->xf = value7 & 0x10;
            r->dp = (value9 << 8) | value8;
            r->i = value7 & 0x04;
            r->d = value7 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        RAM8(0x0000 + sp0 - 9) = db;
        RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), (uint16_t)(value - 1));
        RAM8(0x0001 + (uint16_t)(sp0 - 9)) = 0x54;
        RAM8(0x0002 + (uint16_t)(sp0 - 9)) = RAM8(0x0000 + sp0 - 9);
        RAM8(0x0003 + (uint16_t)(sp0 - 9)) = RAM8(0x0000 + sp0 - 9);
        RAM8(0x0004 + (uint16_t)(sp0 - 9)) = 0x6B;
        RAM8(0x0006 + (uint16_t)(sp0 - 9))++;
        RAM8(0x0000 + sp0 - 0x0A) = ((((RAM8(0x0006 + (uint16_t)(sp0 - 9)) >> 7 << 7) | (((((uint16_t)(sp0 - 5) ^ 4) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0) << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | ((RAM8(0x0006 + (uint16_t)(sp0 - 9)) == 0) << 1) | value >= 0x15;
        RAM8(0x0000 + sp0 - 0x0B) = 0x7E;
        RAM8(0x0000 + sp0 - 0x0C) = 0xC4;
        RAM8(0x0000 + sp0 - 0x0D) = 0x11;
        RAM8(0x0000 + sp0 - 0x0E) = 0;
        RAM8(0x0000 + sp0 - 0x0F) = (uint16_t)(sp0 - 9) >> 8;
        RAM8(0x0000 + sp0 - 0x10) = (uint8_t)(sp0 - 9);
        uint8_t value13 = RAM8(0x0005 + (uint16_t)(sp0 - 9));
        r->a = value13;
        r->c = (uint16_t)(sp0 - 9) > 0xFFFF;
        r->z = value13 == 0;
        r->n = value13 & 0x80;
        r->v = (((uint16_t)(sp0 - 9) ^ (uint16_t)(sp0 - 9)) & (uint16_t)(sp0 - 9) & 0x8000) != 0;
        r->mf = 1;
        r->dp = (uint16_t)(sp0 - 9);
        r->i = 1;
        TAIL_CALL_FRAME(c, (0 << 16) | (uint16_t)((uint16_t)(sp0 - 9) + 1), SOM_RTS, 14); /* jump through a pushed address */
    }
    r->a = (uint16_t)((uint16_t)(sp0 - 9) + 6);
    r->mf = m_entry;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC3BF, SOM_RTS, "gen", copy_native_same_bank_memory_through_stack_generated_mvn, 0, L_B | L_X | L_Y | L_C | L_V, 17, -1, 0, 143, 84)
