#include "som_c.h"

/* 7ED54C reset_title_audio_notify_parent_and_repeat_palette_transfer   [class B, 101 bytes, 42 instructions]
 * Source: src/boot/reset_title_audio_notify_parent_and_repeat_palette_transfer.s
 * Documented in docs/boot-native-title-palette-worker.md
 * Entry: M=8 bit X=16 bit DB=$7F D=$02EE.  Callers read: ABXYCZNV.
 */
static void reset_title_audio_notify_parent_and_repeat_palette_transfer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x02EE) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xEE;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    RAM16_SET(0x1E00, 0xF0);
    r->a = 0xF0;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0xD563, 0xC30000); GUARD_JSL(c, sp_call, 0xD563); } /* audio_boot_public_jump */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD566, 0x7EACD0); GUARD_JSR(c, sp_call, 0xD566); } /* current_task_parent_id */
    r->sp += 4;
    if (r->mf != 0) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    RAM8(0x0000 + sp0 - 4) = a_all2 >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)a_all2;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD56A, 0x7EB1A9); GUARD_JSR(c, sp_call, 0xD56A); } /* allocate_eight_byte_record */
    r->sp += 6;
    if (r->mf != 0) { c->fail = 3; return; }
    uint8_t value = RAM8(0x0000 + sp0 - 5);
    uint8_t value2 = RAM8(0x0000 + sp0 - 4);
    r->a = (value2 << 8) | value;
    r->z = ((value2 << 8) | value) == 0;
    r->n = ((value2 << 8) | value) & 0x8000;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD56E, 0x7EB258); GUARD_JSR(c, sp_call, 0xD56E); } /* append_pending_record */
    r->sp += 4;
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    uint16_t a_all4 = r->a;
    uint16_t y_ret2 = r->y;
    bool carry_ret4 = r->c;
    bool overflow_ret4 = r->v;
    uint8_t a_hi1 = a_all4 >> 8;
    uint16_t y1 = y_ret2;
    bool carry1 = carry_ret4;
    bool overflow1 = overflow_ret4;
    uint8_t data_bank = db_ret3;
    uint16_t direct_page = dp_ret3;
    for (;;) {
        uint16_t value3 = BUS16_RDP(c, (data_bank << 0x10) + 0x030A);
        if (value3 != 0) {
            break;
        }
        r->x = 1;
        r->y = y1;
        r->c = carry1;
        r->z = 0;
        r->n = 0;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD579, 0x7EABE7); GUARD_JSR(c, sp_call, 0xD579); } /* receive_with_supplied_delay */
        r->sp += 4;
        uint16_t dp_ret4 = r->dp;
        uint8_t db_ret4 = r->db;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all5 = r->a;
        uint16_t y_ret3 = r->y;
        bool carry_ret5 = r->c;
        bool overflow_ret5 = r->v;
        a_hi1 = a_all5 >> 8;
        y1 = y_ret3;
        carry1 = carry_ret5;
        overflow1 = overflow_ret5;
        data_bank = db_ret4;
        direct_page = dp_ret4;
        continue;
    }
    uint8_t a_hi2 = a_hi1;
    uint16_t y2 = y1;
    bool carry2 = carry1;
    bool overflow2 = overflow1;
    uint8_t data_bank2 = data_bank;
    uint16_t direct_page2 = direct_page;
    for (;;) {
        uint16_t value4 = BUS16_RDP(c, (data_bank2 << 0x10) + 0x030A);
        r->a = 2;
        r->x = value4;
        r->y = y2;
        r->c = carry2;
        r->z = 0;
        r->n = 0;
        r->v = overflow2;
        r->mf = 0;
        r->xf = 0;
        r->db = data_bank2;
        r->dp = direct_page2;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD587, 0x7E8FC7); GUARD_JSR(c, sp_call, 0xD587); } /* allocate_transfer_descriptor */
        r->sp += 4;
        uint8_t db_ret5 = r->db;
        uint16_t x_ret10 = r->x;
        uint16_t value5 = BUS16_RDP(c, (db_ret5 << 0x10) + 0x030A);
        BUS16_SET(c, (db_ret5 << 0x10) + 2 + x_ret10, (uint16_t)(value5 + 0x10));
        BUS16_SET(c, (db_ret5 << 0x10) + 5 + x_ret10, 8);
        BUS8_SET(c, (db_ret5 << 0x10) + 0x0A + x_ret10, 8);
        BUS8_SET(c, (db_ret5 << 0x10) + 4 + x_ret10, 0x7F);
        r->a = 0x7F;
        r->c = value5 + 0x10 > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = ((value5 ^ (uint16_t)(value5 + 0x10)) & ((uint16_t)(value5 + 0x10) ^ 0x10) & 0x8000) != 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD5A8, 0x7E90DA); GUARD_JSR(c, sp_call, 0xD5A8); } /* submit_transfer_or_program_hdma */
        r->sp += 4;
        r->x = 6;
        r->z = 0;
        r->n = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD5AE, 0x7EABE7); GUARD_JSR(c, sp_call, 0xD5AE); } /* receive_with_supplied_delay */
        r->sp += 4;
        uint16_t dp_ret7 = r->dp;
        uint8_t db_ret7 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all8 = r->a;
        uint16_t y_ret6 = r->y;
        bool carry_ret8 = r->c;
        bool overflow_ret8 = r->v;
        a_hi2 = a_all8 >> 8;
        y2 = y_ret6;
        carry2 = carry_ret8;
        overflow2 = overflow_ret8;
        data_bank2 = db_ret7;
        direct_page2 = dp_ret7;
    }
}
SOM_REGISTER(0x7ED54C, SOM_RTS, "gen", reset_title_audio_notify_parent_and_repeat_palette_transfer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, 1, 0, 101, 42)
