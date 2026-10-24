#include "som_c.h"

/* C14C30 decompress_block   [class C, 144 bytes, 89 instructions]
 * Source: src/rom/decompress_block.s
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void decompress_block(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 0x36) + 0x2D > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = (((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 0x36) = db;
    RAM8(0x0000 + sp0 - 0x37) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x38) = 0x7F;
    RAM8(0x0000 + sp0 - 0x37) = y >> 8;
    RAM8(0x0000 + sp0 - 0x38) = (uint8_t)y;
    RAM8(0x0000 + sp0 - 0x39) = x >> 8;
    RAM8(0x0000 + sp0 - 0x3A) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 0x3B) = value >> 8;
    RAM8(0x0000 + sp0 - 0x3C) = (uint8_t)value;
    r->a = 0x29;
    r->x = 0x4C06;
    r->y = (uint16_t)((uint16_t)(sp0 - 0x36) + 8);
    r->c = (uint16_t)(sp0 - 0x36) + 8 > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 0x36) ^ (uint16_t)((uint16_t)(sp0 - 0x36) + 8)) & ((uint16_t)((uint16_t)(sp0 - 0x36) + 8) ^ 8) & 0x8000) != 0;
    r->mf = 0;
    r->db = 0x7F;
    r->dp = (uint16_t)(sp0 - 0x36);
    i_mvn(c, 0xC1, 0x00); /* copy up bank $C1 to bank $00 */
    uint8_t value2 = RAM8(0x0000 + sp0 - 0x3C);
    uint8_t value3 = RAM8(0x0000 + sp0 - 0x3B);
    RAM8(0x0000 + sp0 - 0x3B) = (uint8_t)((value3 << 8) | value2);
    RAM8(0x002D + (uint16_t)(sp0 - 0x36)) = (uint8_t)((value3 << 8) | value2);
    RAM8(0x002C + (uint16_t)(sp0 - 0x36)) = value3;
    RAM8(0x001D + (uint16_t)(sp0 - 0x36)) = value3;
    RAM8(0x001E + (uint16_t)(sp0 - 0x36)) = value3;
    RAM8(0x0002 + (uint16_t)(sp0 - 0x36)) = 0;
    uint16_t value4 = RAM16(0x0000 + sp0 - 0x3A);
    uint16_t value5 = BUS16_RDP(c, ((uint8_t)((value3 << 8) | value2) << 0x10) + 2 + value4);
    RAM16_SET(0x0005 + (uint16_t)(sp0 - 0x36), (uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) + RAM16(0x0000 + sp0 - 0x38)));
    uint8_t value7 = BUS8_RDP(c, ((uint8_t)((value3 << 8) | value2) << 0x10) + value4);
    RAM8(0x002A + (uint16_t)(sp0 - 0x36)) = (uint8_t)(value7 + RAM8(0x002A + (uint16_t)(sp0 - 0x36)));
    uint8_t value9 = BUS8_RDP(c, ((uint8_t)((value3 << 8) | value2) << 0x10) + value4);
    uint8_t value10 = BUS8(c, 0xC14C00 + value9);
    RAM8(0x0007 + (uint16_t)(sp0 - 0x36)) = value10;
    uint8_t value11 = RAM8(0x0000 + sp0 - 0x3A);
    uint8_t value12 = RAM8(0x0000 + sp0 - 0x39);
    uint8_t value13 = RAM8(0x0000 + sp0 - 0x38);
    uint8_t value14 = RAM8(0x0000 + sp0 - 0x37);
    RAM8(0x0000 + sp0 - 0x37) = 0xC1;
    RAM8(0x0000 + sp0 - 0x38) = 0x4C;
    RAM8(0x0000 + sp0 - 0x39) = 0xB3;
    RAM8(0x0000 + sp0 - 0x3A) = 0;
    RAM8(0x0000 + sp0 - 0x3B) = (uint16_t)((uint16_t)(sp0 - 0x36) + 0x23) >> 8;
    RAM8(0x0000 + sp0 - 0x3C) = (uint8_t)((uint16_t)(sp0 - 0x36) + 0x23);
    r->a = (uint16_t)((uint16_t)(sp0 - 0x36) + 0x23) >> 8;
    r->x = (uint16_t)(((value12 << 8) | value11) + 4);
    r->y = (value14 << 8) | value13;
    r->c = (uint16_t)(sp0 - 0x36) + 0x23 > 0xFFFF;
    r->z = (uint16_t)((uint16_t)(sp0 - 0x36) + 0x23) >> 8 == 0;
    r->n = (uint16_t)((uint16_t)(sp0 - 0x36) + 0x23) >> 8 & 0x80;
    r->v = (((uint16_t)(sp0 - 0x36) ^ (uint16_t)((uint16_t)(sp0 - 0x36) + 0x23)) & ((uint16_t)((uint16_t)(sp0 - 0x36) + 0x23) ^ 0x23) & 0x8000) != 0;
    r->mf = 1;
    r->db = (uint8_t)((value3 << 8) | value2);
    TAIL_CALL_FRAME(c, (0 << 16) | (uint16_t)((uint16_t)((uint16_t)(sp0 - 0x36) + 0x23) + 1), SOM_RTS, 58); /* jump through a pushed address */
}
SOM_REGISTER(0xC14C30, SOM_RTS, "gen", decompress_block, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 61, -1, 0, 144, 89)
