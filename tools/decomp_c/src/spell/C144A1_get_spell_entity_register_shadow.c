#include "som_c.h"

/* C144A1 get_spell_entity_register_shadow   [class A, 18 bytes, 13 instructions]
 * Source: src/rom/get_spell_entity_register_shadow.s
 * Documented in docs/actor-cast-entity-registers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYV.
 */
static void get_spell_entity_register_shadow(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    r->x = RAM16(0x8432);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC144A1, SOM_RTS, "gen", get_spell_entity_register_shadow, 0, L_B | L_X | L_Y | L_V, 5, 1, 0, 18, 13)
