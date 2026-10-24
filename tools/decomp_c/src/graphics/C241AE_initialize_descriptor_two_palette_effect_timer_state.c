#include "som_c.h"

/* C241AE initialize_descriptor_two_palette_effect_timer_state   [class A, 10 bytes, 5 instructions]
 * Source: src/rom/initialize_descriptor_two_palette_effect_timer_state.s
 * Documented in docs/boss-descriptor-two-palette.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_two_palette_effect_timer_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    uint16_t value2 = RAM16(OBJECT_PHASE + value);
    RAM16_SET(OBJECT_AGE + value, 0);
    r->x = value;
    r->c = 0;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC241AE, SOM_RTS, "gen", initialize_descriptor_two_palette_effect_timer_state, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 10, 5)
