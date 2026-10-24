#include "som_c.h"

/* 7E9F74 mix_convert_submit_image_group   [class B, 48 bytes, 20 instructions]
 * Source: src/boot/mix_convert_submit_image_group.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XYCV.
 */
static void mix_convert_submit_image_group(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9F7C, 0x7E9DF5); GUARD_JSR(c, sp_call, 0x9F7C); } /* mix_image_chroma */
    r->sp += 3;
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 0x1600;
    r->y = 0x1C00;
    r->z = 0;
    r->n = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9F85, 0x7E9E3D); GUARD_JSR(c, sp_call, 0x9F85); } /* expand_convert_submit_image_tile */
    r->sp += 3;
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 0x1700;
    r->y = 0x1C80;
    r->z = 0;
    r->n = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9F8E, 0x7E9E3D); GUARD_JSR(c, sp_call, 0x9F8E); } /* expand_convert_submit_image_tile */
    r->sp += 3;
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 0x1800;
    r->y = 0x1C90;
    r->z = 0;
    r->n = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9F97, 0x7E9E3D); GUARD_JSR(c, sp_call, 0x9F97); } /* expand_convert_submit_image_tile */
    r->sp += 3;
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 0x1900;
    r->y = 0x1C10;
    r->z = 0;
    r->n = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9FA0, 0x7E9E3D); GUARD_JSR(c, sp_call, 0x9FA0); } /* expand_convert_submit_image_tile */
    r->sp += 3;
    uint8_t value = RAM8(0x0000 + sp0 - 2);
    uint8_t value2 = RAM8(0x0000 + sp0 - 1);
    uint8_t value3 = RAM8(0x0000 + sp0);
    r->c = value & 0x01;
    r->v = value & 0x40;
    r->mf = value & 0x20;
    r->xf = value & 0x10;
    r->dp = (value3 << 8) | value2;
    r->i = value & 0x04;
    r->d = value & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E9F74, SOM_RTS, "gen", mix_convert_submit_image_group, 0, L_X | L_Y | L_C | L_V, 3, 1, 0, 48, 20)
