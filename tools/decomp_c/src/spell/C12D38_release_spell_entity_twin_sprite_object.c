#include "som_c.h"
#include "som_hand.h"

/* C12D38 release_spell_entity_twin_sprite_object   [class B, 43 bytes, 23 instructions]
 * Source: src/rom/release_spell_entity_twin_sprite_object.s
 * Documented in docs/actor-cast-entity-twin-objects.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void release_spell_entity_twin_sprite_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), x);
    r->a = 0x0A;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 5); /* TSC TCD: the frame */
    r->sp -= 5;
    JSL(c, 0x2D47, 0xC12EB9); /* release_spell_entity_sprite_pointer_group_long */
    r->sp += 5;
    uint16_t value = RAM16((uint16_t)(0x0001 + r->dp));
    r->a = 0x0A;
    r->x = (uint16_t)(value + 0x1A);
    r->c = value + 0x1A > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = ((value ^ (uint16_t)(value + 0x1A)) & ((uint16_t)(value + 0x1A) ^ 0x1A) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 5;
    JSL(c, 0x2D55, 0xC12EB9); /* release_spell_entity_sprite_pointer_group_long */
    r->sp += 5;
    uint16_t value2 = RAM16((uint16_t)(0x0001 + r->dp));
    r->x = value2;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 5;
    JSL(c, 0x2D5B, 0xC12E7C); /* release_spell_entity_heap_bank_long */
    r->sp += 5;
    r->mf = 1; /* SEP #$20 */
    som_pull_p(c, sp0 - 2); /* PLP */
    r->dp = RAM8(sp0 - 1) | (RAM8(sp0) << 8); /* PLD */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12D38, SOM_RTS, "hand", release_spell_entity_twin_sprite_object, 0, 0, 5, 1, 0, 43, 23)
