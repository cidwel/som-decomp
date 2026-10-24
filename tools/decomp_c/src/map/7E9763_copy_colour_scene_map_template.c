#include "som_c.h"

/* 7E9763 copy_colour_scene_map_template   [class B, 48 bytes, 33 instructions]
 * Source: src/boot/copy_colour_scene_map_template.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=$7F D=$05DC.  Callers read: YCV.
 */
static void copy_colour_scene_map_template(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x05DC) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0xDC;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = 1;
    RAM8(0x0000 + sp0 - 7) = 0;
    RAM8(0x0000 + sp0 - 8) = 0x7E;
    RAM8(0x0000 + sp0 - 9) = 0x50;
    RAM8(0x0000 + sp0 - 0x0A) = 0xC0;
    RAM8(0x0000 + sp0 - 0x0B) = 0x7F;
    RAM8(0x0000 + sp0 - 0x0C) = x >> 8;
    RAM8(0x0000 + sp0 - 0x0D) = (uint8_t)x;
    r->y = 0x50C0;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 14;
    JSR(c, 0x9782, 0x7EC44E); /* copy_far_stack_arguments */
    r->sp += 14;
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->c = carry;
    r->v = overflow;
    r->mf = 0;
    r->xf = 0;
    r->dp = (value4 << 8) | value3;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E9763, SOM_RTS, "gen", copy_colour_scene_map_template, 0, L_Y | L_C | L_V, 14, 0, 0, 48, 33)
