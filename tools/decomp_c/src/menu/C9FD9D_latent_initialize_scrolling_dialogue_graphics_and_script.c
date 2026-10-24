#include "som_c.h"

/* C9FD9D latent_initialize_scrolling_dialogue_graphics_and_script   [class B, 63 bytes, 22 instructions]
 * Source: src/rom/latent_initialize_scrolling_dialogue_graphics_and_script.s
 * Documented in docs/source-recovery-parallel-latent-scroll-flow.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void latent_initialize_scrolling_dialogue_graphics_and_script(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    r->a = 0x7EC7;
    r->x = 0xC1C0;
    r->y = 0x9400;
    r->z = 0;
    r->n = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xFDAB, 0xC10014); GUARD_JSL(c, sp_call, 0xFDAB); } /* decompress_block_long_call_wrapper */
    RAM16_SET(0x1D06, 0x4800);
    RAM16_SET(0x1D08, 0x0400);
    RAM16_SET(0x1D1A, 0x0800);
    RAM8(0x1D04) |= 7;
    RAM16_SET(0xA18F, 2);
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xFDD7, 0xC9FF80); GUARD_JSR(c, sp_call, 0xFDD7); } /* latent_copy_scrolling_dialogue_script_until_terminator */
    uint8_t db_ret = r->db;
    uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0xA161);
    BUS8_SET(c, (db_ret << 0x10) + 0xA161, (uint8_t)(value2 + 1));
    r->z = (uint8_t)(value2 + 1) == 0;
    r->n = (uint8_t)(value2 + 1) & 0x80;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC9FD9D, SOM_RTS, "gen", latent_initialize_scrolling_dialogue_graphics_and_script, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 63, 22)
