#include "som_c.h"

/* 7E9875 integrate_native_title_particle_signed_fractional_positions   [class B, 58 bytes, 31 instructions]
 * Source: src/boot/integrate_native_title_particle_signed_fractional_positions.s
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: YCV.
 */
static void integrate_native_title_particle_signed_fractional_positions(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->mf = 1;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x987A, 0x7E9793); GUARD_JSR(c, sp_call, 0x987A); } /* publish_nine_native_title_particle_sprites_from_frame_offsets */
    r->sp += 1;
    uint16_t dp_ret = r->dp;
    if (r->mf != 1) { c->fail = 3; return; }
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
    uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret + 6));
    BUS8_SET(c, (uint16_t)(dp_ret + 6), (uint8_t)(value + value2));
    uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 3));
    uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 7));
    BUS8_SET(c, (uint16_t)(dp_ret + 7), (uint8_t)(value3 + value4 + (value + value2 > 0xFF)));
    uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp_ret + 3));
    uint8_t a1;
    if ((value5 & 0x80) == 0) {
        a1 = value5 & 0x80;
    } else {
        a1 = 0xFF;
    }
    uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp_ret + 8));
    BUS8_SET(c, (uint16_t)(dp_ret + 8), (uint8_t)(a1 + value6 + (value3 + value4 + (value + value2 > 0xFF) > 0xFF)));
    uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret + 4));
    uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp_ret + 9));
    BUS8_SET(c, (uint16_t)(dp_ret + 9), (uint8_t)(value7 + value8));
    uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret + 5));
    uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x0A));
    BUS8_SET(c, (uint16_t)(dp_ret + 0x0A), (uint8_t)(value9 + value10 + (value7 + value8 > 0xFF)));
    uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp_ret + 5));
    uint8_t a2;
    if ((value11 & 0x80) == 0) {
        a2 = value11 & 0x80;
    } else {
        a2 = 0xFF;
    }
    uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x0B));
    BUS8_SET(c, (uint16_t)(dp_ret + 0x0B), (uint8_t)(a2 + value12 + (value9 + value10 + (value7 + value8 > 0xFF) > 0xFF)));
    uint8_t value13 = RAM8(0x0000 + sp0);
    r->c = value13 & 0x01;
    r->v = value13 & 0x40;
    r->mf = value13 & 0x20;
    r->xf = value13 & 0x10;
    r->i = value13 & 0x04;
    r->d = value13 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E9875, SOM_RTS, "gen", integrate_native_title_particle_signed_fractional_positions, 0, L_Y | L_C | L_V, 1, 0, 0, 58, 31)
