#include "som_c.h"

/* 7EA12E initialize_colour_decoder   [class A, 32 bytes, 20 instructions]
 * Source: src/boot/initialize_colour_decoder.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$05F1.  Callers read: XCV.
 */
static void initialize_colour_decoder(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x05F1) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0xF1;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    BUS8_SET(c, 0x7F0002 + x, (uint8_t)a);
    BUS16_SET(c, 0x7F0000 + x, y);
    BUS16_SET(c, 0x7F0004 + x, 0);
    BUS16_SET(c, 0x7F0006 + x, 0);
    uint8_t value = RAM8(0x0000 + sp0 - 3);
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->c = value2 & 0x01;
    r->v = value2 & 0x40;
    r->mf = value2 & 0x20;
    r->xf = value2 & 0x10;
    r->db = value;
    r->dp = (value4 << 8) | value3;
    r->i = value2 & 0x04;
    r->d = value2 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EA12E, SOM_RTS, "gen", initialize_colour_decoder, 0, L_X | L_C | L_V, 6, 0, 0, 32, 20)
