#include "som_c.h"

/* C23C78 dispatch_boss_terminal_bitmap_clear_lifetime   [class C, 8 bytes, 4 instructions]
 * Source: src/rom/dispatch_boss_terminal_bitmap_clear_lifetime.s
 * Documented in docs/boss-native-linked-death-effects.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_boss_terminal_bitmap_clear_lifetime(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    uint8_t value = RAM8(OBJECT_PHASE + x);
    r->a = (a_hi << 8) | (uint8_t)(value << 1);
    r->x = (a_hi << 8) | (uint8_t)(value << 1);
    r->c = value & 0x80;
    r->z = ((a_hi << 8) | (uint8_t)(value << 1)) == 0;
    r->n = ((a_hi << 8) | (uint8_t)(value << 1)) & 0x8000;
    switch ((a_hi << 8) | (uint8_t)(value << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC23C84, SOM_RTS); /* initialize_boss_terminal_bitmap_clear_then_update */
    case 0x0002: TAIL_CALL_DYN(c, 0xC23C89, SOM_RTS); /* clear_terminal_bitmap_until_timer_eighty_four */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x3C80 + ((a_hi << 8) | (uint8_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC23C78, SOM_RTS, "gen", dispatch_boss_terminal_bitmap_clear_lifetime, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 8, 4)
