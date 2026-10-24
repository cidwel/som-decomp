#include "som_c.h"

/* C250BA dispatch_native54_palette_transition_effect   [class C, 8 bytes, 4 instructions]
 * Source: src/rom/dispatch_native54_palette_transition_effect.s
 * Documented in docs/boss-native54-projectiles.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void dispatch_native54_palette_transition_effect(SomCtx *c)
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
    case 0x0000: TAIL_CALL_DYN(c, 0xC250C8, SOM_RTS); /* initialize_native54_effect_palette_ids_from_variant */
    case 0x0002: TAIL_CALL_DYN(c, 0xC250EE, SOM_RTS); /* begin_native54_first_palette_transition_or_terminate */
    case 0x0004: TAIL_CALL_DYN(c, 0xC2511F, SOM_RTS); /* begin_native54_second_palette_transition_or_terminate */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x50C2 + ((a_hi << 8) | (uint8_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC250BA, SOM_RTS, "gen", dispatch_native54_palette_transition_effect, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 8, 4)
