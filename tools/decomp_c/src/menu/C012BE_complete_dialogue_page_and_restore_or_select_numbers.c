#include "som_c.h"
#include "som_hand_b.h"

/* C012BE complete_dialogue_page_and_restore_or_select_numbers   [class B, 65 bytes, 23 instructions]
 * Source: src/rom/complete_dialogue_page_and_restore_or_select_numbers.s
 * Documented in docs/event-dialogue-line-completion.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void complete_dialogue_page_and_restore_or_select_numbers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;

    RAM8(0xA15F) = 0;
    RAM8(0xA15E) = 0;
    RAM8(0x1D00) |= 0x50;                        /* status bits $40 and $10 */
    uint8_t status = RAM8(0x1D00);
    hand_lda8(r, status & 0x80);
    if (status & 0x80) {
        status &= 0x3F;
        RAM8(0x1D00) = status;
        hand_lda8(r, 0x5A);
        RAM8(0xA170) = 0x5A;
        RAM8(0xA160) = 0;
    } else {
        RAM8(0xA170) = 0;
        { const uint16_t sp_call = r->sp; const uint8_t db_call = r->db; JSR(c, 0x12EF, 0xC00F2C); GUARD_JSR_DB(c, sp_call, 0x12EF, db_call); }            /* restore_suspended_dialogue_context_and_script_cursor */
        if (!r->mf) { c->fail = 3; return; }     /* the 8-bit CMP below would be decoded wrongly */
    }

    uint8_t kind = RAM8(0x1D05);
    hand_lda8(r, kind);
    hand_cmp8(r, kind, 7);
    if (kind == 7) {
        { const uint16_t sp_call = r->sp; const uint8_t db_call = r->db; JSR(c, 0x12FA, 0xC01322); GUARD_JSR_DB(c, sp_call, 0x12FA, db_call); }            /* mark_or_publish_dialogue_control_object */
    }
    RAM8(0xA15D) = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC012BE, SOM_RTS, "hand", complete_dialogue_page_and_restore_or_select_numbers, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 65, 23)
