#include "som_c.h"

/* C23057 initialize_boss_random_seed_pool_and_two_separated_indices   [class B, 52 bytes, 24 instructions]
 * Source: src/rom/initialize_boss_random_seed_pool_and_two_separated_indices.s
 * Documented in docs/boss-frame-random-initialize.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XYCV.
 */
static void initialize_boss_random_seed_pool_and_two_separated_indices(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0x033D) = (uint8_t)a;
    uint8_t a_hi1 = a >> 8;
    uint8_t x1 = 0;
    bool carry1 = carry;
    for (;;) {
        uint8_t value = BUS8(c, 0xC2308B + x1);
        RAM8(0x0306 + x1) = value;
        uint8_t x1_next = (uint8_t)(x1 + 1);
        bool carry1_next = (uint8_t)(x1 + 1) >= 0x37;
        x1 = x1_next;
        carry1 = carry1_next;
        if (!(x1 != 0x37)) break;
    }
    RAM8(0x0246) = RAM8(0x033D);
    RAM8(0x024E) = 0x37;
    r->a = (a_hi1 << 8) | 0x37;
    r->x = x1;
    r->y = (uint8_t)y;
    r->c = carry1;
    r->v = overflow;
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0x3075, 0xC22AA6); /* multiply_boss_terrain_row_stride */
    uint8_t value3 = RAM8(0x0257);
    RAM8(0x033D) = value3;
    uint8_t a1;
    bool overflow1;
    if ((uint8_t)(value3 + 0x1F) < 0x37) {
        a1 = (uint8_t)(value3 + 0x1F);
        overflow1 = ((value3 ^ (uint8_t)(value3 + 0x1F)) & ((uint8_t)(value3 + 0x1F) ^ 0x1F) & 0x80) != 0;
    } else {
        a1 = (uint8_t)((uint8_t)(value3 + 0x1F) - 0x37);
        overflow1 = (((uint8_t)(value3 + 0x1F) ^ 0x37) & ((uint8_t)(value3 + 0x1F) ^ (uint8_t)((uint8_t)(value3 + 0x1F) - 0x37)) & 0x80) != 0;
    }
    RAM8(0x033E) = a1;
    r->c = (uint8_t)(value3 + 0x1F) >= 0x37;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23057, SOM_RTS, "gen", initialize_boss_random_seed_pool_and_two_separated_indices, 0, L_X | L_Y | L_C | L_V, 1, 0, 0, 52, 24)
