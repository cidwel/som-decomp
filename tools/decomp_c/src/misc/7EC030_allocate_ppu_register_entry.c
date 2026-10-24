#include "som_c.h"

/* 7EC030 allocate_ppu_register_entry   [class B, 71 bytes, 41 instructions]
 * Source: src/boot/allocate_ppu_register_entry.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$01F0.  Callers read: BXYCZNV.
 */
static void allocate_ppu_register_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x01F0) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xF0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = a;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    uint16_t value = RAM16(0x102D8);
    bool interrupt_disable;
    bool decimal_mode;
    bool m_flag;
    bool x_flag;
    uint8_t a_hi1;
    uint16_t y1;
    if (value == 0) {
        interrupt_disable = i_entry;
        decimal_mode = d_entry;
        m_flag = 0;
        x_flag = 0;
        a_hi1 = a_hi;
        y1 = y;
    } else {
        RAM8(0x0000 + sp0 - 4) = ((((value >> 0x0F << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | ((value == 0) << 1) | carry;
        RAM8(0x0000 + sp0 - 5) = 0;
        RAM8(0x0000 + sp0 - 6) = ((a_hi << 8) | a) & 0xFF;
        uint16_t value2 = BUS16(c, 0x7F0000 + value);
        RAM16_SET(0x102D8, value2);
        BUS16_SET(c, 0x7F0000 + value, ((a_hi << 8) | a) & 0xFF);
        uint16_t value3 = RAM16(0x603E + (((a_hi << 8) | a) & 0xFF));
        uint16_t x2;
        if ((value3 & 0xFF) == 0) {
            x2 = ((a_hi << 8) | a) & 0xFF;
        } else {
            uint16_t x1;
            if ((value3 & 0xFF) == 1) {
                x1 = ((a_hi << 8) | a) & 0xFF;
            } else {
                x1 = value3 & 0xFF;
            }
            x2 = x1;
        }
        uint16_t value5 = BUS16(c, 0x7F0000 + (uint16_t)(x2 + RAM16(0x102E2)));
        BUS16_SET(c, 0x7F0002 + value, value5);
        uint8_t value6 = RAM8(0x0000 + sp0 - 4);
        interrupt_disable = value6 & 0x04;
        decimal_mode = value6 & 0x08;
        m_flag = value6 & 0x20;
        x_flag = value6 & 0x10;
        a_hi1 = value5 >> 8;
        y1 = value;
    }
    uint8_t value7 = RAM8(0x0000 + sp0 - 3);
    uint8_t value8 = RAM8(0x0000 + sp0 - 2);
    uint8_t value9 = RAM8(0x0000 + sp0 - 1);
    uint8_t value10 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | a;
    r->x = value;
    r->y = y1;
    r->c = value8 & 0x01;
    r->z = ((value10 << 8) | value9) == 0;
    r->n = ((value10 << 8) | value9) & 0x8000;
    r->v = value8 & 0x40;
    r->mf = value8 & 0x20;
    r->xf = value8 & 0x10;
    r->db = value7;
    r->dp = (value10 << 8) | value9;
    r->i = value8 & 0x04;
    r->d = value8 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC030, SOM_RTS, "gen", allocate_ppu_register_entry, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 7, 1, 0, 71, 41)
