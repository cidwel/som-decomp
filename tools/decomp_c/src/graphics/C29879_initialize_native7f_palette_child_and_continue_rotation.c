#include "som_c.h"

/* C29879 initialize_native7f_palette_child_and_continue_rotation   [class A, 40 bytes, 15 instructions]
 * Source: src/rom/initialize_native7f_palette_child_and_continue_rotation.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void initialize_native7f_palette_child_and_continue_rotation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    RAM16_SET(0x002B + value, 0x0128);
    RAM16_SET(0x0032 + value, 0x0190);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    RAM16_SET(0x0000 + value, 1);
    r->a = 0x0172;
    r->x = value;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9895, 0xC21394); GUARD_JSR(c, sp_call, 0x9895); } /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x00B0 + value, 0);
    RAM16_SET(0x0022 + value, 0);
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x989E, 0xC298A1); GUARD_JSR(c, sp_call, 0x989E); } /* rotate_four_words_in_each_of_two_native7f_palette_groups */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29879, SOM_RTS, "gen", initialize_native7f_palette_child_and_continue_rotation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 40, 15)
