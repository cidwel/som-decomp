#include "som_c.h"

/* C0B32A advance_hero_charge_input_and_restore_byte_accumulator   [class A, 6 bytes, 3 instructions]
 * Source: src/rom/advance_hero_charge_input_and_restore_byte_accumulator.s
 * Documented in docs/hero-charge-input.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void advance_hero_charge_input_and_restore_byte_accumulator(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xB32C, 0xC0B330); /* advance_selected_hero_charge_timing_and_publish_native_gauge */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0B32A, SOM_RTS, "gen", advance_hero_charge_input_and_restore_byte_accumulator, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 6, 3)
