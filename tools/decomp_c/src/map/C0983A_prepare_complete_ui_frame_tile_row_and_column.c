#include "som_c.h"
#include "som_hand_d.h"

/* JSR keeps the program bank: this code runs from the bank $00 mirror, where $0B00 is WRAM, and the callees must follow it. */
#define SAME_BANK(c, off) (((uint32_t)(c)->cpu.k << 16) | (off))

/* C0983A prepare_complete_ui_frame_tile_row_and_column   [class A, 6 bytes, 2 instructions]
 * Source: src/rom/prepare_complete_ui_frame_tile_row_and_column.s
 * Documented in docs/ui-native-ui-frame-columns.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void prepare_complete_ui_frame_tile_row_and_column(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x983C, SAME_BANK(c, 0x98E4)); /* prepare_upper_or_lower_scene_tile_row_for_publication */
    REQUIRE_M16(c);
    REQUIRE_X8(c);
    TAIL_CALL(c, 0x00993C, SOM_RTS); /* prepare_one_hundred_twenty_eight_ui_column_tiles */
}
SOM_REGISTER(0xC0983A, SOM_RTS, "hand", prepare_complete_ui_frame_tile_row_and_column, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 1, 6, 2)
