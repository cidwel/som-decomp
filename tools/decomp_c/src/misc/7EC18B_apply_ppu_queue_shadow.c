#include "som_c.h"

/* 7EC18B apply_ppu_queue_shadow   [class B, 208 bytes, 104 instructions]
 * Source: src/boot/apply_ppu_queue_shadow.s
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: BXYCZNV.
 */
static void apply_ppu_queue_shadow(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = (((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = db;
    RAM8(0x0000 + sp0 - 6) = 0x7F;
    uint16_t value = RAM16(0x102E2);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), value);
    uint8_t a_hi1 = value >> 8;
    uint16_t x1 = x;
    uint16_t y1 = 0x02DA;
    for (;;) {
        uint16_t value2 = BUS16(c, 0x7F0001 + y1);
        if ((value2 & 0xFF) != 0) {
            uint16_t value3 = RAM16(0x102D6);
            RAM8(0x0000 + sp0 - 6) = (uint16_t)((value2 & 0xFF) + value3) >> 8;
            RAM8(0x0000 + sp0 - 7) = (uint8_t)((value2 & 0xFF) + value3);
            uint16_t value4 = BUS16(c, 0x7F0000 + (uint16_t)((value2 & 0xFF) + value3));
            uint16_t value5 = BUS16(c, 0x7F0002 + (uint16_t)((value2 & 0xFF) + value3));
            BUS8_SET(c, RAM16(0x0001 + (uint16_t)(sp0 - 5)) + 0x7F0000 + (value4 & 0xFF), (uint8_t)value5);
            uint8_t value6 = RAM8(0x603E + (value4 & 0xFF));
            uint8_t a_hi3;
            if (value6 == 0) {
                a_hi3 = value5 >> 8;
            } else {
                uint8_t a_hi2;
                if (value6 != 1) {
                    uint8_t value7 = BUS8_RDP(c, RAM16(0x0001 + (uint16_t)(sp0 - 5)) + 0x7F0000 + (value4 & 0xFF));
                    RAM8(0x0000 + sp0 - 8) = value5 >> 8;
                    RAM8(0x0000 + sp0 - 9) = (uint8_t)((value5 >> 8 << 8) | value7);
                    BUS16_SET(c, RAM16(0x0001 + (uint16_t)(sp0 - 5)) + 0x7F0000 + (RAM16(0x603E + (value4 & 0xFF)) & 0xFF), (value5 >> 8 << 8) | value7);
                    a_hi2 = value5 >> 8;
                } else {
                    BUS8_SET(c, RAM16(0x0001 + (uint16_t)(sp0 - 5)) + 0x7F0000 + ((value4 & 0xFF) + 1), value5 >> 8);
                    a_hi2 = value6;
                }
                a_hi3 = a_hi2;
            }
            uint8_t value9 = RAM8(0x0000 + sp0 - 7);
            uint8_t value10 = RAM8(0x0000 + sp0 - 6);
            a_hi1 = a_hi3;
            x1 = value4 & 0xFF;
            y1 = (value10 << 8) | value9;
            continue;
        }
        a_hi1 = 0;
        break;
    }
    uint8_t a_hi4 = a_hi1;
    uint16_t x2 = x1;
    uint16_t y2 = 0x02DE;
    for (;;) {
        uint16_t value11 = BUS16(c, 0x7F0001 + y2);
        if ((value11 & 0xFF) != 0) {
            uint16_t value12 = RAM16(0x102D6);
            RAM8(0x0000 + sp0 - 6) = (uint16_t)((value11 & 0xFF) + value12) >> 8;
            RAM8(0x0000 + sp0 - 7) = (uint8_t)((value11 & 0xFF) + value12);
            uint8_t a_hi5;
            if (y2 == 0x02DE) {
                a_hi5 = (uint16_t)((value11 & 0xFF) + value12) >> 8;
            } else {
                uint16_t value13 = RAM16(0x102D8);
                BUS16_SET(c, 0x7F0000 + y2, value13);
                RAM16_SET(0x102D8, y2);
                a_hi5 = value13 >> 8;
            }
            uint16_t value14 = BUS16(c, 0x7F0000 + (uint16_t)((value11 & 0xFF) + value12));
            uint16_t value15 = BUS16(c, 0x7F0002 + (uint16_t)((value11 & 0xFF) + value12));
            BUS8_SET(c, RAM16(0x0001 + (uint16_t)(sp0 - 5)) + 0x7F0000 + (value14 & 0xFF), (uint8_t)value15);
            uint8_t value16 = RAM8(0x603E + (value14 & 0xFF));
            uint8_t a_hi7;
            if (value16 == 0) {
                a_hi7 = value15 >> 8;
            } else {
                uint8_t a_hi6;
                if (value16 != 1) {
                    uint8_t value17 = BUS8_RDP(c, RAM16(0x0001 + (uint16_t)(sp0 - 5)) + 0x7F0000 + (value14 & 0xFF));
                    RAM8(0x0000 + sp0 - 8) = value15 >> 8;
                    RAM8(0x0000 + sp0 - 9) = (uint8_t)((value15 >> 8 << 8) | value17);
                    BUS16_SET(c, RAM16(0x0001 + (uint16_t)(sp0 - 5)) + 0x7F0000 + (RAM16(0x603E + (value14 & 0xFF)) & 0xFF), (value15 >> 8 << 8) | value17);
                    a_hi6 = value15 >> 8;
                } else {
                    BUS8_SET(c, RAM16(0x0001 + (uint16_t)(sp0 - 5)) + 0x7F0000 + ((value14 & 0xFF) + 1), value15 >> 8);
                    a_hi6 = value16;
                }
                a_hi7 = a_hi6;
            }
            uint8_t value19 = RAM8(0x0000 + sp0 - 7);
            uint8_t value20 = RAM8(0x0000 + sp0 - 6);
            a_hi4 = a_hi7;
            x2 = value14 & 0xFF;
            y2 = (value20 << 8) | value19;
            continue;
        }
        a_hi4 = 0;
        break;
    }
    uint8_t a_hi8;
    if (y2 == 0x02DE) {
        a_hi8 = a_hi4;
    } else {
        uint16_t value21 = RAM16(0x102D8);
        BUS16_SET(c, 0x7F0000 + y2, value21);
        RAM16_SET(0x102D8, y2);
        a_hi8 = value21 >> 8;
    }
    RAM16_SET(0x102DE, 0);
    RAM16_SET(0x102E0, 0x02DE);
    uint8_t value22 = RAM8(0x0000 + sp0 - 5);
    uint8_t value24 = RAM8(0x0000 + sp0 - 3);
    uint8_t value25 = RAM8(0x0000 + sp0 - 2);
    uint8_t value26 = RAM8(0x0000 + sp0 - 1);
    uint8_t value27 = RAM8(0x0000 + sp0);
    r->a = (2 << 8) | value24;
    r->x = x2;
    r->y = y2;
    r->c = value25 & 0x01;
    r->z = ((value27 << 8) | value26) == 0;
    r->n = ((value27 << 8) | value26) & 0x8000;
    r->v = value25 & 0x40;
    r->mf = value25 & 0x20;
    r->xf = value25 & 0x10;
    r->db = value22;
    r->dp = (value27 << 8) | value26;
    r->i = value25 & 0x04;
    r->d = value25 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC18B, SOM_RTS, "gen", apply_ppu_queue_shadow, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 10, -1, 0, 208, 104)
