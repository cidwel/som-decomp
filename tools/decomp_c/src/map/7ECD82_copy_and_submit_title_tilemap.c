#include "som_c.h"

/* 7ECD82 copy_and_submit_title_tilemap   [class B, 61 bytes, 34 instructions]
 * Source: src/boot/copy_and_submit_title_tilemap.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7F D=$02EE.  Callers read: ABXYCZNV.
 */
static void copy_and_submit_title_tilemap(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x02EE) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xEE;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = x >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)x;
    RAM8(0x0003 + (uint16_t)(sp0 - 6)) = RAM8(0x10310);
    uint16_t value2 = RAM16(0x10306);
    RAM8(0x0002 + (uint16_t)(sp0 - 6)) = 0x1D;
    uint8_t a_hi1 = (uint16_t)(sp0 - 6) >> 8;
    uint16_t x1 = x;
    uint16_t y1 = value2;
    do {
        RAM8(0x0001 + (uint16_t)(sp0 - 6)) = 0x20;
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = x1;
        uint16_t y2 = y1;
        do {
            RAM8(0x10000 + y2) = RAM8(0x64A6 + x2);
            RAM8(0x10000 + (uint16_t)(y2 + 1)) = RAM8(0x0003 + (uint16_t)(sp0 - 6));
            RAM8(0x0001 + (uint16_t)(sp0 - 6))--;
            x2 = (uint16_t)(x2 + 1);
            y2 = (uint16_t)(y2 + 2);
        } while (RAM8(0x0001 + (uint16_t)(sp0 - 6)) != 0);
        RAM8(0x0002 + (uint16_t)(sp0 - 6))--;
        a_hi1 = a_hi2;
        x1 = x2;
        y1 = y2;
    } while (RAM8(0x0002 + (uint16_t)(sp0 - 6)) != 0);
    uint16_t value5 = RAM16(0x10306);
    r->x = value5;
    r->y = y1;
    r->c = carry;
    r->z = value5 == 0;
    r->n = value5 & 0x8000;
    r->v = overflow;
    r->dp = (uint16_t)(sp0 - 6);
    r->sp -= 6;
    JSR(c, 0xCDB8, 0x7EC870); /* queue_registered_vram_buffer */
    r->sp += 6;
    uint8_t value8 = RAM8(0x0000 + sp0 - 3);
    uint8_t value9 = RAM8(0x0000 + sp0 - 1);
    uint8_t value10 = RAM8(0x0000 + sp0);
    SET_A8(r, value8);
    r->c = carry;
    r->z = ((value10 << 8) | value9) == 0;
    r->n = ((value10 << 8) | value9) & 0x8000;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    r->dp = (value10 << 8) | value9;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ECD82, SOM_RTS, "gen", copy_and_submit_title_tilemap, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, 1, 0, 61, 34)
