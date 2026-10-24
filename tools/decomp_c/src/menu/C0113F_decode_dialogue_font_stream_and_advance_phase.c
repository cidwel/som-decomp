#include "som_c.h"

/* C0113F decode_dialogue_font_stream_and_advance_phase   [class A, 17 bytes, 6 instructions]
 * Source: src/rom/decode_dialogue_font_stream_and_advance_phase.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void decode_dialogue_font_stream_and_advance_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x1D04);
    RAM8(0x1D04) = value | 1;
    r->a = (a_hi << 8) | (value | 1);
    r->z = (value | 1) == 0;
    r->n = (value | 1) & 0x80;
    { const uint16_t sp_call = r->sp; JSR(c, 0x114B, 0xC016B8); GUARD_JSR(c, sp_call, 0x114B); } /* decode_dialogue_font_stream_and_all_insertion_commands */
    uint8_t db_ret = r->db;
    uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0xA15D);
    BUS8_SET(c, (db_ret << 0x10) + 0xA15D, (uint8_t)(value2 + 1));
    r->z = (uint8_t)(value2 + 1) == 0;
    r->n = (uint8_t)(value2 + 1) & 0x80;
    r->mf = 1;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0113F, SOM_RTS, "gen", decode_dialogue_font_stream_and_advance_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 17, 6)
