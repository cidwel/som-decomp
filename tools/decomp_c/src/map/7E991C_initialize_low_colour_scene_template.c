#include "som_c.h"
#include "som_hand_b.h"

/* 7E991C initialize_low_colour_scene_template   [class B, 49 bytes, 30 instructions]
 * Source: src/boot/initialize_low_colour_scene_template.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7F D=$05F1.  Callers read: nothing.
 */
static void initialize_low_colour_scene_template(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x05F1) { c->fail = 3; return; }
    i_phd(c);
    i_php(c);
    i_phb(c);
    r->db = 0;
    r->a &= 0xFF00;
    /* Arguments for copy_far_stack_arguments: length 0x40, source 7E:5FCA, destination bank 00 offset 1D00. */
    push16(c, 0x0040);
    push8(c, 0x7E);
    push16(c, 0x5FCA);
    push8(c, 0x00);
    push16(c, 0x1D00);
    r->x = 0x1D00;
    r->z = 0;
    r->n = 0;
    JSR_CHK(c, 0x993B, 0x7EC44E); /* copy_far_stack_arguments */
    r->sp += 8; /* the caller drops the arguments */
    RAM8(0x1D40) = 0;
    hand_plb(c);
    hand_plp(c);
    hand_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E991C, SOM_RTS, "hand", initialize_low_colour_scene_template, 0, 0, 12, 1, 0, 49, 30)
