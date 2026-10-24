#include "som_c.h"

/* C104D3 resolve_controller_hero_actor   [class B, 47 bytes, 26 instructions]
 * Source: src/rom/resolve_controller_hero_actor.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$01DF.  Callers read: ABXYV.
 */
static void resolve_controller_hero_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01DF) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xDF;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint16_t value = RAM16(0x00D9 + (((a_hi << 8) | a) & 3));
    r->a = value & 7;
    r->x = value & 7;
    r->z = (value & 7) == 0;
    r->n = value & 7 & 0x8000;
    r->mf = 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0x04E6, 0xC12710); GUARD_JSR(c, sp_call, 0x04E6); } /* highest_set_bit_index */
    r->sp += 5;
    uint16_t a_all = r->a;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    if ((uint8_t)a_all == 0xFF) {
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = 0;
    } else {
        a1 = (uint8_t)(((((a_all & 3) << 8) | 0) << 1) + 0xE000);
        a_hi1 = (uint16_t)(((((a_all & 3) << 8) | 0) << 1) + 0xE000) >> 8;
        x1 = (uint16_t)(((((a_all & 3) << 8) | 0) << 1) + 0xE000);
    }
    uint8_t value2 = RAM8(0x0000 + sp0 - 2);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->v = value2 & 0x40;
    r->mf = value2 & 0x20;
    r->xf = value2 & 0x10;
    r->dp = (value4 << 8) | value3;
    r->i = value2 & 0x04;
    r->d = value2 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC104D3, SOM_RTS, "gen", resolve_controller_hero_actor, 0, L_A | L_B | L_X | L_Y | L_V, 5, 1, 0, 47, 26)
