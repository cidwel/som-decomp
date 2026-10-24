#include "som_c.h"

static void dispatch_native_visual_frame_script_control_operand(SomCtx *c);
static void dispatch_native_visual_frame_script_control_operand_v2(SomCtx *c);
static void dispatch_native_visual_frame_script_control_operand_v3(SomCtx *c);

/* C18276 consume_native_visual_frame_script_pose_or_terminator   [class C, 196 bytes, 95 instructions]
 * Source: src/rom/consume_native_visual_frame_script_pose_or_terminator.s
 * Documented in docs/actor-visual-effect-scripts.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void consume_native_visual_frame_script_pose_or_terminator(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0x0002) = 0xD1;
    uint8_t value = RAM8(0xE012 + x);
    if (value == 0) {
        uint16_t value2 = RAM16(0xE0FC + x);
        RAM16_SET(0x0000, value2);
        uint8_t a_hi1 = value2 >> 8;
        uint16_t x1 = x;
        uint16_t y1 = y;
        bool carry1 = carry;
        bool overflow1 = overflow;
        uint8_t data_bank = 0x7E;
        uint16_t direct_page = 0;
        bool xf1 = r->xf;
        for (;;) {
            uint8_t value3 = BUS8(c, (RAM8(0x0002 + direct_page) << 0x10) + RAM16(0x0000 + direct_page));
            bool m_flag;
            uint8_t a_hi2;
            uint16_t x2;
            uint16_t y2;
            bool overflow2;
            uint8_t data_bank2;
            uint16_t direct_page2;
            if (!(value3 & 0x80)) {
                m_flag = 1;
                a_hi2 = a_hi1;
                x2 = x1;
                y2 = y1;
                overflow2 = overflow1;
                data_bank2 = data_bank;
                direct_page2 = direct_page;
            } else {
                r->a = (a_hi1 << 8) | value3;
                r->x = x1;
                r->y = y1;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 0;
                r->db = data_bank;
                r->dp = direct_page;
                { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x8294, dispatch_native_visual_frame_script_control_operand_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0x8294); }
                uint16_t dp_ret = r->dp;
                uint8_t db_ret = r->db;
                bool m_ret = r->mf;
                bool x_ret = r->xf;
                uint16_t a_all = r->a;
                uint16_t x_ret2 = r->x;
                uint16_t y_ret = r->y;
                bool carry_ret = r->c;
                bool overflow_ret = r->v;
                (void)m_ret;
                xf1 = x_ret;
                if (carry_ret) {
                    a_hi1 = a_all >> 8;
                    x1 = x_ret2;
                    y1 = y_ret;
                    carry1 = carry_ret;
                    overflow1 = overflow_ret;
                    data_bank = db_ret;
                    direct_page = dp_ret;
                    continue;
                }
                m_flag = 0;
                a_hi2 = a_all >> 8;
                x2 = x_ret2;
                y2 = y_ret;
                overflow2 = overflow_ret;
                data_bank2 = db_ret;
                direct_page2 = dp_ret;
            }
            a_hi1 = a_hi2;
            x1 = x2;
            y1 = y2;
            overflow1 = overflow2;
            data_bank = data_bank2;
            direct_page = direct_page2;
            break;
        }
        uint8_t value4 = BUS8(c, (data_bank << 0x10) + 0xE060 + x1);
        bool m_flag2;
        uint8_t a_hi3;
        if (value4 != 0xC0) {
            m_flag2 = 1;
            a_hi3 = a_hi1;
        } else {
            uint16_t value5 = BUS16(c, (data_bank << 0x10) + 0xE006 + x1);
            BUS16_SET(c, (data_bank << 0x10) + 0xE11C + x1, value5);
            uint16_t value6 = BUS16(c, (data_bank << 0x10) + 0xE036 + x1);
            BUS16_SET(c, (data_bank << 0x10) + 0xE11E + x1, value6);
            BUS16_SET(c, (data_bank << 0x10) + 0xE006 + x1, 0);
            BUS16_SET(c, (data_bank << 0x10) + 0xE036 + x1, 0);
            m_flag2 = 0;
            a_hi3 = value6 >> 8;
        }
        BUS16_SET(c, (data_bank << 0x10) + 0xE0FC + x1, (uint16_t)(RAM16(0x0000 + direct_page) + 2));
        uint8_t value8 = BUS8(c, (data_bank << 0x10) + 0xE00C + x1);
        BUS8_SET(c, (data_bank << 0x10) + 0xE00C + x1, (uint8_t)(value8 + 1));
        uint16_t value9 = BUS16(c, (RAM8(0x0002 + direct_page) << 0x10) + RAM16(0x0000 + direct_page));
        RAM8(0x0000 + sp0) = (uint8_t)value9;
        BUS8_SET(c, (data_bank << 0x10) + 0xE028 + x1, (uint8_t)((uint8_t)value9 << 1));
        uint8_t value10 = RAM8(0x0000 + sp0);
        uint8_t a1;
        if ((value10 & 7) < 4) {
            a1 = value10 & 7;
        } else {
            a1 = 0;
        }
        BUS8_SET(c, (data_bank << 0x10) + 0xE012 + x1, a1);
        if (value9 >> 8 == 0xFF) {
            BUS8_SET(c, (data_bank << 0x10) + 0xE00C + x1, 0);
            BUS8_SET(c, (data_bank << 0x10) + 0xE084 + x1, 0);
            r->a = (a1 << 8) | (value9 >> 8);
            r->x = x1;
            r->y = y1;
            r->c = 0;
            r->v = overflow1;
            r->mf = 1;
            r->xf = xf1;
            r->db = data_bank;
            r->dp = direct_page;
            RETURN_RTS(c);
        }
        BUS16_SET(c, (data_bank << 0x10) + 0xE026 + x1, (((a1 << 8) | (value9 >> 8)) & 0xFF) << 1);
        BUS8_SET(c, (data_bank << 0x10) + 0xE025 + x1, 0);
        r->a = (((a1 << 8) | (value9 >> 8)) & 0xFF) << 1;
        r->x = x1;
        r->y = y1;
        r->c = 0;
        r->v = overflow1;
        r->mf = 1;
        r->xf = xf1;
        r->db = data_bank;
        r->dp = direct_page;
        RETURN_RTS(c);
    }
    RAM8(0xE012 + x) = (uint8_t)(value - 1);
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC18276, SOM_RTS, "hand", consume_native_visual_frame_script_pose_or_terminator, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 196, 95)

/* C182F9 dispatch_native_visual_frame_script_control_operand   [class A, 68 bytes, 34 instructions]
 * Source: src/rom/consume_native_visual_frame_script_pose_or_terminator.s
 * Subroutine of consume_native_visual_frame_script_pose_or_terminator, translated in place.
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void dispatch_native_visual_frame_script_control_operand(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp + 2;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    if (a != 0xFF) {
        if (a >= 0xB0) {
            if (a >= 0xF0) {
                if (a >= 0xF8) {
                    { const uint16_t sp_call = r->sp; JSL(c, 0x8337, 0xC1D48D); GUARD_JSL(c, sp_call, 0x8337); } /* read_actor_animation_velocity_or_sound_operands */
                    r->c = 1;
                    RETURN_RTS(c);
                }
                { const uint16_t sp_call = r->sp; JSL(c, 0x8331, 0xC1D52A); GUARD_JSL(c, sp_call, 0x8331); } /* read_actor_animation_packed_motion_or_effect */
                r->c = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            { const uint16_t sp_call = r->sp; JSL(c, 0x8327, 0xC1D6DC); GUARD_JSL(c, sp_call, 0x8327); } /* read_actor_command_byte_parameter_and_advance_script */
            r->c = 1;
            RETURN_RTS(c);
        }
        { const uint16_t sp_call = r->sp; JSL(c, 0x831D, 0xC1D5C0); GUARD_JSL(c, sp_call, 0x831D); } /* advance_actor_animation_low_command_pointer */
        r->c = 1;
        RETURN_RTS(c);
    }
    RAM8(0xE012 + x) = 0;
    uint8_t value = RAM8(0xE05D + x);
    if (value == 0) {
        uint8_t value2 = RAM8(0x0000 + sp0 - 1);
        uint8_t value3 = RAM8(0x0000 + sp0);
        SET_A8(r, value);
        r->y = (value3 << 8) | value2;
        r->c = 1;
        r->z = ((value3 << 8) | value2) == 0;
        r->n = ((value3 << 8) | value2) & 0x8000;
        r->sp += 2;
        c->unwound = 1;   /* the subroutine returns from its caller */
        RETURN_RTS(c);
    }
    RAM8(0xE05D + x) = 0;
    uint16_t value4 = RAM16(0xE05E + x);
    RAM16_SET(0x0000, value4);
    r->a = value4;
    r->c = 1;
    r->z = value4 == 0;
    r->n = value4 & 0x8000;
    r->mf = 0;
    RETURN_RTS(c);
}

