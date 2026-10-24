#include "som_c.h"

/* C0C059 slide_special_scene_camera_across_128_real_frames   [class B, 79 bytes, 33 instructions]
 * Source: src/rom/slide_special_scene_camera_across_128_real_frames.s
 * Documented in docs/map-camera-transition.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void slide_special_scene_camera_across_128_real_frames(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x010F);
    if ((value ^ 0x80) != 0) {
        SET_A8(r, value ^ 0x80);
        r->z = (value ^ 0x80) == 0;
        r->n = (value ^ 0x80) & 0x80;
        RETURN_RTS(c);
    }
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x010E);
    if (value2 == 0xFF) {
        { const uint16_t sp_call = r->sp; JSL(c, 0xC06D, 0xC1FD37); GUARD_JSL(c, sp_call, 0xC06D); } /* shift_and_align_three_party_horizontal_positions */
        uint16_t a_all = r->a;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        RAM8(0x001F + dp) = 0x80;
        uint8_t a1 = 0x80;
        uint8_t a_hi1 = a_all >> 8;
        uint16_t x1 = x;
        uint16_t y1 = y;
        bool carry1 = carry_ret;
        bool zero1 = 0;
        bool negative1 = 1;
        bool overflow1 = overflow_ret;
        uint8_t data_bank = db;
        uint16_t direct_page = dp;
        for (;;) {
            RAM8(0x0084 + direct_page) = 0x88;
            RAM8(0x0086 + direct_page) = 0;
            r->a = (a_hi1 << 8) | 0x88;
            r->x = x1;
            r->y = y1;
            r->c = carry1;
            r->z = 0;
            r->n = 1;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank;
            r->dp = direct_page;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC07C, 0xC0D1F9); GUARD_JSR(c, sp_call, 0xC07C); } /* move_scene_camera_entry */
            { const uint16_t sp_call = r->sp; JSR(c, 0xC07F, 0xC0C59F); GUARD_JSR(c, sp_call, 0xC07F); } /* detect_map_scroll_edges_and_prepare_both_layer_tile_buffers */
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC082, 0xC0BCCC); GUARD_JSR(c, sp_call, 0xC082); } /* initialize_software_oam_and_optional_spell_frames */
            { const uint16_t sp_call = r->sp; JSR(c, 0xC085, 0xC0E38E); GUARD_JSR(c, sp_call, 0xC085); } /* emit_complete_map_actor_and_hud_sprites */
            { const uint16_t sp_call = r->sp; JSR(c, 0xC088, 0xC0BCAB); GUARD_JSR(c, sp_call, 0xC088); } /* finalize_software_oam_hidden_sprite_tail */
            uint16_t dp_ret3 = r->dp;
            uint8_t db_ret4 = r->db;
            bool x_ret9 = r->xf;
            uint16_t a_all6 = r->a;
            uint16_t x_ret10 = r->x;
            uint16_t y_ret5 = r->y;
            bool carry_ret6 = r->c;
            bool overflow_ret6 = r->v;
            RAM8(0xE00F) = 8;
            RAM8(0xE20F) = 8;
            RAM8(0xE40F) = 8;
            RAM8(0x00EC + dp_ret3) = 1;
            bool overflow2 = overflow_ret6;
            for (;;) {
                uint8_t value3 = RAM8(0x00EC + dp_ret3);
                overflow2 = value3 & 0x40;
                if (!((value3 & 1) != 0)) break;
            }
            RAM8(0x001F + dp_ret3)--;
            if (x_ret9 != 0) { c->fail = 3; return; }
            a1 = 1;
            a_hi1 = a_all6 >> 8;
            x1 = x_ret10;
            y1 = y_ret5;
            carry1 = carry_ret6;
            zero1 = RAM8(0x001F + dp_ret3) == 0;
            negative1 = RAM8(0x001F + dp_ret3) & 0x80;
            overflow1 = overflow2;
            data_bank = db_ret4;
            direct_page = dp_ret3;
            if (!(RAM8(0x001F + direct_page) != 0)) break;
        }
        r->a = (a_hi1 << 8) | a1;
        r->x = (uint8_t)x1;
        r->y = (uint8_t)y1;
        r->c = carry1;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 1;
        r->db = data_bank;
        r->dp = direct_page;
        RETURN_RTS(c);
    }
    SET_A8(r, value2);
    r->c = value2 >= 0xFF;
    r->z = value2 == 0xFF;
    r->n = (uint8_t)(value2 - 0xFF) & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0C059, SOM_RTS, "gen", slide_special_scene_camera_across_128_real_frames, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 79, 33)
