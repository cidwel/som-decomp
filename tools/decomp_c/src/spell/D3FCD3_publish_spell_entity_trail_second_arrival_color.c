#include "som_c.h"

/* D3FCD3 publish_spell_entity_trail_second_arrival_color   [class A, 34 bytes, 17 instructions]
 * Source: src/rom/publish_spell_entity_trail_second_arrival_color.s
 * Documented in docs/actor-cast-entity-trail-state.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void publish_spell_entity_trail_second_arrival_color(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp; /* the prologue pushes are real stack bytes */
    RAM8(sp0 - 0) = r->dp >> 8;
    RAM8(sp0 - 1) = (uint8_t)r->dp;
    RAM8(sp0 - 2) = (r->n << 7) | (r->v << 6) | (r->mf << 5) | (r->xf << 4) | (r->d << 3) | (r->i << 2) | (r->z << 1) | r->c;
    RAM8(sp0 - 3) = r->y >> 8;
    RAM8(sp0 - 4) = (uint8_t)r->y;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    r->a = (a_hi << 8) | 0x31;
    r->z = 0;
    r->n = 0;
    r->sp -= 5;
    JSL(c, 0xFCDF, 0xC12ED5); /* allocate_spell_entity_register_record_long */
    r->sp += 5;
    uint16_t x_ret = r->x;
    RAM8(0x0002 + x_ret) = 0x83;
    r->z = 0;
    r->n = 1;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 5;
    JSL(c, 0xFCE8, 0xC12ED9); /* append_spell_entity_transient_register_record_long */
    r->sp += 5;
    RAM8(0x0152 + y) = 1;
    RAM8(0x0154 + y)++;
    SET_A8(r, 1);
    r->x = y;
    r->c = carry;
    r->z = dp == 0;
    r->n = dp & 0x8000;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3FCD3, SOM_RTS, "hand", publish_spell_entity_trail_second_arrival_color, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 34, 17)
