#include "som_c.h"

/* C1F7CF expand_and_upload_map_pattern_record   [class D, 53 bytes, 20 instructions]
 * Source: src/rom/expand_and_upload_map_pattern_record.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=8 bit DB=$7F D=$0000.  Callers read: BYV.
 */
static void expand_and_upload_map_pattern_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7F, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->x = 0x10;
    r->y = 0;
    r->mf = 1;
    JSR(c, 0xF7D7, 0xC1F804); /* rotate_map_pattern_rows_left */
    r->x = 0x10;
    r->y = 0x20;
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xF7DE, 0xC1F817); /* shift_map_pattern_rows_right */
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xF7E1, 0xC1F817); /* shift_map_pattern_rows_right */
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xF7E4, 0xC1F817); /* shift_map_pattern_rows_right */
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xF7E7, 0xC1F817); /* shift_map_pattern_rows_right */
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xF7EA, 0xC1F817); /* shift_map_pattern_rows_right */
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xF7ED, 0xC1F817); /* shift_map_pattern_rows_right */
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xF7F0, 0xC1F817); /* shift_map_pattern_rows_right */
    BUS8_SET(c, 0x004372, 0);
    BUS8_SET(c, 0x004375, 0x90);
    BUS8_SET(c, 0x00420B, 0x80);
    r->mf = 1;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F7CF, SOM_RTS, "gen", expand_and_upload_map_pattern_record, 0, L_B | L_Y | L_V, 1, 0, 1, 53, 20)
