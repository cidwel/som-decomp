#include "som_c.h"
#include "som_hand_b.h"

/* C229EA step_single_boss_palette_transition_channels   [class B, 45 bytes, 19 instructions]
 * Source: src/rom/step_single_boss_palette_transition_channels.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void step_single_boss_palette_transition_channels(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x0276, RAM16(0x00A0 + value));
    RAM16_SET(0x0279, RAM16(0x00A3 + value));
    RAM16_SET(0x0266, 6);
    r->a = 6;
    r->x = value;
    JSR_CHK(c, 0x29FD, 0xC22A17); /* add_boss_palette_transition_channel_deltas */
    /* The callee returns its own X, which indexes the next load. */
    RAM16_SET(0x0279, RAM16(0x0029 + r->x));
    RAM16_SET(0x0266, 6);
    r->a = 6;
    JSR_CHK(c, 0x2A0A, 0xC22A27); /* pack_boss_palette_fixed_point_channels */
    uint16_t value5 = RAM16(0x0287);
    RAM16_SET(0x009A + value5, (uint16_t)(RAM16(0x009A + value5) - 1));
    bool zero1;
    bool negative1;
    if (RAM16(0x009A + value5) != 0) {
        zero1 = RAM16(0x009A + value5) == 0;
        negative1 = RAM16(0x009A + value5) & 0x8000;
    } else {
        RAM16_SET(OBJECT_PHASE + value5, (uint16_t)(RAM16(OBJECT_PHASE + value5) + 1));
        zero1 = RAM16(OBJECT_PHASE + value5) == 0;
        negative1 = RAM16(OBJECT_PHASE + value5) & 0x8000;
    }
    r->x = value5;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC229EA, SOM_RTS, "hand", step_single_boss_palette_transition_channels, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 45, 19)
