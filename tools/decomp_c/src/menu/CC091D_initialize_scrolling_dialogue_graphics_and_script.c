#include "som_c.h"

/* CC091D initialize_scrolling_dialogue_graphics_and_script   [class B, 63 bytes, 22 instructions]
 * Source: src/rom/initialize_scrolling_dialogue_graphics_and_script.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void initialize_scrolling_dialogue_graphics_and_script(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->a = 0x7EC7;
    r->x = 0xC1C0;
    r->y = 0x9400;
    r->z = 0;
    r->n = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x092B, 0xC10014); GUARD_JSL(c, sp_call, 0x092B); } /* decompress_block_long_call_wrapper */
    RAM16_SET(0x1D06, 0x4800);
    RAM16_SET(0x1D08, 0x0400);
    RAM16_SET(0x1D1A, 0x0800);
    uint8_t value = RAM8(0x1D04);
    RAM8(0x1D04) = value | 7;
    RAM16_SET(0xA18F, 2);
    r->a = (8 << 8) | (value | 7);
    r->x = 2;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0957, 0xCC0B00); GUARD_JSR(c, sp_call, 0x0957); } /* copy_scrolling_dialogue_script_until_terminator */
    uint8_t db_ret = r->db;
    uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0xA161);
    BUS8_SET(c, (db_ret << 0x10) + 0xA161, (uint8_t)(value2 + 1));
    r->z = (uint8_t)(value2 + 1) == 0;
    r->n = (uint8_t)(value2 + 1) & 0x80;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xCC091D, SOM_RTS, "gen", initialize_scrolling_dialogue_graphics_and_script, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 63, 22)
