#include "som_c.h"

/* C13637 advance_spell_entity_color_phase   [class B, 54 bytes, 28 instructions]
 * Source: src/rom/advance_spell_entity_color_phase.s
 * Documented in docs/actor-cast-entity-resource-state.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void advance_spell_entity_color_phase(SomCtx *c)
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
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    r->sp -= 5;
    JSR(c, 0x3640, 0xC144A1); /* get_spell_entity_register_shadow */
    r->sp += 5;
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint8_t value = RAM8(0x0032 + x_ret);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    if ((value | 0xE0) < 0xF7) {
        r->a = (a_all >> 8 << 8) | 0x32;
        r->c = (value | 0xE0) >= 0xF7;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        RAM8(sp0 - 3) = (uint8_t)((value | 0xE0) + 1); /* PHA */
        r->sp -= 4;
        JSR(c, 0x3662, 0xC144B3); /* allocate_spell_entity_register_record */
        r->sp += 4;
        uint16_t x_ret2 = r->x;
        RAM8(0x0002 + x_ret2) = (uint8_t)((value | 0xE0) + 1);
        r->z = (uint8_t)((value | 0xE0) + 1) == 0;
        r->n = (uint8_t)((value | 0xE0) + 1) & 0x80;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 3;
        JSR(c, 0x3669, 0xC14514); /* append_spell_entity_transient_register_record */
        r->sp += 3;
        uint16_t a_all3 = r->a;
        uint16_t y_ret2 = r->y;
        a1 = (uint8_t)a_all3;
        a_hi1 = a_all3 >> 8;
        x1 = x_ret2;
        y1 = y_ret2;
    } else {
        RAM8(0x001E + y) = 0x78;
        uint8_t value2 = RAM8(0x0010 + y);
        RAM8(0x0010 + y) = (value2 & 0x0F) | 0x30;
        a1 = (value2 & 0x0F) | 0x30;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry;
    r->z = dp == 0;
    r->n = dp & 0x8000;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC13637, SOM_RTS, "hand", advance_spell_entity_color_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 54, 28)
