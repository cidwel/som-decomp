#include "som_c.h"

/* C00261 initialize_active_dialogue_window_geometry_and_style   [class B, 92 bytes, 39 instructions]
 * Source: src/rom/initialize_active_dialogue_window_geometry_and_style.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void initialize_active_dialogue_window_geometry_and_style(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x0263, 0xC00D8B); GUARD_JSR(c, sp_call, 0x0263); } /* select_dialogue_window_geometry_from_state */
    uint8_t db_ret = r->db;
    BUS8_SET(c, (db_ret << 0x10) + 0xA16E, 4);
    BUS16_SET(c, (db_ret << 0x10) + 0xA18E, 0x0100);
    uint16_t value = BUS16_RDP(c, (db_ret << 0x10) + 0xA16F);
    uint16_t x1;
    if ((value & 0xFF) == 0) {
        x1 = 0x6480;
    } else {
        x1 = 0x6580;
    }
    BUS16_SET(c, (db_ret << 0x10) + 0xA18C, x1);
    uint16_t value2 = BUS16_RDP(c, (db_ret << 0x10) + 0xA24E);
    BUS16_SET(c, (db_ret << 0x10) + 0xA173, (value2 & 0xFF) << 1);
    uint16_t value3 = BUS16_RDP(c, (db_ret << 0x10) + 0xA173);
    BUS16_SET(c, (db_ret << 0x10) + 0xA1A2, (uint16_t)(((value2 & 0xFF) << 1 << 1 << 1 << 1 << 1) - value3));
    uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0xA24E);
    uint16_t value5 = BUS16_RDP(c, (db_ret << 0x10) + 0xA24F + (value4 & 0xFF));
    BUS16_SET(c, (db_ret << 0x10) + 0xA178, (((value5 & 0xFF) << 8) | 0) >> 1);
    r->a = (((value5 & 0xFF) << 8) | 0) >> 1;
    r->x = value4 & 0xFF;
    r->c = (((value5 & 0xFF) << 8) | 0) & 0x01;
    r->z = (((value5 & 0xFF) << 8) | 0) >> 1 == 0;
    r->n = (((value5 & 0xFF) << 8) | 0) >> 1 & 0x8000;
    r->v = ((((value2 & 0xFF) << 1 << 1 << 1 << 1 << 1) ^ value3) & (((value2 & 0xFF) << 1 << 1 << 1 << 1 << 1) ^ (uint16_t)(((value2 & 0xFF) << 1 << 1 << 1 << 1 << 1) - value3)) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x02AD, 0xC005C3); GUARD_JSR(c, sp_call, 0x02AD); } /* publish_active_dialogue_window_style_palette_pair */
    uint8_t db_ret2 = r->db;
    uint16_t a_all2 = r->a;
    r->a = (a_all2 >> 8 << 8) | 0x49;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x02B2, 0xC00FFA); GUARD_JSR(c, sp_call, 0x02B2); } /* request_dialogue_transfer_and_conditional_window_flags */
    BUS8_SET(c, (db_ret2 << 0x10) + 0xA186, 0);
    BUS8_SET(c, (db_ret2 << 0x10) + 0xA16D, 0);
    uint8_t value6 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA15C);
    BUS8_SET(c, (db_ret2 << 0x10) + 0xA15C, (uint8_t)(value6 + 1));
    r->z = (uint8_t)(value6 + 1) == 0;
    r->n = (uint8_t)(value6 + 1) & 0x80;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00261, SOM_RTS, "gen", initialize_active_dialogue_window_geometry_and_style, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 92, 39)
