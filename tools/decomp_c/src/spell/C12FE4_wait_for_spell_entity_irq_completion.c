#include "som_c.h"

/* C12FE4 wait_for_spell_entity_irq_completion   [class D, 35 bytes, 19 instructions]
 * Source: src/rom/wait_for_spell_entity_irq_completion.s
 * Documented in docs/actor-cast-entity-slots.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$01C0.  Callers read: BYCZNV.
 */
static void wait_for_spell_entity_irq_completion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x01C0) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0x8232, (uint16_t)(RAM16(0x8232) + 1));
    uint8_t a_hi1 = a >> 8;
    for (;;) {
        uint16_t value2 = BUS16(c, 0x004211);
        uint16_t value3 = RAM16(0x8230);
        a_hi1 = value3 >> 8;
        if (!(value3 == 0)) break;
    }
    RAM16_SET(0x8230, (uint16_t)(RAM16(0x8230) - 1));
    RAM16_SET(0x8232, (uint16_t)(RAM16(0x8232) - 1));
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->y = y;
    r->c = carry;
    r->z = 0;
    r->n = 0;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12FE4, SOM_RTS, "gen", wait_for_spell_entity_irq_completion, 0, L_B | L_Y | L_C | L_Z | L_N | L_V, 5, 0, 0, 35, 19)
