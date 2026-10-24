#include "som_c.h"

/* C181AF advance_and_finish_native_motion_effect_frame_script   [class B, 67 bytes, 30 instructions]
 * Source: src/rom/advance_and_finish_native_motion_effect_frame_script.s
 * Documented in docs/actor-visual-effect-scripts.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void advance_and_finish_native_motion_effect_frame_script(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a_hi_81bc = 0;
    uint16_t x_81bc = 0;
    uint16_t y_81bc = 0;
    bool carry_81bc = 0;
    bool overflow_81bc = 0;
    uint8_t value = RAM8(0xE110 + x);
    if (value != 5) {
        a_hi_81bc = a_hi;
        x_81bc = x;
        y_81bc = y;
        carry_81bc = value >= 5;
        overflow_81bc = overflow;
        goto shared_81BC;
    }
    if (RAM8(0xE114 + x) == 0) {
        a_hi_81bc = a_hi;
        x_81bc = x;
        y_81bc = y;
        carry_81bc = value >= 5;
        overflow_81bc = overflow;
        goto shared_81BC;
    }
    r->c = value >= 5;
    RETURN_RTS(c);
    shared_81BC:;
    r->a = (a_hi_81bc << 8) | a;
    r->x = x_81bc;
    r->y = y_81bc;
    r->c = carry_81bc;
    r->v = overflow_81bc;
    r->mf = true;
    r->xf = false;
    r->db = 0x7E;
    r->dp = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x81BE, 0xC18276); GUARD_JSR(c, sp_call, 0x81BE); } /* consume_native_visual_frame_script_pose_or_terminator */
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    bool carry_ret = r->c;
    if (carry_ret) {
        uint8_t value3 = RAM8(0xE121 + x_ret2);
        RAM8(0x0000 + sp0) = value3;
        RAM8(0xE060 + x_ret2) = 0;
        RAM8(0xE00C + x_ret2) = 0;
        RAM8(0xE084 + x_ret2) = 0;
        if (x_ret) {
            r->a = (a_all >> 8 << 8) | value3;
            r->x = (uint8_t)x_ret2;
            r->y = (uint8_t)x_ret2;
            r->mf = true;
            r->xf = true;
            r->sp -= 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x81D4, 0xC181F2); GUARD_JSR(c, sp_call, 0x81D4); } /* restore_target_state_after_previous_cast */
            r->sp += 1;
            r->mf = false;
            r->sp -= 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x81D7, 0xC18DAB); GUARD_JSR(c, sp_call, 0x81D7); } /* restore_actor_weapon_after_cast */
            r->sp += 1;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            bool x_ret5 = r->xf;
            uint16_t a_all3 = r->a;
            uint16_t x_ret6 = r->x;
            uint16_t y_ret3 = r->y;
            bool overflow_ret3 = r->v;
            uint8_t value4 = RAM8(0x0000 + sp0);
            bool x_flag2;
            uint8_t a_hi2;
            uint16_t x2;
            uint16_t y2;
            bool carry2;
            bool overflow2;
            uint8_t data_bank2;
            if (value4 != 6) {
                x_flag2 = x_ret5;
                a_hi2 = a_all3 >> 8;
                x2 = x_ret6;
                y2 = y_ret3;
                carry2 = value4 >= 6;
                overflow2 = overflow_ret3;
                data_bank2 = db_ret;
            } else {
                uint16_t value5 = BUS16(c, (db_ret << 0x10) + 0x0108);
                bool m_flag;
                bool x_flag;
                uint8_t a_hi1;
                uint16_t x1;
                uint16_t y1;
                bool carry1;
                bool overflow1;
                uint8_t data_bank;
                if (value5 == 0) {
                    m_flag = 0;
                    x_flag = x_ret5;
                    a_hi1 = value5 >> 8;
                    x1 = x_ret6;
                    y1 = y_ret3;
                    carry1 = value4 >= 6;
                    overflow1 = overflow_ret3;
                    data_bank = db_ret;
                } else {
                    r->a = value5 | 0x0800;
                    r->c = value4 >= 6;
                    r->mf = false;
                    { const uint16_t sp_call = r->sp; JSL(c, 0x81EC, 0xC1E76D); GUARD_JSL(c, sp_call, 0x81EC); } /* event_command_map_context_entry */
                    uint8_t db_ret2 = r->db;
                    bool x_ret7 = r->xf;
                    uint16_t a_all4 = r->a;
                    uint16_t x_ret8 = r->x;
                    uint16_t y_ret4 = r->y;
                    bool carry_ret4 = r->c;
                    bool overflow_ret4 = r->v;
                    m_flag = 1;
                    x_flag = x_ret7;
                    a_hi1 = a_all4 >> 8;
                    x1 = x_ret8;
                    y1 = y_ret4;
                    carry1 = carry_ret4;
                    overflow1 = overflow_ret4;
                    data_bank = db_ret2;
                }
                RAM8(0x00E0 + dp_ret) = 0;
                x_flag2 = x_flag;
                a_hi2 = a_hi1;
                x2 = x1;
                y2 = y1;
                carry2 = carry1;
                overflow2 = overflow1;
                data_bank2 = data_bank;
            }
            r->a = (a_hi2 << 8) | a;
            r->x = x2;
            r->y = y2;
            r->c = carry2;
            r->v = overflow2;
            r->mf = true;
            r->xf = x_flag2;
            r->db = data_bank2;
            RETURN_RTS(c);
        } else {
            r->a = (a_all >> 8 << 8) | value3;
            r->y = x_ret2;
            r->mf = true;
            r->xf = false;
            r->sp -= 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x81D4, 0xC181F2); GUARD_JSR(c, sp_call, 0x81D4); } /* restore_target_state_after_previous_cast */
            r->sp += 1;
            r->mf = false;
            r->sp -= 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x81D7, 0xC18DAB); GUARD_JSR(c, sp_call, 0x81D7); } /* restore_actor_weapon_after_cast */
            r->sp += 1;
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret3 = r->db;
            bool x_ret11 = r->xf;
            uint16_t a_all6 = r->a;
            uint16_t x_ret12 = r->x;
            uint16_t y_ret6 = r->y;
            bool overflow_ret6 = r->v;
            uint8_t value6 = RAM8(0x0000 + sp0);
            bool x_flag4;
            uint8_t a_hi4;
            uint16_t x4;
            uint16_t y4;
            bool carry4;
            bool overflow4;
            uint8_t data_bank4;
            if (value6 != 6) {
                x_flag4 = x_ret11;
                a_hi4 = a_all6 >> 8;
                x4 = x_ret12;
                y4 = y_ret6;
                carry4 = value6 >= 6;
                overflow4 = overflow_ret6;
                data_bank4 = db_ret3;
            } else {
                uint16_t value7 = BUS16(c, (db_ret3 << 0x10) + 0x0108);
                bool m_flag2;
                bool x_flag3;
                uint8_t a_hi3;
                uint16_t x3;
                uint16_t y3;
                bool carry3;
                bool overflow3;
                uint8_t data_bank3;
                if (value7 == 0) {
                    m_flag2 = 0;
                    x_flag3 = x_ret11;
                    a_hi3 = value7 >> 8;
                    x3 = x_ret12;
                    y3 = y_ret6;
                    carry3 = value6 >= 6;
                    overflow3 = overflow_ret6;
                    data_bank3 = db_ret3;
                } else {
                    r->a = value7 | 0x0800;
                    r->c = value6 >= 6;
                    r->mf = false;
                    { const uint16_t sp_call = r->sp; JSL(c, 0x81EC, 0xC1E76D); GUARD_JSL(c, sp_call, 0x81EC); } /* event_command_map_context_entry */
                    uint8_t db_ret4 = r->db;
                    bool x_ret13 = r->xf;
                    uint16_t a_all7 = r->a;
                    uint16_t x_ret14 = r->x;
                    uint16_t y_ret7 = r->y;
                    bool carry_ret7 = r->c;
                    bool overflow_ret7 = r->v;
                    m_flag2 = 1;
                    x_flag3 = x_ret13;
                    a_hi3 = a_all7 >> 8;
                    x3 = x_ret14;
                    y3 = y_ret7;
                    carry3 = carry_ret7;
                    overflow3 = overflow_ret7;
                    data_bank3 = db_ret4;
                }
                RAM8(0x00E0 + dp_ret2) = 0;
                x_flag4 = x_flag3;
                a_hi4 = a_hi3;
                x4 = x3;
                y4 = y3;
                carry4 = carry3;
                overflow4 = overflow3;
                data_bank4 = data_bank3;
            }
            r->a = (a_hi4 << 8) | a;
            r->x = x4;
            r->y = y4;
            r->c = carry4;
            r->v = overflow4;
            r->mf = true;
            r->xf = x_flag4;
            r->db = data_bank4;
            RETURN_RTS(c);
        }
    }
    r->mf = true;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC181AF, SOM_RTS, "hand", advance_and_finish_native_motion_effect_frame_script, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 67, 30)
