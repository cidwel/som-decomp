#include "som_c.h"

/* C0317E cancel_spell_item_selection_and_request_page_rebuild   [class A, 16 bytes, 7 instructions]
 * Source: src/rom/cancel_spell_item_selection_and_request_page_rebuild.s
 * Documented in docs/ui-native-spell-item-navigation.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void cancel_spell_item_selection_and_request_page_rebuild(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0xA20A) &= 0xBF;
    RAM8(0xA212) &= 0xF7;
    uint8_t value3 = RAM8(0xA20A);
    RAM8(0xA20A) |= 1;
    SET_A8(r, 1);
    r->z = (value3 & 1) == 0;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0317E, SOM_RTS, "gen", cancel_spell_item_selection_and_request_page_rebuild, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 16, 7)
