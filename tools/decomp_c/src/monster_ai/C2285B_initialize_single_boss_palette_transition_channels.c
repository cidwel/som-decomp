#include "som_c.h"
#include "som_hand_b.h"

/* C2285B initialize_single_boss_palette_transition_channels   [class B, 107 bytes, 50 instructions]
 * Source: src/rom/initialize_single_boss_palette_transition_channels.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void initialize_single_boss_palette_transition_channels(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    uint16_t x = RAM16(CURRENT_OBJECT_DP0 + dp);
    RAM16_SET(OBJECT_PHASE + x, (uint16_t)(RAM16(OBJECT_PHASE + x) + 1));
    uint16_t source = RAM16(0x009E + x);
    uint16_t row = (uint16_t)((source & 0x0F00) >> 8);
    row = (uint16_t)(row << 1); /* XBA, ASL: byte offset of the palette row */
    RAM16_SET(0x0068 + dp, row);
    source = RAM16(0x009E + x);
    uint16_t dest = (uint16_t)((((source & 0x000F) << 8) >> 3) + 0x0600 + row); /* XBA, LSR x3, ADC #$0600, ADC $68 */
    RAM16_SET(0x0076 + dp, dest);
    RAM16_SET(0x0029 + x, dest);
    uint16_t slot = (uint16_t)(RAM16(CURRENT_OBJECT_DP0 + dp) + 0x0030);
    RAM16_SET(0x0079 + dp, slot);
    RAM16_SET(0x00A0 + x, slot);
    RAM16_SET(0x0066 + dp, 0x0002);
    r->a = 0x0002;
    r->x = x;
    JSR_CHK(c, 0x2891, 0xC228C6); /* unpack_boss_palette_colors_to_fixed_point_channels */

    x = RAM16(CURRENT_OBJECT_DP0 + dp);
    uint16_t table = (uint16_t)(RAM16(0x009C + x) << 1);
    r->a = 1; /* MVN copies A+1 = 2 bytes: one colour of the source palette */
    r->x = (uint16_t)(RAM16(0x0068 + dp) + BUS16(c, 0xD0BB24 + table));
    r->y = 0x0295;
    r->mf = 0;
    r->xf = 0;
    i_mvn(c, 0xC2, 0x7E);
    x = RAM16(CURRENT_OBJECT_DP0 + dp);
    RAM16_SET(0x0076 + dp, 0x0295);
    slot = (uint16_t)(RAM16(CURRENT_OBJECT_DP0 + dp) + 0x0036);
    RAM16_SET(0x0079 + dp, slot);
    RAM16_SET(0x00A3 + x, slot);
    RAM16_SET(0x0066 + dp, 0x0002);
    r->a = 0x0002;
    r->x = x;
    r->v = (((slot - 0x0036) ^ slot) & (slot ^ 0x0036) & 0x8000) != 0; /* ADC #$0036; CLC and the callee leave V alone */
    JSR_CHK(c, 0x28C3, 0xC228C6); /* unpack_boss_palette_colors_to_fixed_point_channels */
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2285B, SOM_RTS, "hand", initialize_single_boss_palette_transition_channels, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 107, 50)
