#include "som_c.h"

/* C08366 initialize_scene_centers_color_math_and_hdma   [class D, 66 bytes, 26 instructions]
 * Source: src/rom/initialize_scene_centers_color_math_and_hdma.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BYCV.
 */
static void initialize_scene_centers_color_math_and_hdma(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x0070, RAM16(0x00FA) & 0xFFF8);
    uint16_t value2 = RAM16(0x00FC);
    RAM16_SET(0x0072, value2 & 0xFFF8);
    r->a = value2 & 0xFFF8;
    r->z = (value2 & 0xFFF8) == 0;
    r->n = value2 & 0xFFF8 & 0x8000;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x837A, 0xC083C8); GUARD_JSR(c, sp_call, 0x837A); } /* calculate_scene_camera_centers */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->xf != 1) { c->fail = 3; return; }
    BUS8_SET(c, (db_ret << 0x10) + 0x2130, 2);
    BUS8_SET(c, (db_ret << 0x10) + 0x2131, 0x21);
    BUS8_SET(c, (uint16_t)(dp_ret + 0x2A), 0x21);
    BUS8_SET(c, (db_ret << 0x10) + 0x2132, 0xE0);
    BUS8_SET(c, (db_ret << 0x10) + 0x212D, 2);
    r->x = 2;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x8394, 0x02ADAA); GUARD_JSL(c, sp_call, 0x8394); } /* install_scene_hdma_records_and_six_channels */
    uint8_t db_ret2 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    BUS16_SET(c, (db_ret2 << 0x10) + 0x1100, 0);
    BUS16_SET(c, (db_ret2 << 0x10) + 0x1200, 0);
    BUS16_SET(c, (db_ret2 << 0x10) + 0x1000, 0x7F00);
    BUS16_SET(c, (db_ret2 << 0x10) + 0x1400, 0x7F00);
    r->a = 0x7F00;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC08366, SOM_RTS, "gen", initialize_scene_centers_color_math_and_hdma, 0, L_B | L_Y | L_C | L_V, 1, 1, 1, 66, 26)
