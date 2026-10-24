#include "som_c.h"

/* D3F567 advance_spell_frame_signed_velocity   [class B, 81 bytes, 43 instructions]
 * Source: src/rom/advance_spell_frame_signed_velocity.s
 * Documented in docs/map-oam-spell-frames.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$01DA.  Callers read: XY.
 */
static void advance_spell_frame_signed_velocity(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x01DA) { c->fail = 3; return; }
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
    RAM8(0x0000 + sp0 - 1) = 0xDA;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0004 + (uint16_t)(sp0 - 7)) = 1;
    RAM8(0x0003 + (uint16_t)(sp0 - 7)) = RAM8(0x0000 + y);
    uint16_t value2 = RAM16(0x0000 + x);
    uint16_t value3 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
    RAM16_SET(0x0000 + x, (uint16_t)(value2 + value3));
    if (value2 + value3 > 0xFFFF) {
        RAM8(0x0002 + x) = 0;
    }
    uint8_t value4 = RAM8(0x0003 + y);
    RAM8(0x0001 + (uint16_t)(sp0 - 7)) = value4;
    RAM8(0x0002 + (uint16_t)(sp0 - 7)) = 0;
    if ((value4 & 0x80) != 0) {
        RAM8(0x0002 + (uint16_t)(sp0 - 7))--;
    }
    uint16_t value5 = RAM16(0x0003 + x);
    uint16_t value6 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
    RAM16_SET(0x0003 + x, (uint16_t)(value5 + value6));
    RAM8(0x0005 + x) = (uint8_t)(RAM8(0x0005 + x) + RAM8(0x0002 + (uint16_t)(sp0 - 7)) + (value5 + value6 > 0xFFFF));
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3F567, SOM_RTS, "gen", advance_spell_frame_signed_velocity, 0, L_X | L_Y, 7, 0, 0, 81, 43)
