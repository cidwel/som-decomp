#include "som_c.h"

/* C76978 append_native_party_status_active_slot_count_label   [class B, 14 bytes, 5 instructions]
 * Source: src/rom/append_native_party_status_active_slot_count_label.s
 * Documented in docs/ui-native-party-status-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_native_party_status_active_slot_count_label(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->y = 0x7B53;
    JSR(c, 0x697D, 0xC76ABE); /* select_bank_C7_and_copy_native_terminated_tokens */
    r->mf = 1;
    r->xf = 0;
    JSL(c, 0x6981, 0xC029FC); /* count_active_native_menu_live_slot_bytes */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x6984, 0xC76986); /* append_native_party_status_count_glyph_and_newline */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76978, SOM_RTS, "gen", append_native_party_status_active_slot_count_label, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 14, 5)
