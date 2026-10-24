#include "som_c.h"

/* C18898 prepare_actor_cast_directional_offset   [class B, 47 bytes, 21 instructions]
 * Source: src/rom/prepare_actor_cast_directional_offset.s
 * Documented in docs/actor-cast-publication.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void prepare_actor_cast_directional_offset(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint8_t value = RAM8(0xE010 + x);
    if (value == 0) {
        RAM16_SET(0xE11A + x, 0xFFE8);
        RAM16_SET(0xE118 + x, 0);
        r->a = 0xFFE8;
        r->mf = 0;
        RETURN_RTS(c);
    }
    if (value & 0x80) {
        RAM16_SET(0xE118 + x, 0xFFE8);
        RAM16_SET(0xE11A + x, 0);
        r->a = 0xFFE8;
        r->mf = 0;
        RETURN_RTS(c);
    }
    if ((uint16_t)(value - 1) == 0) {
        RAM16_SET(0xE11A + x, 0x18);
        RAM16_SET(0xE118 + x, 0);
        r->a = 0x18;
        r->mf = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0xE118 + x, 0x18);
    RAM16_SET(0xE11A + x, 0);
    r->a = 0x18;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC18898, SOM_RTS, "gen", prepare_actor_cast_directional_offset, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 47, 21)
