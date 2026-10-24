#include "som_c.h"

/* C64028 run_complete_three_phase_mode_seven_transition   [class D, 462 bytes, 187 instructions]
 * Source: src/rom/run_complete_three_phase_mode_seven_transition.s
 * Documented in docs/ui-native-mode7-transition.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: nothing.
 */
static void run_complete_three_phase_mode_seven_transition(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    BUS8_SET(c, 0x002100, 0x8F);
    BUS8_SET(c, 0x004200, 1);
    BUS8_SET(c, 0x00420C, 0);
    BUS8_SET(c, 0x002101, 2);
    BUS8_SET(c, 0x002105, 7);
    BUS8_SET(c, 0x002106, 0);
    BUS8_SET(c, 0x00210D, 0);
    BUS8_SET(c, 0x00210D, 0);
    BUS8_SET(c, 0x00210E, 0xFF);
    BUS8_SET(c, 0x00210E, 0xFE);
    BUS8_SET(c, 0x00211A, 0x80);
    BUS8_SET(c, 0x00211B, 0);
    BUS8_SET(c, 0x00211B, 1);
    BUS8_SET(c, 0x00211C, 0);
    BUS8_SET(c, 0x00211C, 0);
    BUS8_SET(c, 0x00211D, 0);
    BUS8_SET(c, 0x00211D, 0);
    BUS8_SET(c, 0x00211E, 0);
    BUS8_SET(c, 0x00211E, 1);
    BUS8_SET(c, 0x00211F, 0);
    BUS8_SET(c, 0x00211F, 0);
    BUS8_SET(c, 0x002120, 0);
    BUS8_SET(c, 0x002120, 0);
    BUS8_SET(c, 0x00212C, 0x11);
    BUS8_SET(c, 0x00212D, 0);
    BUS8_SET(c, 0x00212E, 0);
    BUS8_SET(c, 0x00212F, 0);
    BUS8_SET(c, 0x002130, 0);
    BUS8_SET(c, 0x002131, 0);
    BUS8_SET(c, 0x002132, 0xE0);
    r->a = (a_hi << 8) | 0xE0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4098, 0xC6438F); GUARD_JSR(c, sp_call, 0x4098); } /* initialize_mode_seven_transition_vram_and_palettes */
    uint16_t a_all = r->a;
    BUS8_SET(c, 0x004360, 0);
    BUS8_SET(c, 0x004361, 0x21);
    BUS16_SET(c, 0x004362, 0x1000);
    BUS8_SET(c, 0x004364, 0);
    BUS8_SET(c, 0x004370, 2);
    BUS8_SET(c, 0x004371, 0x22);
    BUS16_SET(c, 0x004372, 0x1020);
    BUS8_SET(c, 0x004374, 0);
    RAM8(0x004A) = 0;
    RAM8(0x004B) = 0;
    r->a = (a_all >> 8 << 8) | 0x22;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x40C5, 0xC641F6); GUARD_JSR(c, sp_call, 0x40C5); } /* build_mode_seven_transition_hdma_line_records */
    RAM16_SET(0x1E00, 0x2801);
    RAM16_SET(0x1E02, 0xFF0E);
    r->x = 0xFF0E;
    r->z = 0;
    r->n = 1;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x40D5, 0xC30004); GUARD_JSL(c, sp_call, 0x40D5); } /* audio_command_sender_public_jump */
    uint16_t y_ret3 = r->y;
    { const uint16_t sp_call = r->sp; JSR(c, 0x40D8, 0xC6459C); GUARD_JSR(c, sp_call, 0x40D8); } /* await_next_mode_seven_scene_vblank */
    bool x_ret5 = r->xf;
    uint16_t a_all4 = r->a;
    BUS8_SET(c, 0x00420C, 0xC0);
    BUS8_SET(c, 0x002100, 0x0F);
    uint8_t a_hi1 = a_all4 >> 8;
    uint16_t y1 = y_ret3;
    uint8_t data_bank = 0;
    for (;;) {
        r->y = y1;
        r->mf = 1;
        r->xf = x_ret5;
        r->db = data_bank;
        r->dp = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x40E5, 0xC64285); GUARD_JSR(c, sp_call, 0x40E5); } /* clip_and_pack_visible_mode_seven_transition_objects */
        uint8_t db_ret = r->db;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x40E8, 0xC6459C); GUARD_JSR(c, sp_call, 0x40E8); } /* await_next_mode_seven_scene_vblank */
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x40EB, 0xC641F6); GUARD_JSR(c, sp_call, 0x40EB); } /* build_mode_seven_transition_hdma_line_records */
        uint16_t y_ret5 = r->y;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x40EF, 0xC646C5); GUARD_JSL(c, sp_call, 0x40EF); } /* upload_complete_mode_seven_scene_oam_buffer */
        uint16_t a_all8 = r->a;
        uint8_t value = RAM8(0x004A);
        RAM8(0x004A) = (uint8_t)(value + 0x10);
        a_hi1 = a_all8 >> 8;
        y1 = y_ret5;
        data_bank = db_ret;
        if (!((uint8_t)(value + 0x10) != 0xE0)) break;
    }
    r->y = y1;
    r->mf = 1;
    r->xf = x_ret5;
    r->db = data_bank;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x40FD, 0xC64285); GUARD_JSR(c, sp_call, 0x40FD); } /* clip_and_pack_visible_mode_seven_transition_objects */
    uint8_t db_ret2 = r->db;
    uint16_t y_ret6 = r->y;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4100, 0xC6459C); GUARD_JSR(c, sp_call, 0x4100); } /* await_next_mode_seven_scene_vblank */
    uint16_t a_all10 = r->a;
    BUS8_SET(c, (db_ret2 << 0x10) + 0x420C, 0);
    BUS8_SET(c, (db_ret2 << 0x10) + 0x2121, 0);
    BUS8_SET(c, (db_ret2 << 0x10) + 0x2122, RAM8(0x0048));
    BUS8_SET(c, (db_ret2 << 0x10) + 0x2122, RAM8(0x0049));
    RAM8(0x002C) = 3;
    RAM16_SET(0x002E, 0x10);
    uint8_t a_hi2 = a_all10 >> 8;
    uint16_t y2 = y_ret6;
    uint8_t data_bank2 = db_ret2;
    for (;;) {
        r->a = (a_hi2 << 8) | a;
        r->y = y2;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank2;
        r->dp = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x4125, 0xC646C5); GUARD_JSL(c, sp_call, 0x4125); } /* upload_complete_mode_seven_scene_oam_buffer */
        uint16_t value4 = RAM16(0x004A);
        uint16_t value5 = RAM16(0x002E);
        RAM16_SET(0x004A, (uint16_t)(value4 + value5));
        RAM8(0x002C)--;
        if (RAM8(0x002C) != 0) {
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x411E, 0xC64285); GUARD_JSR(c, sp_call, 0x411E); } /* clip_and_pack_visible_mode_seven_transition_objects */
            uint8_t db_ret3 = r->db;
            uint16_t y_ret7 = r->y;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x4121, 0xC6459C); GUARD_JSR(c, sp_call, 0x4121); } /* await_next_mode_seven_scene_vblank */
            uint16_t a_all13 = r->a;
            a_hi2 = a_all13 >> 8;
            y2 = y_ret7;
            data_bank2 = db_ret3;
            continue;
        }
        RAM8(0x002C) = 3;
        RAM8(0x002E)--;
        if (RAM8(0x002E) != 1) {
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x411E, 0xC64285); GUARD_JSR(c, sp_call, 0x411E); } /* clip_and_pack_visible_mode_seven_transition_objects */
            uint8_t db_ret4 = r->db;
            uint16_t y_ret8 = r->y;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x4121, 0xC6459C); GUARD_JSR(c, sp_call, 0x4121); } /* await_next_mode_seven_scene_vblank */
            uint16_t a_all15 = r->a;
            a_hi2 = a_all15 >> 8;
            y2 = y_ret8;
            data_bank2 = db_ret4;
            continue;
        }
        a_hi2 = (uint16_t)(value4 + value5) >> 8;
        break;
    }
    r->y = y2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank2;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4143, 0xC64285); GUARD_JSR(c, sp_call, 0x4143); } /* clip_and_pack_visible_mode_seven_transition_objects */
    uint8_t db_ret5 = r->db;
    uint16_t y_ret9 = r->y;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4146, 0xC6459C); GUARD_JSR(c, sp_call, 0x4146); } /* await_next_mode_seven_scene_vblank */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x414A, 0xC646C5); GUARD_JSL(c, sp_call, 0x414A); } /* upload_complete_mode_seven_scene_oam_buffer */
    BUS8_SET(c, (db_ret5 << 0x10) + 0x210D, 0x4C);
    BUS8_SET(c, (db_ret5 << 0x10) + 0x210D, 0xFF);
    RAM8(0x004D) = 0xD9;
    BUS8_SET(c, (db_ret5 << 0x10) + 0x210E, 0xD9);
    BUS8_SET(c, (db_ret5 << 0x10) + 0x210E, 0xFF);
    BUS8_SET(c, (db_ret5 << 0x10) + 0x211F, 0xFF);
    BUS8_SET(c, (db_ret5 << 0x10) + 0x211F, 0);
    BUS8_SET(c, (db_ret5 << 0x10) + 0x2120, 0xFF);
    BUS8_SET(c, (db_ret5 << 0x10) + 0x2120, 0);
    RAM8(0x0044) = 0x30;
    RAM16_SET(0x0040, 1);
    RAM16_SET(0x0042, 1);
    RAM16_SET(0x0046, 1);
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x417C, 0xC644DB); GUARD_JSR(c, sp_call, 0x417C); } /* compute_signed_mode_seven_transition_matrix */
    uint16_t value8 = RAM16(0x004A);
    RAM16_SET(0x004A, (uint16_t)(value8 + 1));
    RAM8(0x0045) = 0;
    uint8_t a_hi3 = (uint16_t)(value8 + 1) >> 8;
    uint16_t y3 = y_ret9;
    uint8_t data_bank3 = db_ret5;
    for (;;) {
        r->y = y3;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank3;
        r->dp = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x418D, 0xC64285); GUARD_JSR(c, sp_call, 0x418D); } /* clip_and_pack_visible_mode_seven_transition_objects */
        uint8_t db_ret6 = r->db;
        uint16_t y_ret10 = r->y;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4190, 0xC6459C); GUARD_JSR(c, sp_call, 0x4190); } /* await_next_mode_seven_scene_vblank */
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x4194, 0xC646C5); GUARD_JSL(c, sp_call, 0x4194); } /* upload_complete_mode_seven_scene_oam_buffer */
        BUS8_SET(c, (db_ret6 << 0x10) + 0x210E, RAM8(0x004D));
        BUS8_SET(c, (db_ret6 << 0x10) + 0x210E, 0xFF);
        RAM8(0x004D)--;
        BUS8_SET(c, (db_ret6 << 0x10) + 0x211F, 0x10);
        BUS8_SET(c, (db_ret6 << 0x10) + 0x211F, 0);
        BUS8_SET(c, (db_ret6 << 0x10) + 0x2120, 0x10);
        BUS8_SET(c, (db_ret6 << 0x10) + 0x2120, 0);
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x41B1, 0xC644DB); GUARD_JSR(c, sp_call, 0x41B1); } /* compute_signed_mode_seven_transition_matrix */
        RAM8(0x0044)--;
        if (RAM8(0x0044) & 0x80) {
            RAM8(0x0044) = 0x47;
        }
        uint16_t value10 = RAM16(0x0046);
        RAM16_SET(0x0030, value10);
        RAM8(0x0033) = RAM8(0x0045);
        r->x = value10;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x41C4, 0xC645D3); GUARD_JSR(c, sp_call, 0x41C4); } /* scale_mode_seven_scene_step_by_two_hardware_products */
        uint16_t value12 = RAM16(0x0030);
        uint16_t value13 = RAM16(0x0032);
        RAM16_SET(0x0032, RAM16(0x0032) >> 1);
        uint16_t value14 = RAM16(0x0032);
        RAM16_SET(0x0032, RAM16(0x0032) >> 1);
        uint16_t value15 = RAM16(0x0046);
        RAM16_SET(0x0040, (uint16_t)(((((value12 >> 1) | ((value13 & 1) << 0x0F)) >> 1) | ((value14 & 1) << 0x0F)) + value15));
        RAM16_SET(0x0042, (uint16_t)(((((value12 >> 1) | ((value13 & 1) << 0x0F)) >> 1) | ((value14 & 1) << 0x0F)) + value15));
        uint16_t value16 = RAM16(0x004A);
        RAM16_SET(0x004A, (uint16_t)(value16 + 1));
        RAM8(0x0045)++;
        if (RAM8(0x0045) >= 4) {
            uint8_t value18 = RAM8(0x0046);
            RAM8(0x0046) <<= 1;
            RAM8(0x0047) = (uint8_t)((RAM8(0x0047) << 1) | (value18 >> 7));
            RAM8(0x0045) = 0;
        }
        uint16_t value20 = RAM16(0x0046);
        a_hi3 = (uint16_t)(value16 + 1) >> 8;
        y3 = y_ret10;
        data_bank3 = db_ret6;
        if (!(value20 != 0)) break;
    }
    r->a = (a_hi3 << 8) | a;
    r->y = y3;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank3;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x41F4, 0xC645BA); GUARD_JSR(c, sp_call, 0x41F4); } /* fade_mode_seven_scene_over_seventeen_vblanks */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC64028, SOM_RTS, "gen", run_complete_three_phase_mode_seven_transition, 0, 0, 1, 1, 0, 462, 187)
