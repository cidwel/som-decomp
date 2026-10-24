#include "som_c.h"

/* C9FEAB latent_tick_scrolling_dialogue_line_delay   [class B, 90 bytes, 37 instructions]
 * Source: src/rom/latent_tick_scrolling_dialogue_line_delay.s
 * Documented in docs/source-recovery-parallel-latent-scroll-flow.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void latent_tick_scrolling_dialogue_line_delay(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint8_t value = RAM8(0xA20C);
    RAM8(0xA20C) = (uint8_t)(value - 1) & 1;
    uint8_t a1;
    bool zero2;
    bool negative2;
    if (((uint8_t)(value - 1) & 1) != 0) {
        a1 = (uint8_t)(value - 1) & 1;
        zero2 = ((uint8_t)(value - 1) & 1) == 0;
        negative2 = (uint8_t)(value - 1) & 1 & 0x80;
    } else {
        RAM8(0x0040) = (uint8_t)(RAM8(0x0040) + 1);
        RAM8(0xA171)++;
        uint8_t value3 = RAM8(0xA171);
        bool zero1;
        bool negative1;
        if ((value3 & 0x0F) != 0) {
            zero1 = (value3 & 0x0F) == 0;
            negative1 = value3 & 0x0F & 0x80;
        } else {
            RAM8(0xA161)--;
            zero1 = RAM8(0xA161) == 0;
            negative1 = RAM8(0xA161) & 0x80;
        }
        a1 = value3 & 0x0F;
        zero2 = zero1;
        negative2 = negative1;
    }
    SET_A8(r, a1);
    r->z = zero2;
    r->n = negative2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC9FEAB, SOM_RTS, "gen", latent_tick_scrolling_dialogue_line_delay, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 90, 37)
