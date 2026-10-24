#include "som_c.h"
#include "som_hand_b.h"

/* 7E964B prepare_colour_resources   [class B, 21 bytes, 11 instructions]
 * Source: src/boot/prepare_colour_resources.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: CV.
 */
static void prepare_colour_resources(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    const uint16_t sp0 = r->sp;

    /* PHD, PHP, REP #$30, SEP #$20: D and the flags stay on the stack for the epilogue. */
    RAM8(sp0) = r->dp >> 8;
    RAM8(sp0 - 1) = (uint8_t)r->dp;
    RAM8(sp0 - 2) = hand_p_byte(r);
    r->sp -= 3;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9653, 0x7EBE5B); GUARD_JSR(c, sp_call, 0x9653); }                /* prepare_colour_scene */
    { const uint16_t sp_call = r->sp; JSR(c, 0x9656, 0x7EA061); GUARD_JSR(c, sp_call, 0x9656); }                /* allocate_colour_tree */
    { const uint16_t sp_call = r->sp; JSR(c, 0x9659, 0x7E833E); GUARD_JSR(c, sp_call, 0x9659); }                /* allocate_auxiliary_graphics_buffers */
    { const uint16_t sp_call = r->sp; JSR(c, 0x965C, 0x7E991C); GUARD_JSR(c, sp_call, 0x965C); }                /* initialize_low_colour_scene_template */
    r->sp += 3;

    som_pull_p(c, sp0 - 2);                      /* PLP */
    r->dp = (RAM8(sp0) << 8) | RAM8(sp0 - 1);    /* PLD */
    hand_nz16(r, r->dp);
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E964B, SOM_RTS, "hand", prepare_colour_resources, 0, L_C | L_V, 3, 1, 0, 21, 11)
