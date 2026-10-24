#include "som_c.h"

/* 7E8D1A run_native_title_normal_rows_and_complete_buffer_notice   [class B, 134 bytes, 63 instructions]
 * Source: src/boot/run_native_title_normal_rows_and_complete_buffer_notice.s
 * Documented in docs/source-recovery-parallel-title-workers.md
 * Entry: M=8 bit X=16 bit DB=$7F D=any.  Callers read: ABXYCZNV.
 */
static void run_native_title_normal_rows_and_complete_buffer_notice(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 8) + 0x1 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x10063) = 0;
    r->a = (uint16_t)(sp0 - 8);
    r->c = (uint16_t)(sp0 - 3) >= 5;
    r->z = (uint16_t)(sp0 - 8) == 0;
    r->n = (uint16_t)(sp0 - 8) & 0x8000;
    r->v = (((uint16_t)(sp0 - 3) ^ 5) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 8)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 8);
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8D2C, 0x7EACD0); GUARD_JSR(c, sp_call, 0x8D2C); } /* current_task_parent_id */
    r->sp += 8;
    uint16_t a_all = r->a;
    RAM8(0x0001 + (uint16_t)(sp0 - 8)) = (uint8_t)a_all;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8D31, 0x7EB1A9); GUARD_JSR(c, sp_call, 0x8D31); } /* allocate_eight_byte_record */
    r->sp += 8;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    uint16_t a_all2 = r->a;
    uint16_t x_ret3 = r->x;
    BUS8_SET(c, (db_ret << 0x10) + 3 + x_ret3, 1);
    uint8_t value = RAM8(0x0001 + dp_ret);
    r->a = (a_all2 >> 8 << 8) | value;
    r->z = value == 0;
    r->n = value & 0x80;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8D3B, 0x7EB258); GUARD_JSR(c, sp_call, 0x8D3B); } /* append_pending_record */
    r->sp += 8;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8D3E, 0x7EB2FB); GUARD_JSR(c, sp_call, 0x8D3E); } /* receive_raw_task_record */
    r->sp += 8;
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    uint16_t x_ret7 = r->x;
    uint16_t value2 = BUS16_RDP(c, (db_ret3 << 0x10) + 4 + x_ret7);
    RAM16_SET(0x0002 + dp_ret3, value2);
    r->a = value2;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    r->mf = 0;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8D48, 0x7EB1DD); GUARD_JSR(c, sp_call, 0x8D48); } /* release_eight_byte_record */
    r->sp += 8;
    uint16_t dp_ret4 = r->dp;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8D4B, 0x7E88E7); GUARD_JSR(c, sp_call, 0x8D4B); } /* prepare_title_buffer_display */
    r->sp += 8;
    uint8_t db_ret5 = r->db;
    uint16_t a_all6 = r->a;
    uint16_t y_ret3 = r->y;
    bool carry_ret6 = r->c;
    bool overflow_ret6 = r->v;
    RAM16_SET(0x0004 + dp_ret4, 0);
    uint8_t a_hi1 = a_all6 >> 8;
    uint16_t y1 = y_ret3;
    bool carry1 = carry_ret6;
    bool overflow1 = overflow_ret6;
    uint16_t direct_page = dp_ret4;
    for (;;) {
        uint16_t value3 = RAM16(0x0002 + direct_page);
        r->a = 0x0200;
        r->x = (uint16_t)(value3 + 0x04C0);
        r->y = (uint16_t)(value3 + 0x0480);
        r->c = value3 + 0x04C0 > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = ((value3 ^ (uint16_t)(value3 + 0x04C0)) & ((uint16_t)(value3 + 0x04C0) ^ 0x04C0) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        r->db = db_ret5;
        r->dp = direct_page;
        r->sp -= 8;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8D64, 0x7EC3BF); GUARD_JSR(c, sp_call, 0x8D64); } /* copy_native_same_bank_memory_through_stack_generated_mvn */
        r->sp += 8;
        uint16_t dp_ret5 = r->dp;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t value4 = RAM16(0x0002 + dp_ret5);
        r->x = value4;
        r->z = value4 == 0;
        r->n = value4 & 0x8000;
        r->sp -= 8;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8D69, 0x7EC870); GUARD_JSR(c, sp_call, 0x8D69); } /* queue_registered_vram_buffer */
        r->sp += 8;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t value5 = RAM16(0x0002 + dp_ret5);
        uint16_t value6 = RAM16(0x0004 + dp_ret5);
        r->x = value6;
        r->y = (uint16_t)(value5 + 0x0680);
        r->c = value5 + 0x0680 > 0xFFFF;
        r->z = value6 == 0;
        r->n = value6 & 0x8000;
        r->v = ((value5 ^ (uint16_t)(value5 + 0x0680)) & ((uint16_t)(value5 + 0x0680) ^ 0x0680) & 0x8000) != 0;
        r->sp -= 8;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8D75, 0x7E8820); GUARD_JSR(c, sp_call, 0x8D75); } /* expand_title_text_row */
        r->sp += 8;
        uint16_t dp_ret6 = r->dp;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret12 = r->x;
        RAM16_SET(0x0004 + dp_ret6, x_ret12);
        uint16_t value7 = RAM16(0x0002 + dp_ret6);
        r->x = value7;
        r->z = value7 == 0;
        r->n = value7 & 0x8000;
        r->sp -= 8;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8D7C, 0x7E8BA5); GUARD_JSR(c, sp_call, 0x8D7C); } /* animate_title_text_row */
        r->sp += 8;
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t y_ret7 = r->y;
        bool carry_ret10 = r->c;
        bool overflow_ret10 = r->v;
        uint16_t value8 = RAM16(0x0004 + dp_ret6);
        a_hi1 = value8 >> 8;
        y1 = y_ret7;
        carry1 = carry_ret10;
        overflow1 = overflow_ret10;
        direct_page = dp_ret6;
        if (!(value8 != 0)) break;
    }
    uint16_t value9 = RAM16(0x0002 + direct_page);
    r->x = value9;
    r->y = y1;
    r->c = carry1;
    r->z = value9 == 0;
    r->n = value9 & 0x8000;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = db_ret5;
    r->dp = direct_page;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8D85, 0x7EC870); GUARD_JSR(c, sp_call, 0x8D85); } /* queue_registered_vram_buffer */
    r->sp += 8;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8D88, 0x7E8CA6); GUARD_JSR(c, sp_call, 0x8D88); } /* cleanup_title_buffer_display */
    r->sp += 8;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8D8B, 0x7EB1A9); GUARD_JSR(c, sp_call, 0x8D8B); } /* allocate_eight_byte_record */
    r->sp += 8;
    uint16_t dp_ret8 = r->dp;
    uint8_t db_ret7 = r->db;
    uint16_t x_ret19 = r->x;
    BUS16_SET(c, (db_ret7 << 0x10) + 3 + x_ret19, 2);
    uint16_t value10 = RAM16(0x0001 + dp_ret8);
    r->a = value10;
    r->z = value10 == 0;
    r->n = value10 & 0x8000;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8D96, 0x7EB258); GUARD_JSR(c, sp_call, 0x8D96); } /* append_pending_record */
    r->sp += 8;
    uint8_t value11 = RAM8(0x0000 + sp0 - 2);
    uint8_t value12 = RAM8(0x0000 + sp0 - 1);
    uint8_t value13 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)((uint16_t)(sp0 - 8) + 5);
    r->c = value11 & 0x01;
    r->z = ((value13 << 8) | value12) == 0;
    r->n = ((value13 << 8) | value12) & 0x8000;
    r->v = value11 & 0x40;
    r->mf = value11 & 0x20;
    r->xf = value11 & 0x10;
    r->dp = (value13 << 8) | value12;
    r->i = value11 & 0x04;
    r->d = value11 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0x7E8D1A, SOM_RTL, "gen", run_native_title_normal_rows_and_complete_buffer_notice, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 8, 1, 0, 134, 63)
