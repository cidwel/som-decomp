#include "som_c.h"

/* 7E968D colour_image_task   [class B, 137 bytes, 64 instructions]
 * Source: src/boot/colour_image_task.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void colour_image_task(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    if ((uint32_t)(uint16_t)(sp0 - 8) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 8) = db;
    RAM8(0x0000 + sp0 - 9) = 0x7F;
    r->a = ((uint16_t)(sp0 - 8) >> 8 << 8) | 0x7F;
    r->c = (uint16_t)(sp0 - 3) >= 5;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 5) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 8)) & 0x8000) != 0;
    r->mf = 0;
    r->db = 0x7F;
    r->dp = (uint16_t)(sp0 - 8);
    r->sp -= 9;
    { const uint16_t sp_call = r->sp; JSR(c, 0x96A3, 0x7EACD0); GUARD_JSR(c, sp_call, 0x96A3); } /* current_task_parent_id */
    r->sp += 9;
    uint16_t a_all = r->a;
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 8), a_all);
    r->mf = 0;
    r->xf = 0;
    r->sp -= 9;
    { const uint16_t sp_call = r->sp; JSR(c, 0x96A8, 0x7E964B); GUARD_JSR(c, sp_call, 0x96A8); } /* prepare_colour_resources */
    r->sp += 9;
    uint16_t dp_ret = r->dp;
    r->a = 0xD2;
    r->x = 0xE536;
    r->z = 0;
    r->n = 0;
    r->sp -= 9;
    { const uint16_t sp_call = r->sp; JSR(c, 0x96B1, 0x7EA090); GUARD_JSR(c, sp_call, 0x96B1); } /* build_colour_binary_tree */
    r->sp += 9;
    bool x_ret3 = r->xf;
    uint16_t a_all3 = r->a;
    RAM16_SET(0x0004 + dp_ret, a_all3);
    RAM16_SET(0x0001 + dp_ret, ((((uint8_t)a_all3 << 8) | (a_all3 >> 8)) & 0xFF) + 1);
    uint16_t value = RAM16(0x0001 + dp_ret);
    if (x_ret3) {
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    } else {
        r->a = 0xD2;
        r->x = 0x80;
        r->y = (uint16_t)((uint16_t)((((((uint8_t)a_all3 << 8) | (a_all3 >> 8)) & 0xFF) + 1 << 1) + value) + 0xE536);
        r->c = (uint16_t)((((((uint8_t)a_all3 << 8) | (a_all3 >> 8)) & 0xFF) + 1 << 1) + value) + 0xE536 > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = (((uint16_t)((((((uint8_t)a_all3 << 8) | (a_all3 >> 8)) & 0xFF) + 1 << 1) + value) ^ (uint16_t)((uint16_t)((((((uint8_t)a_all3 << 8) | (a_all3 >> 8)) & 0xFF) + 1 << 1) + value) + 0xE536)) & ((uint16_t)((uint16_t)((((((uint8_t)a_all3 << 8) | (a_all3 >> 8)) & 0xFF) + 1 << 1) + value) + 0xE536) ^ 0xE536) & 0x8000) != 0;
        r->xf = 0;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0x96CC, 0x7EA12E); GUARD_JSR(c, sp_call, 0x96CC); } /* initialize_colour_decoder */
        r->sp += 9;
        r->z = 0;
        r->n = 0;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0x96D2, 0x7E83AD); GUARD_JSR(c, sp_call, 0x96D2); } /* decode_three_component_lanes */
        r->sp += 9;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0x96D5, 0x7E8621); GUARD_JSR(c, sp_call, 0x96D5); } /* initialize_colour_lookup */
        r->sp += 9;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0x96D8, 0x7E8686); GUARD_JSR(c, sp_call, 0x96D8); } /* queue_colour_sample_palette */
        r->sp += 9;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0x96DB, 0x7EB1A9); GUARD_JSR(c, sp_call, 0x96DB); } /* allocate_eight_byte_record */
        r->sp += 9;
        uint16_t dp_ret4 = r->dp;
        uint8_t db_ret4 = r->db;
        uint16_t x_ret12 = r->x;
        BUS16_SET(c, (db_ret4 << 0x10) + 3 + x_ret12, 2);
        uint16_t value2 = RAM16(0x0003 + dp_ret4);
        r->a = value2;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0x96E6, 0x7EB258); GUARD_JSR(c, sp_call, 0x96E6); } /* append_pending_record */
        r->sp += 9;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0x96E9, 0x7EB2FB); GUARD_JSR(c, sp_call, 0x96E9); } /* receive_raw_task_record */
        r->sp += 9;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0x96EC, 0x7EB1DD); GUARD_JSR(c, sp_call, 0x96EC); } /* release_eight_byte_record */
        r->sp += 9;
        uint16_t dp_ret7 = r->dp;
        bool m_ret7 = r->mf;
        uint16_t a_all11 = r->a;
        if (m_ret7) {
            r->a = (a_all11 >> 8 << 8) | RAM8(0x0003 + dp_ret7);
            r->x = 0x80;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0x96F4, 0x7EA009); GUARD_JSR(c, sp_call, 0x96F4); } /* generate_twelve_row_image */
            r->sp += 9;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0x96F7, 0x7EB1A9); GUARD_JSR(c, sp_call, 0x96F7); } /* allocate_eight_byte_record */
            r->sp += 9;
            uint16_t dp_ret8 = r->dp;
            uint8_t db_ret8 = r->db;
            uint16_t x_ret20 = r->x;
            BUS16_SET(c, (db_ret8 << 0x10) + 3 + x_ret20, 4);
            uint16_t value4 = RAM16(0x0003 + dp_ret8);
            r->a = value4;
            r->z = value4 == 0;
            r->n = value4 & 0x8000;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9702, 0x7EB258); GUARD_JSR(c, sp_call, 0x9702); } /* append_pending_record */
            r->sp += 9;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9705, 0x7EB2FB); GUARD_JSR(c, sp_call, 0x9705); } /* receive_raw_task_record */
            r->sp += 9;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9708, 0x7EB1DD); GUARD_JSR(c, sp_call, 0x9708); } /* release_eight_byte_record */
            r->sp += 9;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0x970B, 0x7E9660); GUARD_JSR(c, sp_call, 0x970B); } /* release_colour_resources */
            r->sp += 9;
            bool m_ret12 = r->mf;
            uint8_t value5 = RAM8(0x0000 + sp0 - 8);
            if (m_ret12) {
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            } else {
                uint8_t value6 = RAM8(0x0000 + sp0 - 2);
                uint8_t value7 = RAM8(0x0000 + sp0 - 1);
                uint8_t value8 = RAM8(0x0000 + sp0);
                r->a = (uint16_t)((uint16_t)(sp0 - 8) + 5);
                r->c = value6 & 0x01;
                r->z = ((value8 << 8) | value7) == 0;
                r->n = ((value8 << 8) | value7) & 0x8000;
                r->v = value6 & 0x40;
                r->mf = value6 & 0x20;
                r->xf = value6 & 0x10;
                r->db = value5;
                r->dp = (value8 << 8) | value7;
                r->i = value6 & 0x04;
                r->d = value6 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTL(c);
            }
        } else {
            r->a = RAM16(0x0003 + dp_ret7);
            r->x = 0x80;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0x96F4, 0x7EA009); GUARD_JSR(c, sp_call, 0x96F4); } /* generate_twelve_row_image */
            r->sp += 9;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0x96F7, 0x7EB1A9); GUARD_JSR(c, sp_call, 0x96F7); } /* allocate_eight_byte_record */
            r->sp += 9;
            uint16_t dp_ret13 = r->dp;
            uint8_t db_ret13 = r->db;
            uint16_t x_ret31 = r->x;
            BUS16_SET(c, (db_ret13 << 0x10) + 3 + x_ret31, 4);
            uint16_t value10 = RAM16(0x0003 + dp_ret13);
            r->a = value10;
            r->z = value10 == 0;
            r->n = value10 & 0x8000;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9702, 0x7EB258); GUARD_JSR(c, sp_call, 0x9702); } /* append_pending_record */
            r->sp += 9;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9705, 0x7EB2FB); GUARD_JSR(c, sp_call, 0x9705); } /* receive_raw_task_record */
            r->sp += 9;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9708, 0x7EB1DD); GUARD_JSR(c, sp_call, 0x9708); } /* release_eight_byte_record */
            r->sp += 9;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0x970B, 0x7E9660); GUARD_JSR(c, sp_call, 0x970B); } /* release_colour_resources */
            r->sp += 9;
            bool m_ret17 = r->mf;
            uint8_t value11 = RAM8(0x0000 + sp0 - 8);
            if (m_ret17) {
                c->fail = 3; /* operand size does not fit the register width on this path */
                return;
            } else {
                uint8_t value12 = RAM8(0x0000 + sp0 - 2);
                uint8_t value13 = RAM8(0x0000 + sp0 - 1);
                uint8_t value14 = RAM8(0x0000 + sp0);
                r->a = (uint16_t)((uint16_t)(sp0 - 8) + 5);
                r->c = value12 & 0x01;
                r->z = ((value14 << 8) | value13) == 0;
                r->n = ((value14 << 8) | value13) & 0x8000;
                r->v = value12 & 0x40;
                r->mf = value12 & 0x20;
                r->xf = value12 & 0x10;
                r->db = value11;
                r->dp = (value14 << 8) | value13;
                r->i = value12 & 0x04;
                r->d = value12 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTL(c);
            }
        }
    }
}
SOM_REGISTER(0x7E968D, SOM_RTS, "gen", colour_image_task, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 10, 1, 0, 137, 64)
