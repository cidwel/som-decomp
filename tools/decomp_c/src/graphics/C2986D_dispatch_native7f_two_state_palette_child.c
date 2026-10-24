#include "som_c.h"

/* C2986D dispatch_native7f_two_state_palette_child   [class C, 8 bytes, 4 instructions]
 * Source: src/rom/dispatch_native7f_two_state_palette_child.s
 * Documented in docs/boss-native7f-setup.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void dispatch_native7f_two_state_palette_child(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x94 + x);
    r->a = (a_hi << 8) | (uint8_t)(value << 1);
    r->x = (a_hi << 8) | (uint8_t)(value << 1);
    r->c = value & 0x80;
    r->z = ((a_hi << 8) | (uint8_t)(value << 1)) == 0;
    r->n = ((a_hi << 8) | (uint8_t)(value << 1)) & 0x8000;
    switch ((a_hi << 8) | (uint8_t)(value << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC29879, SOM_RTS); /* initialize_native7f_palette_child_and_continue_rotation */
    case 0x0002: TAIL_CALL_DYN(c, 0xC2989C, SOM_RTS); /* rotate_native7f_child_palettes_without_termination */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x9875 + ((a_hi << 8) | (uint8_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC2986D, SOM_RTS, "gen", dispatch_native7f_two_state_palette_child, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 8, 4)
