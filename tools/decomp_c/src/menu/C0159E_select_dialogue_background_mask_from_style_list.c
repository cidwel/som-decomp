#include "som_c.h"

/* C0159E select_dialogue_background_mask_from_style_list   [class A, 27 bytes, 13 instructions]
 * Source: src/rom/select_dialogue_background_mask_from_style_list.s
 * Documented in docs/event-dialogue-render-blend.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: B.
 */
static void select_dialogue_background_mask_from_style_list(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value2 = RAM8(0xA24F + RAM8(0xA24E));
    RAM16_SET(0xA182, ((value2 << 8) | 0) >> 1);
    r->a = (r->a & 0x00FF) | ((((value2 << 8) | 0) >> 1 >> 8) << 8);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0159E, SOM_RTS, "gen", select_dialogue_background_mask_from_style_list, 0, L_B, 1, 1, 0, 27, 13)
