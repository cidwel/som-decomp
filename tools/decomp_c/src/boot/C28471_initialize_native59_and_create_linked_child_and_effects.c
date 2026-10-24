#include "som_c.h"

/* C28471 initialize_native59_and_create_linked_child_and_effects   [class B, 183 bytes, 73 instructions]
 * Source: src/rom/initialize_native59_and_create_linked_child_and_effects.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_native59_and_create_linked_child_and_effects(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM8(0x000A + value) = 0xFF;
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    r->a = 0x010B;
    r->x = value;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8484, 0xC21394); GUARD_JSR(c, sp_call, 0x8484); } /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x0070 + value, 8);
    RAM16_SET(0x001E + value, 8);
    r->a = 8;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8493, 0xC23372); GUARD_JSR(c, sp_call, 0x8493); } /* derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction */
    RAM16_SET(0x00AD + value, 0);
    RAM16_SET(0x00B0 + value, 0);
    RAM16_SET(0x00B6 + value, 0);
    RAM16_SET(0x0062 + value, 0xFFF4);
    RAM16_SET(0x0045 + value, (uint16_t)((RAM16(0x02C7) ^ 0xFFF4) + 1));
    RAM16_SET(0x0362, RAM16(0x02C7));
    RAM16_SET(0x0295, RAM16(0x002B + value));
    uint16_t value5 = RAM16(0x0032 + value);
    RAM16_SET(0x0297, (uint16_t)(value5 - 0x10));
    RAM16_SET(0x0299, RAM16(0x0042 + value));
    RAM16_SET(0x029B, value);
    r->a = value;
    r->x = 0x8883;
    r->y = 0x290D;
    r->c = value5 >= 0x10;
    r->z = 0;
    r->n = 0;
    r->v = ((value5 ^ 0x10) & (value5 ^ (uint16_t)(value5 - 0x10)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x84CC, 0xC20D53); GUARD_JSR(c, sp_call, 0x84CC); } /* allocate_boss_object_pool_slot */
    uint16_t x_ret = r->x;
    RAM16_SET(0x002B + x_ret, RAM16(0x0295));
    RAM16_SET(0x0032 + x_ret, RAM16(0x0297));
    RAM16_SET(0x0042 + x_ret, RAM16(0x0299));
    RAM16_SET(0x00B6 + x_ret, RAM16(0x029B));
    uint16_t value11 = RAM16(0x0287);
    RAM16_SET(0x00B4 + value11, x_ret);
    r->a = x_ret;
    r->x = value11;
    r->z = value11 == 0;
    r->n = value11 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x84E9, 0xC2876C); GUARD_JSR(c, sp_call, 0x84E9); } /* dispatch_native59_variant_hp_scaling */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 0x8A91;
    r->y = 0xB821;
    r->z = 0;
    r->n = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x84F2, 0xC20D53); GUARD_JSR(c, sp_call, 0x84F2); } /* allocate_boss_object_pool_slot */
    r->x = 0x3D34;
    r->y = 0x2A20;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x84FB, 0xC20D53); GUARD_JSR(c, sp_call, 0x84FB); } /* allocate_boss_object_pool_slot */
    bool overflow_ret5 = r->v;
    uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
    r->x = value12;
    r->z = value12 == 0;
    r->n = value12 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8500, 0xC2857D); GUARD_JSR(c, sp_call, 0x8500); } /* consume_native59_status_and_enter_hurt_phase */
    uint16_t x_ret5 = r->x;
    bool carry_ret6 = r->c;
    if (carry_ret6) {
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8525, 0xC28597); GUARD_JSR(c, sp_call, 0x8525); } /* move_native59_one_step_toward_farthest_party_target */
        r->c = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value13 = BUS16_RDP(c, (db_ret << 0x10) + 0xAD + x_ret5);
    uint16_t value14 = BUS16_RDP(c, (db_ret << 0x10) + 0x2D + x_ret5);
    if (value13 < value14) {
        uint16_t value15 = BUS16_RDP(c, (db_ret << 0x10) + 0x42 + x_ret5);
        bool x_flag2;
        uint8_t a2;
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        bool zero2;
        bool negative2;
        bool overflow2;
        if (value15 != 0) {
            x_flag2 = 0;
            a2 = (uint8_t)value15;
            a_hi2 = value15 >> 8;
            x2 = x_ret5;
            y2 = 0x2A20;
            zero2 = value15 == 0;
            negative2 = value15 & 0x8000;
            overflow2 = overflow_ret5;
        } else {
            uint16_t value16 = BUS16_RDP(c, (db_ret << 0x10) + 0xB6 + x_ret5);
            bool x_flag;
            uint8_t a1;
            uint8_t a_hi1;
            uint16_t x1;
            uint16_t y1;
            bool zero1;
            bool negative1;
            bool overflow1;
            if (value16 < 1) {
                x_flag = 0;
                a1 = (uint8_t)value16;
                a_hi1 = value16 >> 8;
                x1 = x_ret5;
                y1 = 0x2A20;
                zero1 = value16 == 1;
                negative1 = (uint16_t)(value16 - 1) & 0x8000;
                overflow1 = overflow_ret5;
            } else {
                BUS16_SET(c, (db_ret << 0x10) + 0xB6 + x_ret5, 0);
                r->a = value16;
                r->c = value16 >= 1;
                r->z = value16 == 1;
                r->n = (uint16_t)(value16 - 1) & 0x8000;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8522, 0xC28528); GUARD_JSR(c, sp_call, 0x8522); } /* choose_native59_distinct_color_and_publish_status_palette_sound */
                bool x_ret7 = r->xf;
                uint16_t a_all9 = r->a;
                uint16_t x_ret8 = r->x;
                uint16_t y_ret3 = r->y;
                bool zero_ret9 = r->z;
                bool negative_ret9 = r->n;
                bool overflow_ret7 = r->v;
                x_flag = x_ret7;
                a1 = (uint8_t)a_all9;
                a_hi1 = a_all9 >> 8;
                x1 = x_ret8;
                y1 = y_ret3;
                zero1 = zero_ret9;
                negative1 = negative_ret9;
                overflow1 = overflow_ret7;
            }
            x_flag2 = x_flag;
            a2 = a1;
            a_hi2 = a_hi1;
            x2 = x1;
            y2 = y1;
            zero2 = zero1;
            negative2 = negative1;
            overflow2 = overflow1;
        }
        r->a = (a_hi2 << 8) | a2;
        r->x = x2;
        r->y = y2;
        r->z = zero2;
        r->n = negative2;
        r->v = overflow2;
        r->mf = 0;
        r->xf = x_flag2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8525, 0xC28597); GUARD_JSR(c, sp_call, 0x8525); } /* move_native59_one_step_toward_farthest_party_target */
        r->c = 0;
        r->mf = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    uint16_t value17 = BUS16_RDP(c, (db_ret << 0x10) + 0x94 + x_ret5);
    BUS16_RMW_SET(c, (db_ret << 0x10) + 0x94 + x_ret5, (uint16_t)(value17 + 1));
    r->a = value13;
    r->c = 0;
    r->z = (uint16_t)(value17 + 1) == 0;
    r->n = (uint16_t)(value17 + 1) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28471, SOM_RTS, "gen", initialize_native59_and_create_linked_child_and_effects, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 183, 73)
