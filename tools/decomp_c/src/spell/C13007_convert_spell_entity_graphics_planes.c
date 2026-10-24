#include "som_c.h"

/* C13007 convert_spell_entity_graphics_planes   [class A, 37 bytes, 25 instructions]
 * Source: src/rom/convert_spell_entity_graphics_planes.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: YCZNV.
 */
static void convert_spell_entity_graphics_planes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = a;
    RAM8(0x0000 + sp0 - 5) = 0xD4;
    RAM8(0x0000 + sp0 - 4) = a_hi;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)((a_hi << 8) | a);
    r->a = (a_hi << 8) | a;
    r->x = (uint16_t)(x - 0x2000);
    r->c = x >= 0x2000;
    r->z = ((a_hi << 8) | a) == 0;
    r->n = ((a_hi << 8) | a) & 0x8000;
    r->v = ((x ^ 0x2000) & (x ^ (uint16_t)(x - 0x2000)) & 0x8000) != 0;
    r->db = 0xD4;
    r->dp = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0x3027, 0x018009); GUARD_JSL(c, sp_call, 0x3027); } /* graphics_planes_public_jump */
    r->sp += 4;
    uint8_t value = RAM8(0x0000 + sp0 - 3);
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->c = value2 & 0x01;
    r->z = ((value4 << 8) | value3) == 0;
    r->n = ((value4 << 8) | value3) & 0x8000;
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
SOM_REGISTER(0xC13007, SOM_RTS, "gen", convert_spell_entity_graphics_planes, 0, L_Y | L_C | L_Z | L_N | L_V, 6, 1, 0, 37, 25)
