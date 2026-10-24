#include "som_c.h"

static void refresh_mask_selected_idle_hero_weapon_graphics(SomCtx *c);
static void refresh_mask_selected_idle_hero_weapon_graphics_v2(SomCtx *c);

/* C1DB6B dispatch_queued_actor_weapon_cast_or_motion_request   [class C, 220 bytes, 98 instructions]
 * Source: src/rom/dispatch_queued_actor_weapon_cast_or_motion_request.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void dispatch_queued_actor_weapon_cast_or_motion_request(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x19F0);
    if (!(value & 0x80)) {
        if (value != 0) {
            if (value != 1) {
                if (value == 2) {
                    uint8_t value2 = RAM8(0x19F2);
                    bool m_flag;
                    bool x_flag;
                    uint8_t a_hi1;
                    uint16_t x1;
                    uint16_t y1;
                    bool carry1;
                    bool overflow1;
                    uint8_t data_bank;
                    uint16_t direct_page;
                    if (!(value2 & 0x01)) {
                        m_flag = 1;
                        x_flag = 0;
                        a_hi1 = a >> 8;
                        x1 = x;
                        y1 = y;
                        carry1 = value2 & 0x01;
                        overflow1 = overflow;
                        data_bank = 0x7E;
                        direct_page = 0;
                    } else {
                        r->a = (a >> 8 << 8) | 0;
                        r->c = value2 & 0x01;
                        r->z = 1;
                        r->n = 0;
                        r->mf = 1;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDB97, refresh_mask_selected_idle_hero_weapon_graphics, sp_in, 2); GUARD_JSR(c, sp_call, 0xDB97); }
                        uint16_t dp_ret = r->dp;
                        uint8_t db_ret = r->db;
                        bool m_ret = r->mf;
                        bool x_ret = r->xf;
                        uint16_t a_all = r->a;
                        uint16_t x_ret2 = r->x;
                        uint16_t y_ret = r->y;
                        bool carry_ret = r->c;
                        bool overflow_ret = r->v;
                        m_flag = m_ret;
                        x_flag = x_ret;
                        a_hi1 = a_all >> 8;
                        x1 = x_ret2;
                        y1 = y_ret;
                        carry1 = carry_ret;
                        overflow1 = overflow_ret;
                        data_bank = db_ret;
                        direct_page = dp_ret;
                    }
                    uint8_t value3 = BUS8_RDP(c, (data_bank << 0x10) + 0x19F2);
                    bool m_flag2;
                    bool x_flag2;
                    uint8_t a_hi2;
                    uint16_t x2;
                    uint16_t y2;
                    bool carry2;
                    bool overflow2;
                    uint8_t data_bank2;
                    uint16_t direct_page2;
                    if ((value3 & 2) == 0) {
                        m_flag2 = 1;
                        x_flag2 = x_flag;
                        a_hi2 = a_hi1;
                        x2 = x1;
                        y2 = y1;
                        carry2 = carry1;
                        overflow2 = overflow1;
                        data_bank2 = data_bank;
                        direct_page2 = direct_page;
                    } else {
                        r->a = a_hi1 << 8 | (value3 & 2);
                        r->x = x1;
                        r->y = y1;
                        r->c = carry1;
                        r->z = (value3 & 2) == 0;
                        r->n = value3 & 2 & 0x80;
                        r->v = overflow1;
                        r->mf = 1;
                        r->xf = x_flag;
                        r->db = data_bank;
                        r->dp = direct_page;
                        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBA3, refresh_mask_selected_idle_hero_weapon_graphics_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xDBA3); }
                        uint16_t dp_ret2 = r->dp;
                        uint8_t db_ret2 = r->db;
                        bool m_ret2 = r->mf;
                        bool x_ret3 = r->xf;
                        uint16_t a_all2 = r->a;
                        uint16_t x_ret4 = r->x;
                        uint16_t y_ret2 = r->y;
                        bool carry_ret2 = r->c;
                        bool overflow_ret2 = r->v;
                        m_flag2 = m_ret2;
                        x_flag2 = x_ret3;
                        a_hi2 = a_all2 >> 8;
                        x2 = x_ret4;
                        y2 = y_ret2;
                        carry2 = carry_ret2;
                        overflow2 = overflow_ret2;
                        data_bank2 = db_ret2;
                        direct_page2 = dp_ret2;
                    }
                    uint8_t value4 = BUS8_RDP(c, (data_bank2 << 0x10) + 0x19F2);
                    if ((value4 & 4) != 0) {
                        r->a = a_hi2 << 8 | (value4 & 4);
                        r->x = x2;
                        r->y = y2;
                        r->c = carry2;
                        r->z = (value4 & 4) == 0;
                        r->n = value4 & 4 & 0x80;
                        r->v = overflow2;
                        r->mf = 1;
                        r->xf = x_flag2;
                        r->db = data_bank2;
                        r->dp = direct_page2;
                        refresh_mask_selected_idle_hero_weapon_graphics_v2(c); return;
                    }
                    r->a = a_hi2 << 8 | (value4 & 4);
                    r->x = x2;
                    r->y = y2;
                    r->c = carry2;
                    r->v = overflow2;
                    r->mf = 1;
                    r->xf = x_flag2;
                    r->db = data_bank2;
                    r->dp = direct_page2;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                r->c = value >= 2;
                r->mf = 1;
                RETURN_RTS(c);
            }
            uint8_t value5 = RAM8(0x19F1);
            if (!(value5 & 0x80)) {
                r->a = ((value5 & 3) << 1 << 8) | 0;
                r->x = ((value5 & 3) << 1 << 8) | 0;
                r->c = value5 & 3 & 0x80;
                r->z = (((value5 & 3) << 1 << 8) | 0) == 0;
                r->n = (((value5 & 3) << 1 << 8) | 0) & 0x8000;
                r->mf = 1;
                TAIL_CALL(c, 0xC188C7, SOM_RTS); /* prepare_guarded_actor_cast_request_and_party_graphics */
            }
            r->c = value >= 1;
            r->mf = 1;
            RETURN_RTS(c);
        }
        uint8_t value6 = RAM8(0x19F1);
        if (value6 != 7) {
            RAM8(0x0000 + sp0) = x >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
            r->a = (a >> 8 << 8) | value6;
            r->c = value6 >= 7;
            r->z = value6 == 7;
            r->n = (uint8_t)(value6 - 7) & 0x80;
            r->mf = 1;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0xDC34, 0xC1DC48); GUARD_JSR(c, sp_call, 0xDC34); } /* prepare_queued_native_motion_presentation */
            r->sp += 2;
            bool x_ret5 = r->xf;
            if (x_ret5) {
                c->fail = 3;
                return;
            } else {
                r->x = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
                r->xf = 0;
                RETURN_RTS(c);
            }
        }
        uint8_t value10 = RAM8(0x19F2);
        RAM16_SET(0x0014, ((value10 & 3) << 1 << 8) | 0);
        r->a = ((value10 & 3) << 1 << 8) | 0;
        r->x = ((value10 & 3) << 1 << 8) | 0;
        r->c = value10 & 3 & 0x80;
        r->z = (((value10 & 3) << 1 << 8) | 0) == 0;
        r->n = (((value10 & 3) << 1 << 8) | 0) & 0x8000;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xDBDB, 0xC1CA6C); GUARD_JSR(c, sp_call, 0xDBDB); } /* clear_actor_movement_charge_and_palette_effects */
        uint16_t a_all4 = r->a;
        uint16_t x_ret8 = r->x;
        RAM8(0xE04F + x_ret8) = 0x7F;
        RAM8(0xE104 + x_ret8) = 0;
        RAM8(0xE02F + x_ret8) = 5;
        RAM8(0xE00C + x_ret8) = 0;
        RAM8(0xE084 + x_ret8) = 0;
        RAM8(0xE006) = 0;
        RAM8(0xE007) = 0;
        RAM8(0xE206) = 0;
        RAM8(0xE207) = 0;
        RAM8(0xE406) = 0;
        RAM8(0xE407) = 0;
        uint8_t value11 = RAM8(0x00F4);
        RAM8(0x00F4) = (value11 & 0x1F) | 0x20;
        r->a = (a_all4 >> 8 << 8) | ((value11 & 0x1F) | 0x20);
        r->z = ((value11 & 0x1F) | 0x20) == 0;
        r->n = ((value11 & 0x1F) | 0x20) & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xDC0B, 0xC185D8); GUARD_JSR(c, sp_call, 0xDC0B); } /* load_object_weapon_palette_from_field_04f */
        RAM16_SET(0x0008, 0x40);
        RAM16_SET(0x0000, 0);
        r->a = 0xD4;
        r->y = 0x2850;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xDC21, 0x01C599); GUARD_JSL(c, sp_call, 0xDC21); } /* dispatch_object_graphics_plane_conversion */
        uint16_t value12 = RAM16(0x00DC);
        r->a = (value12 & 0xFF) | 0x0C00;
        r->z = ((value12 & 0xFF) | 0x0C00) == 0;
        r->n = ((value12 & 0xFF) | 0x0C00) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xDC2F, 0x01E76D); GUARD_JSL(c, sp_call, 0xDC2F); } /* event_command_map_context_entry */
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    if (value != 0xC0) {
        r->c = value >= 0xC0;
        r->mf = 1;
        RETURN_RTS(c);
    }
    RAM8(0x1D04) = 0;
    r->a = (a >> 8 << 8) | value;
    r->c = value >= 0xC0;
    r->z = value == 0xC0;
    r->n = (uint8_t)(value - 0xC0) & 0x80;
    r->mf = 1;
    TAIL_CALL(c, 0xC1FF3A, SOM_RTS); /* restore_event_screen_and_reenable_frame_interrupts */
}
SOM_REGISTER(0xC1DB6B, SOM_RTS, "gen", dispatch_queued_actor_weapon_cast_or_motion_request, 0, L_B | L_X | L_Y | L_C | L_V, 10, 0, 0, 221, 98)

