#include "som_c.h"

/* C25FE0 begin_descriptor_five_terminal_animation_and_restore_party_palette_music   [class B, 47 bytes, 18 instructions]
 * Source: src/rom/begin_descriptor_five_terminal_animation_and_restore_party_palette_music.s
 * Documented in docs/boss-descriptor-five-terminal.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void begin_descriptor_five_terminal_animation_and_restore_party_palette_music(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
}
SOM_REGISTER(0xC25FE0, SOM_RTS, "gen", begin_descriptor_five_terminal_animation_and_restore_party_palette_music, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 47, 18)
