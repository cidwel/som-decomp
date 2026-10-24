#include "som_c.h"

/* C073DB dispatch_native_misc_ring_inventory_targets_and_five_modal_pages   [class B, 164 bytes, 63 instructions]
 * Source: src/rom/dispatch_native_misc_ring_inventory_targets_and_five_modal_pages.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void dispatch_native_misc_ring_inventory_targets_and_five_modal_pages(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    RAM8(0x0000 + 0x19FD) = RAM8(0x1836);
    BUS8_SET(c, 0x19FE, RAM8(RING_OWNER));
    BUS8_SET(c, 0x19FF, RAM8(0x1802));
    RAM8(0x19F0) = 0xC0;
    uint8_t value3 = RAM8(0x1876);
    if (value3 == 0) {
        r->a = (a >> 8 << 8) | value3;
        r->x = 0x19FD;
        r->z = value3 == 0;
        r->n = value3 & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x741A, 0xD9FC90); GUARD_JSL(c, sp_call, 0x741A); } /* check_native_menu_inventory_availability */
        bool zero_ret = r->z;
        if (zero_ret) {
            r->mf = 1;
            r->xf = 0;
            TAIL_CALL(c, 0xC07271, SOM_RTS); /* external */
        }
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x7420, 0xD0CF08); GUARD_JSL(c, sp_call, 0x7420); } /* request_native_menu_audio_0e */
        uint8_t db_ret = r->db;
        { const uint16_t sp_call = r->sp; JSL(c, 0x7424, 0xD0C83F); GUARD_JSL(c, sp_call, 0x7424); } /* hide_native_menu_icon_oam_objects */
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x7427, 0xC0692D); GUARD_JSR(c, sp_call, 0x7427); } /* request_event_menu_loop_and_initialize_input_state */
        uint8_t value4 = BUS8_RDP(c, (db_ret << 0x10) + 0x1803);
        BUS8_SET(c, (db_ret << 0x10) + 0x1803, value4 | 8);
        BUS8_SET(c, (db_ret << 0x10) + 0x1809, 4);
        SET_A8(r, 4);
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if ((uint8_t)(value3 - 1) == 0) {
        RAM8(0x19F0) = 0x80;
        RAM8(0x1842) = 0x80;
        r->a = (a >> 8 << 8) | 0x80;
        r->x = 0xFD;
        r->y = (uint8_t)y;
        r->z = 0;
        r->n = 1;
        r->mf = 1;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x7444, 0xD0DA60); GUARD_JSL(c, sp_call, 0x7444); } /* build_native_three_actor_menu_target_list_and_count */
        bool zero_ret5 = r->z;
        if (zero_ret5) {
            r->mf = 0;
            r->xf = 0;
            TAIL_CALL(c, 0xC07271, SOM_RTS); /* external */
        }
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x744A, 0xD0DB58); GUARD_JSL(c, sp_call, 0x744A); } /* select_native_menu_target_with_controller_edges_and_real_vblank */
        bool zero_ret6 = r->z;
        if (zero_ret6) {
            { const uint16_t sp_call = r->sp; JSL(c, 0x7456, 0xD0CF40); GUARD_JSL(c, sp_call, 0x7456); } /* request_native_menu_audio_a3 */
            uint8_t db_ret3 = r->db;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x745B, 0xC0787E); GUARD_JSR(c, sp_call, 0x745B); } /* encode_native_menu_target_mask_from_selected_actor_or_multi_target_flags */
            uint8_t value5 = BUS8_RDP(c, (db_ret3 << 0x10) + 0x19F3);
            uint16_t value6 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x1844);
            RAM8(0x002C + value6) = value5;
            r->a = 0;
            r->x = value6 & 0x0600;
            r->z = 1;
            r->n = 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0x7477, 0xC10024); GUARD_JSL(c, sp_call, 0x7477); } /* call_actor_status_program_long */
            if (r->mf != 0) { c->fail = 3; return; }
            BUS16_SET(c, (db_ret3 << 0x10) + 0x19F0, 0x01C0);
            r->a = 0x01C0;
            r->z = 0;
            r->n = 0;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        TAIL_CALL(c, 0xC07275, SOM_RTS); /* external */
    }
    r->a = (a >> 8 << 8) | (uint8_t)(value3 - 1);
    r->x = 0x19FD;
    r->z = (uint8_t)(value3 - 1) == 0;
    r->n = (uint8_t)(value3 - 1) & 0x80;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x73FF, 0xD0CF08); GUARD_JSL(c, sp_call, 0x73FF); } /* request_native_menu_audio_0e */
    bool m_ret4 = r->mf;
    uint16_t a_all10 = r->a;
    if (m_ret4) {
        RAM8(0x0000 + sp0) = (uint8_t)a_all10;
        r->mf = 1;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x7404, 0xC00095); GUARD_JSL(c, sp_call, 0x7404); } /* close_dialogue_public_jump */
        r->sp += 1;
        uint16_t a_all11 = r->a;
        uint8_t value7 = RAM8(0x0000 + sp0);
        r->a = (a_all11 >> 8 << 8) | value7;
        r->z = value7 == 0;
        r->n = value7 & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x7409, 0xC0000F); GUARD_JSL(c, sp_call, 0x7409); } /* jump_public_native_name_menu */
        { const uint16_t sp_call = r->sp; JSL(c, 0x740D, 0xC20018); GUARD_JSL(c, sp_call, 0x740D); } /* public_first_three_boss_animation_control_jump */
        uint8_t db_ret6 = r->db;
        uint16_t value8 = BUS16_RDP(c, (db_ret6 << 0x10) + 0x19CE);
        r->sp = value8;
        som_task_note(c);
        sp0 = r->sp;
        if (r->sp < 0x100 || sp0 > 0x1FFF) { c->fail = 3; return; }
        r->a = value8;
        r->z = value8 == 0;
        r->n = value8 & 0x8000;
        r->mf = 0;
        TAIL_CALL(c, 0xC0645C, SOM_RTS); /* restore_inventory_menu_direct_page_bank_and_status */
    } else {
        RAM8(0x0000 + sp0) = a_all10 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)a_all10;
        r->mf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSL(c, 0x7404, 0xC00095); GUARD_JSL(c, sp_call, 0x7404); } /* close_dialogue_public_jump */
        r->sp += 2;
        uint8_t value9 = RAM8(0x0000 + sp0 - 1);
        uint8_t value10 = RAM8(0x0000 + sp0);
        r->a = (value10 << 8) | value9;
        r->z = ((value10 << 8) | value9) == 0;
        r->n = ((value10 << 8) | value9) & 0x8000;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x7409, 0xC0000F); GUARD_JSL(c, sp_call, 0x7409); } /* jump_public_native_name_menu */
        { const uint16_t sp_call = r->sp; JSL(c, 0x740D, 0xC20018); GUARD_JSL(c, sp_call, 0x740D); } /* public_first_three_boss_animation_control_jump */
        uint8_t db_ret8 = r->db;
        uint16_t value11 = BUS16_RDP(c, (db_ret8 << 0x10) + 0x19CE);
        r->sp = value11;
        som_task_note(c);
        sp0 = r->sp;
        if (r->sp < 0x100 || sp0 > 0x1FFF) { c->fail = 3; return; }
        r->a = value11;
        r->z = value11 == 0;
        r->n = value11 & 0x8000;
        r->mf = 0;
        TAIL_CALL(c, 0xC0645C, SOM_RTS); /* restore_inventory_menu_direct_page_bank_and_status */
    }
}
SOM_REGISTER(0xC073DB, SOM_RTS, "gen", dispatch_native_misc_ring_inventory_targets_and_five_modal_pages, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 164, 63)
