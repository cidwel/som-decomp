#include "som_c.h"

/* D3EFAE get_spell_sprite_object_history_entry   [class A, 22 bytes, 16 instructions]
 * Source: src/rom/get_spell_sprite_object_history_entry.s
 * Documented in docs/actor-cast-entity-sprite-motion.md
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: XYV.
 */
static void get_spell_sprite_object_history_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint8_t m_entry = r->mf;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    r->y = (uint16_t)((uint16_t)(((a & 0xFF) << 1 << 1) + x) + 0x50);
    r->mf = m_entry;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3EFAE, SOM_RTS, "gen", get_spell_sprite_object_history_entry, 0, L_X | L_Y | L_V, 5, -1, 0, 22, 16)
