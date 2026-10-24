#include "som_c.h"

/* C27ED5 initialize_left_child_identity_and_linked_grandchild   [class B, 127 bytes, 48 instructions]
 * Source: src/rom/initialize_left_child_identity_and_linked_grandchild.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_left_child_identity_and_linked_grandchild(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7ED9, 0xC20CE0); GUARD_JSR(c, sp_call, 0x7ED9); } /* set_boss_animation_bank_low_byte_c7 */
    RAM16_SET(0x0000 + value, 1);
    RAM16_SET(0x0092 + value, 0x3000);
    r->a = 0;
    r->z = 1;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7EEB, 0xC21394); GUARD_JSR(c, sp_call, 0x7EEB); } /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x0066 + value, 0);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    RAM8(0x0046 + value) = 0;
    RAM8(0x0047 + value) = 0;
    RAM8(0x0074 + value) = 0;
    RAM8(0x0010 + value) = 1;
    RAM16_SET(0x0295, RAM16(0x00B0 + value));
    uint16_t value4 = RAM16(0x0042 + value);
    RAM16_SET(0x0297, value4);
    r->a = value4;
    r->x = 0x8138;
    r->y = 0x3901;
    r->z = 0;
    r->n = 1;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7F16, 0xC20D53); GUARD_JSR(c, sp_call, 0x7F16); } /* allocate_boss_object_pool_slot */
    uint16_t x_ret = r->x;
    RAM16_SET(0x00B0 + x_ret, RAM16(0x0287));
    RAM16_SET(0x00B2 + x_ret, RAM16(0x0295));
    RAM16_SET(0x0042 + x_ret, RAM16(0x0297));
    uint16_t value8 = RAM16(0x0287);
    uint16_t value9 = RAM16(0x00B0 + value8);
    uint16_t value11 = BUS16(c, 0xC28136 + RAM16(0x0042 + value9));
    r->a = value11 & 0xFF;
    r->x = value8;
    r->y = value9;
    r->z = value8 == 0;
    r->n = value8 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7F3B, 0xC0003F); GUARD_JSL(c, sp_call, 0x7F3B); } /* change_actor_identity_public_jump */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret2 = r->xf;
    uint16_t y_ret = r->y;
    if (x_ret2) {
        uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        uint16_t value13 = BUS16_RDP(c, (db_ret << 0x10) + 0x96 + value12);
        uint8_t a1;
        uint8_t a_hi1;
        bool zero1;
        bool negative1;
        if (value13 < 0x3C) {
            a1 = (uint8_t)value13;
            a_hi1 = value13 >> 8;
            zero1 = value13 == 0x3C;
            negative1 = (uint16_t)(value13 - 0x3C) & 0x8000;
        } else {
            r->a = 0x011A;
            r->x = value12;
            r->y = (uint8_t)y_ret;
            r->c = value13 >= 0x3C;
            r->z = 0;
            r->n = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x7F4B, 0xC21394); GUARD_JSR(c, sp_call, 0x7F4B); } /* select_boss_animation_and_reset_frame_cursor */
            uint16_t a_all5 = r->a;
            uint16_t value14 = BUS16_RDP(c, (db_ret << 0x10) + 0x94 + value12);
            BUS16_RMW_SET(c, (db_ret << 0x10) + 0x94 + value12, (uint16_t)(value14 + 1));
            BUS16_SET(c, (db_ret << 0x10) + 0x96 + value12, 0);
            a1 = (uint8_t)a_all5;
            a_hi1 = a_all5 >> 8;
            zero1 = (uint16_t)(value14 + 1) == 0;
            negative1 = (uint16_t)(value14 + 1) & 0x8000;
        }
        r->a = (a_hi1 << 8) | a1;
        r->x = value12;
        r->y = (uint8_t)y_ret;
        r->c = 0;
        r->z = zero1;
        r->n = negative1;
        r->mf = 0;
        r->xf = 1;
        RETURN_RTS(c);
    } else {
        uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        uint16_t value16 = BUS16_RDP(c, (db_ret << 0x10) + 0x96 + value15);
        uint8_t a2;
        uint8_t a_hi2;
        bool zero2;
        bool negative2;
        if (value16 < 0x3C) {
            a2 = (uint8_t)value16;
            a_hi2 = value16 >> 8;
            zero2 = value16 == 0x3C;
            negative2 = (uint16_t)(value16 - 0x3C) & 0x8000;
        } else {
            r->a = 0x011A;
            r->x = value15;
            r->c = value16 >= 0x3C;
            r->z = 0;
            r->n = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x7F4B, 0xC21394); GUARD_JSR(c, sp_call, 0x7F4B); } /* select_boss_animation_and_reset_frame_cursor */
            uint16_t a_all6 = r->a;
            uint16_t value17 = BUS16_RDP(c, (db_ret << 0x10) + 0x94 + value15);
            BUS16_RMW_SET(c, (db_ret << 0x10) + 0x94 + value15, (uint16_t)(value17 + 1));
            BUS16_SET(c, (db_ret << 0x10) + 0x96 + value15, 0);
            a2 = (uint8_t)a_all6;
            a_hi2 = a_all6 >> 8;
            zero2 = (uint16_t)(value17 + 1) == 0;
            negative2 = (uint16_t)(value17 + 1) & 0x8000;
        }
        r->a = (a_hi2 << 8) | a2;
        r->x = value15;
        r->c = 0;
        r->z = zero2;
        r->n = negative2;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC27ED5, SOM_RTS, "gen", initialize_left_child_identity_and_linked_grandchild, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 127, 48)
