#include "som_c.h"

/* C1F10E event_decode_individual_map_piece_and_redraw   [class B, 50 bytes, 26 instructions]
 * Source: src/rom/event_decode_individual_map_piece_and_redraw.s
 * Entry: M=8 bit X=8 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void event_decode_individual_map_piece_and_redraw(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    const uint16_t dp = r->dp;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 5));
    BUS8_SET(c, dp, value);
    uint8_t value2 = BUS8_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 0xD3)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 0xD1)) + 2, BUS8_RDP(c, (uint16_t)(dp + 0xD3)));
    BUS8_SET(c, (uint16_t)(dp + 1), value2);
    uint16_t value3 = BUS16_RDL(c, (BUS8_RDP(c, (uint16_t)(dp + 0xD3)) << 0x10) + BUS16_RDP(c, (uint16_t)(dp + 0xD1)) + 3, BUS8_RDP(c, (uint16_t)(dp + 0xD3)));
    BUS16_SET(c, (uint16_t)(dp + 2), value3);
    uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp + 0xD1));
    BUS16_SET(c, (uint16_t)(dp + 0xD1), (uint16_t)(value4 + 5));
    uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp + 2));
    uint8_t a1;
    uint8_t a_hi1;
    if (!(value5 >> 8 & 0x80)) {
        a1 = (uint8_t)((((uint8_t)value5 << 8) | (uint8_t)(value5 >> 8 << 1)) & 0x7FFF);
        a_hi1 = ((((uint8_t)value5 << 8) | (uint8_t)(value5 >> 8 << 1)) & 0x7FFF) >> 8;
    } else {
        a1 = (uint8_t)(((((uint8_t)value5 << 8) | (uint8_t)(value5 >> 8 << 1)) & 0x7FFF) | 0x8000);
        a_hi1 = (((((uint8_t)value5 << 8) | (uint8_t)(value5 >> 8 << 1)) & 0x7FFF) | 0x8000) >> 8;
    }
    BUS16_SET(c, (uint16_t)(dp + 0x12), ((a_hi1 << 8) | a1) >> 1);
    r->a = ((a_hi1 << 8) | a1) >> 1;
    r->y = 3;
    r->c = 0;
    r->z = ((a_hi1 << 8) | a1) >> 1 == 0;
    r->n = ((a_hi1 << 8) | a1) >> 1 & 0x8000;
    r->v = ((value4 ^ (uint16_t)(value4 + 5)) & ((uint16_t)(value4 + 5) ^ 5) & 0x8000) != 0;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF13E, 0x00CAFF); GUARD_JSL(c, sp_call, 0xF13E); } /* reload_map_pieces_preserving_low_scratch_and_redraw */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F10E, SOM_RTS, "gen", event_decode_individual_map_piece_and_redraw, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 50, 26)
