#include "som_c.h"

/* C1FF3A restore_event_screen_and_reenable_frame_interrupts   [class D, 49 bytes, 25 instructions]
 * Source: src/rom/restore_event_screen_and_reenable_frame_interrupts.s
 * Entry: M=any X=any DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void restore_event_screen_and_reenable_frame_interrupts(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    RAM8(0x0000 + sp0) = 0x7E;
    RAM8(0x0000 + sp0 - 1) = 0;
    BUS8_SET(c, 0x004200, 0);
    BUS8_SET(c, 0x002100, 0x8F);
    uint8_t value = RAM8(0x001F);
    RAM8(0x0000 + sp0 - 1) = value;
    r->a = (a >> 8 << 8) | value;
    r->z = value == 0;
    r->n = value & 0x80;
    r->mf = 1;
    r->db = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xFF4E, 0xC1FF6B); GUARD_JSR(c, sp_call, 0xFF4E); } /* restore_screen_ports_map_graphics_tiles_hud_and_boss */
    r->sp += 2;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    BUS16_SET(c, (uint16_t)(dp_ret + 0xE6), 0x0F00);
    BUS16_SET(c, (uint16_t)(dp_ret + 0xE4), 0x0101);
    uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret + 0xE2));
    BUS8_SET(c, (uint16_t)(dp_ret + 0xE2), value2 | 1);
    BUS8_SET(c, (db_ret << 0x10) + 0x4200, 0xB1);
    BUS8_SET(c, (uint16_t)(dp_ret + 0x1F), RAM8(0x0000 + sp0 - 1));
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->a = (r->a & 0x00FF) | (1 << 8);
    r->mf = 1;
    r->db = value4;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1FF3A, SOM_RTS, "gen", restore_event_screen_and_reenable_frame_interrupts, 0, L_B | L_X | L_Y | L_C | L_V, 2, -1, -1, 49, 25)
