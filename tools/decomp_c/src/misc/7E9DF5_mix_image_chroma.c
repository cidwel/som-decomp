#include "som_c.h"

/* 7E9DF5 mix_image_chroma   [class B, 72 bytes, 45 instructions]
 * Source: src/boot/mix_image_chroma.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$05E5.  Callers read: CV.
 */
static void mix_image_chroma(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x05E5) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0xE5;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), 0x40);
    uint8_t a_hi1 = 0;
    uint16_t x1 = 0;
    uint16_t y1 = 0;
    do {
        uint16_t value = BUS16(c, 0x001B00 + x1);
        BUS16_SET(c, 0x001C00 + y1, value >> 1);
        RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), value >> 2);
        uint16_t value2 = BUS16(c, 0x001A00 + x1);
        BUS16_SET(c, 0x001C01 + y1, (uint16_t)(((uint16_t)((value2 >> 3) + RAM16(0x0003 + (uint16_t)(sp0 - 7))) ^ 0xFFFF) + 1));
        uint16_t value4 = BUS16(c, 0x001A00 + x1);
        BUS16_SET(c, 0x001C02 + y1, value4 >> 1);
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 7)) - 1));
        a_hi1 = value4 >> 1 >> 8;
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 + 4);
    } while (RAM16(0x0001 + (uint16_t)(sp0 - 7)) != 0);
    uint8_t value9 = RAM8(0x0000 + sp0 - 2);
    uint8_t value10 = RAM8(0x0000 + sp0 - 1);
    uint8_t value11 = RAM8(0x0000 + sp0);
    r->c = value9 & 0x01;
    r->v = value9 & 0x40;
    r->mf = value9 & 0x20;
    r->xf = value9 & 0x10;
    r->dp = (value11 << 8) | value10;
    r->i = value9 & 0x04;
    r->d = value9 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E9DF5, SOM_RTS, "gen", mix_image_chroma, 0, L_C | L_V, 7, 1, 0, 72, 45)
