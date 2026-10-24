#include "som_c.h"

/* C00F2C restore_suspended_dialogue_context_and_script_cursor   [class B, 45 bytes, 19 instructions]
 * Source: src/rom/restore_suspended_dialogue_context_and_script_cursor.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void restore_suspended_dialogue_context_and_script_cursor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x0000 + sp0) = 0x7E;
    RAM8(0x0000 + sp0 - 1) = 0x7E;
    uint8_t value = RAM8(0xA162);
    uint8_t data_bank;
    if (value != 2) {
        data_bank = 0x7E;
    } else {
        uint8_t value2 = RAM8(0xA188);
        RAM8(0xA162) = value2;
        r->a = (a_hi << 8) | value2;
        r->c = value >= 2;
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0F41, 0xC00D8B); GUARD_JSR(c, sp_call, 0x0F41); } /* select_dialogue_window_geometry_from_state */
        r->sp += 1;
        uint8_t db_ret = r->db;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0F44, 0xC0193F); GUARD_JSR(c, sp_call, 0x0F44); } /* initialize_dialogue_window_cursor_and_render_state */
        r->sp += 1;
        uint16_t value3 = BUS16_RDP(c, (db_ret << 0x10) + 0xA1D1);
        RAM16_SET(0x1D01, value3);
        uint8_t value4 = BUS8_RDP(c, (db_ret << 0x10) + 0xA1D3);
        RAM8(0x1D03) = value4;
        data_bank = db_ret;
    }
    uint8_t value5 = RAM8(0x0000 + sp0);
    r->mf = 1;
    r->xf = 0;
    r->db = value5;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00F2C, SOM_RTS, "gen", restore_suspended_dialogue_context_and_script_cursor, 0, 0, 2, 1, 0, 45, 19)
