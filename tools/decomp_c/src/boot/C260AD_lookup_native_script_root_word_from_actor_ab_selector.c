#include "som_c.h"

/* C260AD lookup_native_script_root_word_from_actor_ab_selector   [class A, 10 bytes, 5 instructions]
 * Source: src/rom/lookup_native_script_root_word_from_actor_ab_selector.s
 * Documented in docs/boss-unused-native-leaves.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void lookup_native_script_root_word_from_actor_ab_selector(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0xAB + x);
    uint8_t value2 = BUS8(c, 0xDCE292 + ((a_hi << 8) | (uint8_t)(value << 1)));
    SET_A8(r, value2);
    r->x = (a_hi << 8) | (uint8_t)(value << 1);
    r->c = value & 0x80;
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC260AD, SOM_RTS, "gen", lookup_native_script_root_word_from_actor_ab_selector, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 10, 5)
