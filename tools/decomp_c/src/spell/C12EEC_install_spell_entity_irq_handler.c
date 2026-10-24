#include "som_c.h"

/* C12EEC install_spell_entity_irq_handler   [class D, 71 bytes, 30 instructions]
 * Source: src/rom/install_spell_entity_irq_handler.s
 * Documented in docs/actor-cast-entity-events.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$01CC.  Callers read: BYCZNV.
 */
static void install_spell_entity_irq_handler(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x01CC) { c->fail = 3; return; }
    BUS16_SET(c, 0x004209, 0xC0);
    RAM16_SET(0x822C, RAM16(0x0100));
    uint16_t value2 = RAM16(0x0102);
    RAM16_SET(0x822E, value2);
    RAM8(0x0100) = 0x5C;
    RAM8(0x0101) = 0x5E;
    RAM8(0x0102) = 0x2F;
    RAM8(0x0103) = 0xC1;
    RAM8(0x822A)++;
    uint8_t value3 = BUS8(c, 0x004210);
    r->a = (value2 >> 8 << 8) | value3;
    r->z = 0;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12EEC, SOM_RTS, "gen", install_spell_entity_irq_handler, 0, L_B | L_Y | L_C | L_Z | L_N | L_V, 5, 0, 0, 71, 30)
