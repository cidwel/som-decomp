#include "som_c.h"

/* C05A7F replace_message_prefix_with_dialogue_marker   [class A, 8 bytes, 5 instructions]
 * Source: src/rom/replace_message_prefix_with_dialogue_marker.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void replace_message_prefix_with_dialogue_marker(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    RAM8(0xFE00 + (uint16_t)(y - 1)) = 0x30;
    r->y = (uint16_t)((uint16_t)(y - 1) + 1);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC05A7F, SOM_RTS, "gen", replace_message_prefix_with_dialogue_marker, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 8, 5)