/* C1DBAE refresh_mask_selected_idle_hero_weapon_graphics   [class A, 24 bytes, 11 instructions]
 * Source: src/rom/dispatch_queued_actor_weapon_cast_or_motion_request.s
 * Subroutine of dispatch_queued_actor_weapon_cast_or_motion_request, translated in place.
 * Entry: M=8 bit X=any DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void refresh_mask_selected_idle_hero_weapon_graphics(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xE060 + ((a << 8) | 0));
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    uint8_t data_bank;
    if (value != 0) {
        m_flag = 1;
        x_flag = 0;
        a1 = value;
        a_hi1 = a;
        x1 = (a << 8) | 0;
        y1 = y;
        carry1 = carry;
        zero1 = value == 0;
        negative1 = value & 0x80;
        overflow1 = overflow;
        data_bank = 0x7E;
    } else {
        RAM8(0xE069 + ((a << 8) | 0)) = 0;
        RAM8(0xE104 + ((a << 8) | 0)) = 0;
        r->a = (a << 8) | value;
        r->x = (a << 8) | 0;
        r->z = value == 0;
        r->n = value & 0x80;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xDBC4, 0x00E9F4); GUARD_JSL(c, sp_call, 0xDBC4); } /* refresh_actor_weapon_graphics_long */
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        bool overflow_ret = r->v;
        m_flag = m_ret;
        x_flag = x_ret;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = x_ret2;
        y1 = y_ret;
        carry1 = carry_ret;
        zero1 = zero_ret;
        negative1 = negative_ret;
        overflow1 = overflow_ret;
        data_bank = db_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = x_flag;
    r->db = data_bank;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}

