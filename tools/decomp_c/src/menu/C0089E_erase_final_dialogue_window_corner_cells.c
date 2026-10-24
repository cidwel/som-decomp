#include "som_c.h"

/* C0089E erase_final_dialogue_window_corner_cells   [class B, 37 bytes, 13 instructions]
 * Source: src/rom/erase_final_dialogue_window_corner_cells.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void erase_final_dialogue_window_corner_cells(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM8(0xA157) = RAM8(0xA166);
    uint8_t value2 = RAM8(0xA165);
    RAM8(0xA156) = value2;
    r->a = (a_hi << 8) | value2;
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    { const uint16_t sp_call = r->sp; JSR(c, 0x08AC, 0xC01BBD); GUARD_JSR(c, sp_call, 0x08AC); } /* exchange_dialogue_tilemap_entry_with_zero_tile */
    uint8_t db_ret = r->db;
    uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 0xA156);
    BUS8_SET(c, (db_ret << 0x10) + 0xA156, (uint8_t)(value3 + 1));
    r->z = (uint8_t)(value3 + 1) == 0;
    r->n = (uint8_t)(value3 + 1) & 0x80;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x08B2, 0xC01BBD); GUARD_JSR(c, sp_call, 0x08B2); } /* exchange_dialogue_tilemap_entry_with_zero_tile */
    uint8_t db_ret2 = r->db;
    uint8_t value4 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA157);
    BUS8_SET(c, (db_ret2 << 0x10) + 0xA157, (uint8_t)(value4 + 1));
    r->z = (uint8_t)(value4 + 1) == 0;
    r->n = (uint8_t)(value4 + 1) & 0x80;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x08B8, 0xC01BBD); GUARD_JSR(c, sp_call, 0x08B8); } /* exchange_dialogue_tilemap_entry_with_zero_tile */
    uint8_t db_ret3 = r->db;
    uint8_t value5 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA156);
    BUS8_SET(c, (db_ret3 << 0x10) + 0xA156, (uint8_t)(value5 - 1));
    r->z = (uint8_t)(value5 - 1) == 0;
    r->n = (uint8_t)(value5 - 1) & 0x80;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x08BE, 0xC01BBD); GUARD_JSR(c, sp_call, 0x08BE); } /* exchange_dialogue_tilemap_entry_with_zero_tile */
    uint8_t db_ret4 = r->db;
    uint8_t value6 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA15E);
    BUS8_SET(c, (db_ret4 << 0x10) + 0xA15E, (uint8_t)(value6 + 1));
    r->z = (uint8_t)(value6 + 1) == 0;
    r->n = (uint8_t)(value6 + 1) & 0x80;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0089E, SOM_RTS, "gen", erase_final_dialogue_window_corner_cells, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 37, 13)
