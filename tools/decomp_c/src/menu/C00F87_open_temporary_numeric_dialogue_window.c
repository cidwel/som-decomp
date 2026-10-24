#include "som_c.h"

/* C00F87 open_temporary_numeric_dialogue_window   [class B, 35 bytes, 13 instructions]
 * Source: src/rom/open_temporary_numeric_dialogue_window.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void open_temporary_numeric_dialogue_window(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x0F89, 0xC00F08); GUARD_JSR(c, sp_call, 0x0F89); } /* save_dialogue_cursor_before_temporary_window */
    uint16_t a_all = r->a;
    RAM8(0xA162) = 2;
    r->a = (a_all >> 8 << 8) | 2;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0F91, 0xC01999); GUARD_JSR(c, sp_call, 0x0F91); } /* construct_temporary_numeric_dialogue_script */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0F94, 0xC00D8B); GUARD_JSR(c, sp_call, 0x0F94); } /* select_dialogue_window_geometry_from_state */
    uint8_t db_ret = r->db;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0F97, 0xC0193F); GUARD_JSR(c, sp_call, 0x0F97); } /* initialize_dialogue_window_cursor_and_render_state */
    BUS8_SET(c, (db_ret << 0x10) + 0xA170, 0x53);
    uint8_t value = RAM8(0x1D00);
    RAM8(0x1D00) = (value | 4) & 0xBF;
    SET_A8(r, (value | 4) & 0xBF);
    r->z = ((value | 4) & 0xBF) == 0;
    r->n = (value | 4) & 0xBF & 0x80;
    r->mf = 1;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00F87, SOM_RTS, "gen", open_temporary_numeric_dialogue_window, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 35, 13)