/* C1DBAE refresh_mask_selected_idle_hero_weapon_graphics_v2   [class A, 24 bytes, 11 instructions]
 * Source: src/rom/dispatch_queued_actor_weapon_cast_or_motion_request.s
 * Subroutine of dispatch_queued_actor_weapon_cast_or_motion_request, translated in place.
 * Entry: M=8 bit X=any DB=any D=any.  Callers read: ABXYCZNV.
 */
static void refresh_mask_selected_idle_hero_weapon_graphics_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, -1)) return;
    const uint8_t a = r->a & 0xFF;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0xE060 + ((a << 8) | 0));
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    uint8_t data_bank;
    if (value != 0) {
        m_flag = 1;
        x_flag = 0;
        a1 = value;
        a_hi1 = a;
        x1 = (a << 8) | 0;
        y1 = y;
        carry1 = carry;
        zero1 = value == 0;
        negative1 = value & 0x80;
        overflow1 = overflow;
        data_bank = db;
    } else {
        BUS8_SET(c, (db << 0x10) + 0xE069 + ((a << 8) | 0), 0);
        BUS8_SET(c, (db << 0x10) + 0xE104 + ((a << 8) | 0), 0);
        r->a = (a << 8) | value;
        r->x = (a << 8) | 0;
        r->z = value == 0;
        r->n = value & 0x80;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xDBC4, 0x00E9F4); GUARD_JSL(c, sp_call, 0xDBC4); } /* refresh_actor_weapon_graphics_long */
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        bool overflow_ret = r->v;
        m_flag = m_ret;
        x_flag = x_ret;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = x_ret2;
        y1 = y_ret;
        carry1 = carry_ret;
        zero1 = zero_ret;
        negative1 = negative_ret;
        overflow1 = overflow_ret;
        data_bank = db_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = x_flag;
    r->db = data_bank;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
