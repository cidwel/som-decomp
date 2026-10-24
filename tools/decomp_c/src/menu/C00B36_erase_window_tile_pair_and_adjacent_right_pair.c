#include "som_c.h"

/* C00B36 erase_window_tile_pair_and_adjacent_right_pair   [class B, 25 bytes, 9 instructions]
 * Source: src/rom/erase_window_tile_pair_and_adjacent_right_pair.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXY.
 */
static void erase_window_tile_pair_and_adjacent_right_pair(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x0B38, 0xC01BBD); GUARD_JSR(c, sp_call, 0x0B38); } /* exchange_dialogue_tilemap_entry_with_zero_tile */
    uint8_t db_ret = r->db;
    uint8_t value = BUS8_RDP(c, (db_ret << 0x10) + 0xA157);
    BUS8_SET(c, (db_ret << 0x10) + 0xA157, (uint8_t)(value + 1));
    r->z = (uint8_t)(value + 1) == 0;
    r->n = (uint8_t)(value + 1) & 0x80;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0B3E, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0B3E); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    uint8_t db_ret2 = r->db;
    bool m_ret = r->mf;
    if (m_ret) {
        uint8_t value2 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA157);
        BUS8_SET(c, (db_ret2 << 0x10) + 0xA157, (uint8_t)(value2 - 1));
        uint8_t value3 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA156);
        BUS8_SET(c, (db_ret2 << 0x10) + 0xA156, (uint8_t)(value3 + 1));
        r->z = (uint8_t)(value3 + 1) == 0;
        r->n = (uint8_t)(value3 + 1) & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0B47, 0xC01BBD); GUARD_JSR(c, sp_call, 0x0B47); } /* exchange_dialogue_tilemap_entry_with_zero_tile */
        uint8_t db_ret3 = r->db;
        uint8_t value4 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA157);
        BUS8_SET(c, (db_ret3 << 0x10) + 0xA157, (uint8_t)(value4 + 1));
        r->z = (uint8_t)(value4 + 1) == 0;
        r->n = (uint8_t)(value4 + 1) & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0B4D, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0B4D); } /* exchange_dialogue_tilemap_entry_and_request_upload */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value5 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA157);
        BUS16_RMW_SET(c, (db_ret2 << 0x10) + 0xA157, (uint16_t)(value5 - 1));
        uint16_t value6 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA156);
        BUS16_RMW_SET(c, (db_ret2 << 0x10) + 0xA156, (uint16_t)(value6 + 1));
        r->z = (uint16_t)(value6 + 1) == 0;
        r->n = (uint16_t)(value6 + 1) & 0x8000;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0B47, 0xC01BBD); GUARD_JSR(c, sp_call, 0x0B47); } /* exchange_dialogue_tilemap_entry_with_zero_tile */
        uint8_t db_ret5 = r->db;
        uint8_t value7 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA157);
        BUS8_SET(c, (db_ret5 << 0x10) + 0xA157, (uint8_t)(value7 + 1));
        r->z = (uint8_t)(value7 + 1) == 0;
        r->n = (uint8_t)(value7 + 1) & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0B4D, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0B4D); } /* exchange_dialogue_tilemap_entry_and_request_upload */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC00B36, SOM_RTS, "gen", erase_window_tile_pair_and_adjacent_right_pair, 0, L_B | L_X | L_Y, 1, 1, 0, 25, 9)