/* C182F9 dispatch_native_visual_frame_script_control_operand_v2   [class A, 68 bytes, 34 instructions]
 * Source: src/rom/consume_native_visual_frame_script_pose_or_terminator.s
 * Subroutine of consume_native_visual_frame_script_pose_or_terminator, translated in place.
 * Entry: M=8 bit X=16 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void dispatch_native_visual_frame_script_control_operand_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp + 2;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    if (a != 0xFF) {
        if (a >= 0xB0) {
            if (a >= 0xF0) {
                if (a >= 0xF8) {
                    { const uint16_t sp_call = r->sp; JSL(c, 0x8337, 0xC1D48D); GUARD_JSL(c, sp_call, 0x8337); } /* read_actor_animation_velocity_or_sound_operands */
                    r->c = 1;
                    RETURN_RTS(c);
                }
                { const uint16_t sp_call = r->sp; JSL(c, 0x8331, 0xC1D52A); GUARD_JSL(c, sp_call, 0x8331); } /* read_actor_animation_packed_motion_or_effect */
                r->c = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            { const uint16_t sp_call = r->sp; JSL(c, 0x8327, 0xC1D6DC); GUARD_JSL(c, sp_call, 0x8327); } /* read_actor_command_byte_parameter_and_advance_script */
            r->c = 1;
            RETURN_RTS(c);
        }
        { const uint16_t sp_call = r->sp; JSL(c, 0x831D, 0xC1D5C0); GUARD_JSL(c, sp_call, 0x831D); } /* advance_actor_animation_low_command_pointer */
        r->c = 1;
        RETURN_RTS(c);
    }
    BUS8_SET(c, (db << 0x10) + 0xE012 + x, 0);
    uint8_t value = BUS8(c, (db << 0x10) + 0xE05D + x);
    if (value == 0) {
        uint8_t value2 = RAM8(0x0000 + sp0 - 1);
        uint8_t value3 = RAM8(0x0000 + sp0);
        SET_A8(r, value);
        r->y = (value3 << 8) | value2;
        r->c = 1;
        r->z = ((value3 << 8) | value2) == 0;
        r->n = ((value3 << 8) | value2) & 0x8000;
        r->sp += 2;
        c->unwound = 1;   /* the subroutine returns from its caller */
        RETURN_RTS(c);
    }
    BUS8_SET(c, (db << 0x10) + 0xE05D + x, 0);
    uint16_t value4 = BUS16(c, (db << 0x10) + 0xE05E + x);
    RAM16_SET(0x0000, value4);
    r->a = value4;
    r->c = 1;
    r->z = value4 == 0;
    r->n = value4 & 0x8000;
    r->mf = 0;
    RETURN_RTS(c);
}

