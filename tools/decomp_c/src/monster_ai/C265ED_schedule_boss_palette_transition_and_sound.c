#include "som_c.h"

/* C265ED schedule_boss_palette_transition_and_sound   [class A, 35 bytes, 15 instructions]
 * Source: src/rom/schedule_boss_palette_transition_and_sound.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void schedule_boss_palette_transition_and_sound(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x007E + x);
    RAM8(0x033F + 0x0E) = (uint8_t)(value + 0x78);
    r->a = 0x20;
    r->x = (uint16_t)(value + 0x78);
    r->y = 0x0E;
    r->c = value + 0x78 > 0xFFFF;
    r->v = ((value ^ (uint16_t)(value + 0x78)) & ((uint16_t)(value + 0x78) ^ 0x78) & 0x8000) != 0;
    JSR(c, 0x6605, 0xC2272D); /* allocate_boss_palette_transition_object */
    r->a = 0x86;
    r->x = 0x0F;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x660E, 0xC230E3); /* request_boss_sound_with_parameter_word */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC265ED, SOM_RTS, "gen", schedule_boss_palette_transition_and_sound, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 35, 15)
