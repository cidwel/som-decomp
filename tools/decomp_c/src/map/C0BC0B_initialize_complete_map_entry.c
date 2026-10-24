#include "som_c.h"

/* C0BC0B initialize_complete_map_entry   [class D, 122 bytes, 43 instructions]
 * Source: src/rom/initialize_complete_map_entry.s
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void initialize_complete_map_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC0D, 0xC0BC85); GUARD_JSR(c, sp_call, 0xBC0D); } /* install_map_interrupt_jump_template */
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC10, 0xC0C481); GUARD_JSR(c, sp_call, 0xBC10); } /* initialize_map_header_resources */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC13, 0xC0C9EA); GUARD_JSR(c, sp_call, 0xBC13); } /* load_map_tile_layers_and_camera */
    r->mf = 0;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xBC17, 0x02AA5C); GUARD_JSL(c, sp_call, 0xBC17); } /* configure_map_screen_long */
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xBC1B, 0x01FD4E); GUARD_JSL(c, sp_call, 0xBC1B); } /* configure_map_backgrounds_long */
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xBC1F, 0x02A6C5); GUARD_JSL(c, sp_call, 0xBC1F); } /* initialize_map_layer_records_long */
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xBC23, 0x01DC8F); GUARD_JSL(c, sp_call, 0xBC23); } /* initialize_party_for_map_entry */
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC26, 0xC0DCDC); GUARD_JSR(c, sp_call, 0xBC26); } /* load_ordinary_map_objects */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xBC2A, 0x01E0D7); GUARD_JSL(c, sp_call, 0xBC2A); } /* initialize_party_hud_long */
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC2D, 0xC0E355); GUARD_JSR(c, sp_call, 0xBC2D); } /* initialize_map_sprite_workspace */
    uint8_t db_ret5 = r->db;
    BUS16_SET(c, (db_ret5 << 0x10) + 0x0120, 0x0200);
    r->x = 0x0F00;
    r->y = 0x0101;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBC3E, 0xC08B30); GUARD_JSR(c, sp_call, 0xBC3E); } /* request_map_entry_fade */
    uint16_t dp_ret3 = r->dp;
    { const uint16_t sp_call = r->sp; JSL(c, 0xBC42, 0x01F29C); GUARD_JSL(c, sp_call, 0xBC42); } /* prepare_map_palette_snapshot_long */
    uint8_t db_ret7 = r->db;
    uint16_t a_all12 = r->a;
    uint16_t x_ret15 = r->x;
    uint16_t y_ret12 = r->y;
    bool carry_ret10 = r->c;
    BUS8_SET(c, (db_ret7 << 0x10) + 0x1D04, 0);
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0xE3));
    BUS8_SET(c, (uint16_t)(dp_ret3 + 0xE3), value & 0xF0);
    uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0xB0));
    BUS8_SET(c, (db_ret7 << 0x10) + 0x210D, value2);
    BUS8_SET(c, (db_ret7 << 0x10) + 0x210D, 0);
    uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0xB2));
    BUS8_SET(c, (db_ret7 << 0x10) + 0x210E, value3);
    BUS8_SET(c, (db_ret7 << 0x10) + 0x210E, 0);
    uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0xE8));
    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x52), value4 & 3);
    BUS8_SET(c, (db_ret7 << 0x10) + 0x4207, 0xB8);
    BUS8_SET(c, (db_ret7 << 0x10) + 0x4208, 0);
    BUS8_SET(c, (db_ret7 << 0x10) + 0x4209, 0xC4);
    BUS8_SET(c, (db_ret7 << 0x10) + 0x420A, 0);
    uint8_t value5 = BUS8_RDP(c, (db_ret7 << 0x10) + 0x010E);
    uint8_t value6 = BUS8_RDP(c, (db_ret7 << 0x10) + 0x010F);
    uint8_t a1;
    uint8_t a_hi1;
    uint8_t x1;
    uint8_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    if ((value5 | value6) != 0) {
        a1 = value5 | value6;
        a_hi1 = a_all12 >> 8;
        x1 = (uint8_t)x_ret15;
        y1 = (uint8_t)y_ret12;
        carry1 = carry_ret10;
        zero1 = (value5 | value6) == 0;
        negative1 = (value5 | value6) & 0x80;
    } else {
        r->a = (a_all12 >> 8 << 8) | (value5 | value6);
        r->x = (uint8_t)x_ret15;
        r->y = (uint8_t)y_ret12;
        r->z = (value5 | value6) == 0;
        r->n = (value5 | value6) & 0x80;
        r->mf = 1;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0xBC7F, 0x02CEC1); GUARD_JSL(c, sp_call, 0xBC7F); } /* initialize_map_overlay_graphics_and_windows */
        uint16_t a_all13 = r->a;
        uint8_t x_ret16 = r->x;
        uint8_t y_ret13 = r->y;
        bool carry_ret11 = r->c;
        bool zero_ret13 = r->z;
        bool negative_ret13 = r->n;
        a1 = (uint8_t)a_all13;
        a_hi1 = a_all13 >> 8;
        x1 = x_ret16;
        y1 = y_ret13;
        carry1 = carry_ret11;
        zero1 = zero_ret13;
        negative1 = negative_ret13;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xBC83, 0xC00060); GUARD_JSL(c, sp_call, 0xBC83); } /* clear_map_entry_party_effects_jump */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0BC0B, SOM_RTS, "gen", initialize_complete_map_entry, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 1, 122, 43)
