#include "som_c.h"

/* C12F33 restore_spell_entity_irq_handler   [class B, 43 bytes, 22 instructions]
 * Source: src/rom/restore_spell_entity_irq_handler.s
 * Documented in docs/actor-cast-entity-events.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$01C0.  Callers read: Y.
 */
static void restore_spell_entity_irq_handler(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x01C0) { c->fail = 3; return; }
    if (RAM8(0x822A) == 0) {
        RAM16_SET(0x0100, RAM16(0x822C));
        RAM16_SET(0x0102, RAM16(0x822E));
    } else {
        RAM8(0x822A)--;
        if (RAM8(0x822A) == 0) {
            RAM16_SET(0x0100, RAM16(0x822C));
            RAM16_SET(0x0102, RAM16(0x822E));
        }
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12F33, SOM_RTS, "gen", restore_spell_entity_irq_handler, 0, L_Y, 5, 0, 0, 43, 22)
