#include "som_c.h"

/* 7EC097 append_oneshot_ppu_entry   [class B, 43 bytes, 26 instructions]
 * Source: src/boot/append_oneshot_ppu_entry.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$01F0.  Callers read: ABXYCZNV.
 */
static void append_oneshot_ppu_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x01F0) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xF0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    bool interrupt_disable;
    bool decimal_mode;
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t y1;
    if (x == 0) {
        interrupt_disable = i_entry;
        decimal_mode = d_entry;
        m_flag = 0;
        x_flag = 0;
        a1 = (uint8_t)x;
        a_hi1 = x >> 8;
        y1 = y;
    } else {
        RAM8(0x0000 + sp0 - 4) = ((((x >> 0x0F << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | ((x == 0) << 1) | carry;
        uint16_t value = RAM16(0x102D6);
        uint16_t value2 = RAM16(0x102E0);
        BUS8_SET(c, 0x7F0001 + value2, (uint8_t)(x - value));
        BUS8_SET(c, 0x7F0001 + x, 0);
        RAM16_SET(0x102E0, x);
        uint8_t value3 = RAM8(0x0000 + sp0 - 4);
        interrupt_disable = value3 & 0x04;
        decimal_mode = value3 & 0x08;
        m_flag = value3 & 0x20;
        x_flag = value3 & 0x10;
        a1 = (uint8_t)(x - value);
        a_hi1 = (uint16_t)(x - value) >> 8;
        y1 = value2;
    }
    uint8_t value4 = RAM8(0x0000 + sp0 - 3);
    uint8_t value5 = RAM8(0x0000 + sp0 - 2);
    uint8_t value6 = RAM8(0x0000 + sp0 - 1);
    uint8_t value7 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | a1;
    r->y = y1;
    r->c = value5 & 0x01;
    r->z = ((value7 << 8) | value6) == 0;
    r->n = ((value7 << 8) | value6) & 0x8000;
    r->v = value5 & 0x40;
    r->mf = value5 & 0x20;
    r->xf = value5 & 0x10;
    r->db = value4;
    r->dp = (value7 << 8) | value6;
    r->i = value5 & 0x04;
    r->d = value5 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC097, SOM_RTS, "gen", append_oneshot_ppu_entry, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 43, 26)