/* C182F9 dispatch_native_visual_frame_script_control_operand_v3   [class A, 68 bytes, 34 instructions]
 * Source: src/rom/consume_native_visual_frame_script_pose_or_terminator.s
 * Subroutine of consume_native_visual_frame_script_pose_or_terminator, translated in place.
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void dispatch_native_visual_frame_script_control_operand_v3(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp + 2;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    if (a != 0xFF) {
        if (a >= 0xB0) {
            if (a >= 0xF0) {
                if (a >= 0xF8) {
                    { const uint16_t sp_call = r->sp; JSL(c, 0x8337, 0xC1D48D); GUARD_JSL(c, sp_call, 0x8337); } /* read_actor_animation_velocity_or_sound_operands */
                    r->c = 1;
                    RETURN_RTS(c);
                }
                { const uint16_t sp_call = r->sp; JSL(c, 0x8331, 0xC1D52A); GUARD_JSL(c, sp_call, 0x8331); } /* read_actor_animation_packed_motion_or_effect */
                r->c = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            { const uint16_t sp_call = r->sp; JSL(c, 0x8327, 0xC1D6DC); GUARD_JSL(c, sp_call, 0x8327); } /* read_actor_command_byte_parameter_and_advance_script */
            r->c = 1;
            RETURN_RTS(c);
        }
        { const uint16_t sp_call = r->sp; JSL(c, 0x831D, 0xC1D5C0); GUARD_JSL(c, sp_call, 0x831D); } /* advance_actor_animation_low_command_pointer */
        r->c = 1;
        RETURN_RTS(c);
    }
    BUS8_SET(c, (db << 0x10) + 0xE012 + x, 0);
    uint8_t value = BUS8(c, (db << 0x10) + 0xE05D + x);
    if (value == 0) {
        uint8_t value2 = RAM8(0x0000 + sp0 - 1);
        uint8_t value3 = RAM8(0x0000 + sp0);
        SET_A8(r, value);
        r->y = (value3 << 8) | value2;
        r->c = 1;
        r->z = ((value3 << 8) | value2) == 0;
        r->n = ((value3 << 8) | value2) & 0x8000;
        r->sp += 2;
        c->unwound = 1;   /* the subroutine returns from its caller */
        RETURN_RTS(c);
    }
    BUS8_SET(c, (db << 0x10) + 0xE05D + x, 0);
    uint16_t value4 = BUS16(c, (db << 0x10) + 0xE05E + x);
    RAM16_SET(0x0000 + dp, value4);
    r->a = value4;
    r->c = 1;
    r->z = value4 == 0;
    r->n = value4 & 0x8000;
    r->mf = 0;
    RETURN_RTS(c);
}
