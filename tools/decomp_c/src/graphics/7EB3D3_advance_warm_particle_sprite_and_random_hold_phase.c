#include "som_c.h"

/* 7EB3D3 advance_warm_particle_sprite_and_random_hold_phase   [class B, 67 bytes, 31 instructions]
 * Source: src/boot/advance_warm_particle_sprite_and_random_hold_phase.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$06EC.  Callers read: BV.
 */
static void advance_warm_particle_sprite_and_random_hold_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x06EC) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 6;
    RAM8(0x0000 + sp0 - 1) = 0xEC;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t value = BUS8(c, 0x7F0002 + x);
    if (value < 7) {
        BUS8_SET(c, 0x7F0002 + x, (uint8_t)(BUS8(c, 0x7F0002 + x) + 1));
        uint16_t value2 = BUS16(c, 0x7F0000 + x);
        BUS8_SET(c, 0x7F0002 + value2, (uint8_t)(BUS8(c, 0x7F0002 + value2) + 1));
        BUS8_SET(c, 0x7F0004 + value2, (uint8_t)(BUS8(c, 0x7F0004 + value2) - 1));
        BUS8_SET(c, 0x7F0006 + value2, (uint8_t)(BUS8(c, 0x7F0006 + value2) + 1));
    } else {
        if (value == 7) {
            uint16_t value3 = BUS16(c, 0x7F0000 + x);
            BUS8_SET(c, 0x7F0002 + value3, (uint8_t)(BUS8(c, 0x7F0002 + value3) + 1));
            BUS8_SET(c, 0x7F0004 + value3, (uint8_t)(BUS8(c, 0x7F0004 + value3) - 1));
            BUS8_SET(c, 0x7F0004 + x, (uint8_t)(BUS8(c, 0x7F0004 + x) - 1));
            if (BUS8(c, 0x7F0004 + x) == 0) {
                BUS8_SET(c, 0x7F0002 + x, (uint8_t)(BUS8(c, 0x7F0002 + x) + 1));
            }
        } else {
            BUS8_SET(c, 0x7F0002 + x, (uint8_t)(BUS8(c, 0x7F0002 + x) + 1));
            uint16_t value4 = BUS16(c, 0x7F0000 + x);
            BUS8_SET(c, 0x7F0006 + value4, (uint8_t)(BUS8(c, 0x7F0006 + value4) - 1));
        }
    }
    uint8_t value5 = RAM8(0x0000 + sp0 - 2);
    uint8_t value6 = RAM8(0x0000 + sp0 - 1);
    uint8_t value7 = RAM8(0x0000 + sp0);
    r->v = value5 & 0x40;
    r->mf = value5 & 0x20;
    r->xf = value5 & 0x10;
    r->dp = (value7 << 8) | value6;
    r->i = value5 & 0x04;
    r->d = value5 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB3D3, SOM_RTS, "gen", advance_warm_particle_sprite_and_random_hold_phase, 0, L_B | L_V, 3, 1, 0, 67, 31)
