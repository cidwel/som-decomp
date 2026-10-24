#include "som_c.h"

/* 7E994D release_low_colour_scene_template   [class A, 15 bytes, 12 instructions]
 * Source: src/boot/release_low_colour_scene_template.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7F D=$0500.  Callers read: BYCZNV.
 */
static void release_low_colour_scene_template(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    const uint16_t sp0 = r->sp;

    /* PHD, PHP, REP #$30, SEP #$20, PHB, LDA #$00, PHA, PLB, PLB, PLP, PLD: every register comes back, D sets Z and N */
    RAM8(sp0) = r->dp >> 8;
    RAM8((uint16_t)(sp0 - 1)) = (uint8_t)r->dp;
    RAM8((uint16_t)(sp0 - 2)) = hand_p_byte(r);
    RAM8((uint16_t)(sp0 - 3)) = r->db;
    RAM8((uint16_t)(sp0 - 4)) = 0x00;
    r->sp = sp0;
    SET_A8(r, 0x00);
    r->z = r->dp == 0;
    r->n = (r->dp & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E994D, SOM_RTS, "hand", release_low_colour_scene_template, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 0, 1, 0, 15, 12)
