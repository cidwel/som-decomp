#include "som_c.h"

/* C139BA queue_spell_entity_script_cleanup   [class A, 19 bytes, 10 instructions]
 * Source: src/rom/queue_spell_entity_script_cleanup.s
 * Documented in docs/actor-cast-entity-construction.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$01C0.  Callers read: YCZNV.
 */
static void queue_spell_entity_script_cleanup(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x01C0) { c->fail = 3; return; }
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x8234);
    r->a = 6;
    r->x = value;
    r->y = 0xFC7C;
    r->z = 0;
    r->n = 0;
    r->sp -= 3;
    JSR(c, 0x39C9, 0xC1302E); /* build_spell_entity_script_transfers */
    r->sp += 3;
    r->c = carry;
    r->z = 0;
    r->n = 0;
    r->v = overflow;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC139BA, SOM_RTS, "gen", queue_spell_entity_script_cleanup, 0, L_Y | L_C | L_Z | L_N | L_V, 3, 0, 0, 19, 10)
