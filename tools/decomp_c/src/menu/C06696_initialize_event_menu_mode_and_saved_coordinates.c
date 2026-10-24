#include "som_c.h"

/* C06696 initialize_event_menu_mode_and_saved_coordinates   [class A, 31 bytes, 11 instructions]
 * Source: src/rom/initialize_event_menu_mode_and_saved_coordinates.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void initialize_event_menu_mode_and_saved_coordinates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6699, 0xC064A4); GUARD_JSL(c, sp_call, 0x6699); } /* normalize_menu_native_direct_page_and_bank */
    uint8_t db_ret = r->db;
    uint16_t a_all = r->a;
    BUS8_SET(c, (db_ret << 0x10) + 0x1820, (uint8_t)a_all);
    BUS8_SET(c, (db_ret << 0x10) + 0x1802, 0);
    BUS8_SET(c, (db_ret << 0x10) + 0x1803, 0);
    BUS8_SET(c, (db_ret << 0x10) + 0x1804, 0);
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x66AA, 0xC0692D); GUARD_JSR(c, sp_call, 0x66AA); } /* request_event_menu_loop_and_initialize_input_state */
    BUS16_SET(c, (db_ret << 0x10) + 0x1826, 0);
    BUS16_SET(c, (db_ret << 0x10) + 0x183E, x);
    BUS16_SET(c, (db_ret << 0x10) + 0x1840, y);
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06696, SOM_RTS, "gen", initialize_event_menu_mode_and_saved_coordinates, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 31, 11)
