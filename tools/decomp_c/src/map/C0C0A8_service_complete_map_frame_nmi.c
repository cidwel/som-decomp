#include "som_c.h"

/* C0C0A8 service_complete_map_frame_nmi   [class D, 200 bytes, 88 instructions]
 * Source: src/rom/service_complete_map_frame_nmi.s
 * Entry: M=any X=any DB=any D=any.  Callers read: nothing.
 */
static void service_complete_map_frame_nmi(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = a >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 2) = x >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 4) = y >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)y;
    RAM8(0x0000 + sp0 - 6) = dp >> 8;
    RAM8(0x0000 + sp0 - 7) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 8) = db;
    RAM8(0x0000 + sp0 - 9) = 0;
    uint8_t value = BUS8(c, 0x004210);
    BUS8_SET(c, 0x002100, 0x8F);
    BUS8_SET(c, 0x00420C, 0);
    uint8_t value2 = RAM8(0x0029);
    if ((value2 & 4) != 0) {
        BUS8_SET(c, 0x002105, value2);
        BUS8_SET(c, 0x00212C, RAM8(0x0021));
    }
    uint8_t value4 = RAM8(0x1D04);
    uint8_t a_hi3;
    if ((value4 & 0x20) != 0) {
        BUS8_SET(c, 0x002121, 0);
        uint8_t value5 = RAM8(0x002A);
        uint16_t x1;
        if (value5 == 0) {
            x1 = 0x0600;
        } else {
            x1 = 0xBE00;
        }
        BUS16_SET(c, 0x004372, x1);
        BUS16_SET(c, 0x004370, 0x2200);
        BUS8_SET(c, 0x004374, 0x7E);
        BUS16_SET(c, 0x004375, 0x0200);
        BUS8_SET(c, 0x00420B, 0x80);
        a_hi3 = 0;
    } else {
        uint8_t value6 = RAM8(0x010E);
        uint8_t value7 = RAM8(0x010F);
        uint8_t a_hi2;
        if ((value6 | value7) == 0) {
            if ((RAM8(0x00EC) & 5) != 0) {
                BUS8_SET(c, 0x002121, 0);
                uint8_t value9 = RAM8(0x002A);
                uint16_t x2;
                if (value9 == 0) {
                    x2 = 0x0600;
                } else {
                    x2 = 0xBE00;
                }
                BUS16_SET(c, 0x004372, x2);
                BUS16_SET(c, 0x004370, 0x2200);
                BUS8_SET(c, 0x004374, 0x7E);
                BUS16_SET(c, 0x004375, 0x0200);
                BUS8_SET(c, 0x00420B, 0x80);
            }
            a_hi2 = 0;
        } else {
            uint8_t value10 = RAM8(0x002C);
            RAM8(0x002C) &= 0xFC;
            uint8_t a_hi1;
            if ((value10 & 3) == 0) {
                if ((RAM8(0x00EC) & 5) != 0) {
                    BUS8_SET(c, 0x002121, 0);
                    uint8_t value12 = RAM8(0x002A);
                    uint16_t x3;
                    if (value12 == 0) {
                        x3 = 0x0600;
                    } else {
                        x3 = 0xBE00;
                    }
                    BUS16_SET(c, 0x004372, x3);
                    BUS16_SET(c, 0x004370, 0x2200);
                    BUS8_SET(c, 0x004374, 0x7E);
                    BUS16_SET(c, 0x004375, 0x0200);
                    BUS8_SET(c, 0x00420B, 0x80);
                }
                a_hi1 = 0;
            } else {
                r->a = 3;
                r->z = (value10 & 3) == 0;
                r->n = 0;
                r->mf = 1;
                r->xf = 0;
                r->db = 0;
                r->dp = 0;
                r->sp -= 9;
                { const uint16_t sp_call = r->sp; JSR(c, 0xC0E7, 0xC0C42C); GUARD_JSR(c, sp_call, 0xC0E7); } /* restore_map_saved_palette_rows */
                r->sp += 9;
                uint16_t a_all = r->a;
                BUS8_SET(c, 0x002121, 0);
                uint8_t value13 = RAM8(0x002A);
                uint16_t x4;
                if (value13 == 0) {
                    x4 = 0x0600;
                } else {
                    x4 = 0xBE00;
                }
                BUS16_SET(c, 0x004372, x4);
                BUS16_SET(c, 0x004370, 0x2200);
                BUS8_SET(c, 0x004374, 0x7E);
                BUS16_SET(c, 0x004375, 0x0200);
                BUS8_SET(c, 0x00420B, 0x80);
                a_hi1 = a_all >> 8;
            }
            a_hi2 = a_hi1;
        }
        a_hi3 = a_hi2;
    }
    uint8_t value14 = RAM8(0x00EC);
    if ((value14 & 9) != 0) {
        BUS16_SET(c, 0x002102, 0);
        BUS16_SET(c, 0x004372, 0x0800);
        BUS16_SET(c, 0x004370, 0x0400);
        BUS8_SET(c, 0x004374, 0);
        BUS16_SET(c, 0x004375, 0x0220);
        BUS8_SET(c, 0x00420B, 0x80);
    }
    bool x_flag;
    uint8_t a_hi4;
    bool carry1;
    uint8_t data_bank;
    uint16_t direct_page;
    if ((value14 & 1) == 0) {
        x_flag = 0;
        a_hi4 = a_hi3;
        carry1 = carry;
        data_bank = 0;
        direct_page = 0;
    } else {
        RAM16_SET(0x00F4, (uint16_t)(RAM16(0x00F4) + 1));
        uint16_t value15 = RAM16(0x00F4);
        r->a = (a_hi3 << 8) | 1;
        r->z = value15 == 0;
        r->n = value15 & 0x8000;
        r->v = value14 & 0x40;
        r->mf = 0;
        r->xf = 0;
        r->db = 0;
        r->dp = 0;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC14A, 0xC0C692); GUARD_JSR(c, sp_call, 0xC14A); } /* upload_pending_map_tile_rows_and_columns */
        r->sp += 9;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC14D, 0xC0C238); GUARD_JSR(c, sp_call, 0xC14D); } /* upload_map_frame_hud_and_animated_characters */
        r->sp += 9;
        r->mf = 1;
        r->xf = 1;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSL(c, 0xC151, 0x01950D); GUARD_JSL(c, sp_call, 0xC151); } /* upload_complete_actor_frame_tiles */
        r->sp += 9;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC154, 0xC0C170); GUARD_JSR(c, sp_call, 0xC154); } /* write_map_frame_background_scroll */
        r->sp += 9;
        bool x_ret6 = r->xf;
        uint16_t a_all5 = r->a;
        bool carry_ret3 = r->c;
        x_flag = x_ret6;
        a_hi4 = a_all5 >> 8;
        carry1 = carry_ret3;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    r->c = carry1;
    r->mf = 1;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = direct_page;
    r->sp -= 9;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC157, 0xC0C1E7); GUARD_JSR(c, sp_call, 0xC157); } /* upload_map_menu_and_prepare_palette_hdma */
    r->sp += 9;
    uint8_t db_ret2 = r->db;
    uint8_t value16 = BUS8_RDP(c, (uint16_t)(direct_page + 0x2C));
    BUS8_SET(c, (db_ret2 << 0x10) + 0x420C, value16);
    uint8_t value17 = BUS8_RDP(c, (uint16_t)(direct_page + 0xE6));
    BUS8_SET(c, (db_ret2 << 0x10) + 0x2100, value17);
    uint8_t value18 = BUS8_RDP(c, (uint16_t)(direct_page + 0xEC));
    BUS8_SET(c, (uint16_t)(direct_page + 0xEC), 0);
    uint8_t value19 = RAM8(0x0000 + sp0 - 8);
    uint8_t value20 = RAM8(0x0000 + sp0 - 7);
    uint8_t value21 = RAM8(0x0000 + sp0 - 6);
    r->db = value19;
    r->dp = (value21 << 8) | value20;
    RETURN_RTI(c);
}
SOM_REGISTER(0xC0C0A8, SOM_RTI, "gen", service_complete_map_frame_nmi, 0, 0, 10, -1, -1, 200, 88)
