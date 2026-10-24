#include "som_c.h"
#include "som_hand_b.h"

/* C227F2 initialize_full_boss_palette_transition_channels   [class B, 105 bytes, 51 instructions]
 * Source: src/rom/initialize_full_boss_palette_transition_channels.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_full_boss_palette_transition_channels(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t x = RAM16(0x0287);
    RAM16_SET(OBJECT_PHASE + x, 1);
    uint16_t swapped = RAM16(0x009E + x);
    swapped = (uint16_t)((swapped << 8) | (swapped >> 8)); /* XBA */
    uint16_t dest = (uint16_t)((swapped >> 3) + 0x0600);
    RAM16_SET(0x0276, dest);
    RAM16_SET(0x0029 + x, dest);
    uint16_t slot = (uint16_t)(RAM16(0x0287) + 0x0100);
    RAM16_SET(0x0279, slot);
    RAM16_SET(0x00A0 + x, slot);
    RAM16_SET(0x0266, 0x0020);
    r->a = 0x0020;
    r->x = x;
    JSR_CHK(c, 0x281C, 0xC228C6); /* unpack_boss_palette_colors_to_fixed_point_channels */

    /* Copy the 16 source colours of the table entry into the workspace at $0295+X. */
    x = RAM16(0x0287);
    RAM16_SET(0x0277, 0xC200);
    uint16_t table = (uint16_t)(RAM16(0x009C + x) << 1);
    uint16_t pointer = BUS16(c, 0xD0BB24 + table);
    RAM16_SET(0x0276, pointer);
    x = RAM16(0x02C5);
    uint16_t y = x;
    uint16_t colour;
    do {
        colour = BUS16(c, (uint32_t)((RAM8(0x0278) << 16) + RAM16(0x0276) + y));
        BUS16_SET(c, (uint16_t)(0x0295 + x), colour); /* dp,X: bank 0, wraps at 16 bits, may leave WRAM */
        y = (uint16_t)(y + 2);
        x = (uint16_t)(x + 2);
    } while (x < 0x0020);
    x = RAM16(0x0287);
    RAM16_SET(0x0276, 0x0295);
    r->c = 0;
    slot = hand_adc16(r, RAM16(0x0287), 0x0160); /* sets V for the routine's exit state */
    RAM16_SET(0x0279, slot);
    RAM16_SET(0x00A3 + x, slot);
    RAM16_SET(0x0266, 0x0020);
    r->a = 0x0020;
    r->x = x;
    r->y = y;
    JSR_CHK(c, 0x2858, 0xC228C6); /* unpack_boss_palette_colors_to_fixed_point_channels */
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC227F2, SOM_RTS, "hand", initialize_full_boss_palette_transition_channels, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 105, 51)
