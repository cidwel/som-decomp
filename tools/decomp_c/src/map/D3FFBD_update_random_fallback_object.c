#include "som_c.h"
#include "som_hand.h"

/* D3FFBD update_random_fallback_object   [class B, 35 bytes, 18 instructions]
 * Source: src/rom/update_random_fallback_object.s
 * Documented in docs/actor-cast-entity-fallback-lifecycle.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void update_random_fallback_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp; /* the prologue pushes are real stack bytes */
    RAM8(sp0 - 0) = r->dp >> 8;
    RAM8(sp0 - 1) = (uint8_t)r->dp;
    RAM8(sp0 - 2) = (r->n << 7) | (r->v << 6) | (r->mf << 5) | (r->xf << 4) | (r->d << 3) | (r->i << 2) | (r->z << 1) | r->c;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0x0148 + x, (uint16_t)(RAM16(0x0148 + x) - 1));
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (RAM16(0x0148 + x) != 0) {
        a1 = a;
        a_hi1 = a_hi;
        x1 = x;
        carry1 = carry;
        zero1 = RAM16(0x0148 + x) == 0;
        negative1 = RAM16(0x0148 + x) & 0x8000;
        overflow1 = overflow;
    } else {
        RAM16_SET(0x0148 + x, 1);
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->sp -= 3;
        JSR(c, 0xFFCE, 0xD3FEFB); /* spawn_random_fallback_particle */
        r->sp += 3;
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        bool carry_ret = r->c;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        bool overflow_ret = r->v;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        carry1 = carry_ret;
        zero1 = zero_ret;
        negative1 = negative_ret;
        overflow1 = overflow_ret;
    }
    r->x = x1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 5;
    JSR(c, 0xFFD2, 0xD3FE71); /* advance_random_fallback_particles */
    r->sp += 5;
    r->mf = 1;
    r->xf = 0;
    som_pull_p(c, sp0 - 2); /* PLP */
    r->dp = RAM8(sp0 - 1) | (RAM8(sp0) << 8); /* PLD */
    r->z = r->dp == 0;
    r->n = r->dp & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3FFBD, SOM_RTS, "hand", update_random_fallback_object, 0, 0, 5, 1, 0, 35, 18)
