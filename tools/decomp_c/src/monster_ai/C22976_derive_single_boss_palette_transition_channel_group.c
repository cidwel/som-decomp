#include "som_c.h"

/* C22976 derive_single_boss_palette_transition_channel_group   [class A, 28 bytes, 12 instructions]
 * Source: src/rom/derive_single_boss_palette_transition_channel_group.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void derive_single_boss_palette_transition_channel_group(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(OBJECT_PHASE + value, 2);
    RAM16_SET(0x0276, RAM16(0x00A0 + value));
    RAM16_SET(0x0279, RAM16(0x00A3 + value));
    RAM16_SET(0x0266, 6);
    r->a = 6;
    r->x = value;
    JSR(c, 0x298F, 0xC22999); /* divide_boss_palette_channel_deltas_by_duration */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22976, SOM_RTS, "gen", derive_single_boss_palette_transition_channel_group, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 28, 12)
