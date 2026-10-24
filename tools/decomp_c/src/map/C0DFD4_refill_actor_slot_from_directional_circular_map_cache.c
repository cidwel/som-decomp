#include "som_c.h"

/* C0DFD4 refill_actor_slot_from_directional_circular_map_cache   [class B, 56 bytes, 32 instructions]
 * Source: src/rom/refill_actor_slot_from_directional_circular_map_cache.s
 * Documented in docs/map-object-refill-cpu.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void refill_actor_slot_from_directional_circular_map_cache(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0x00FF);
    uint8_t value2 = RAM8(0x0052);
    if ((value | value2) != 0) {
        SET_A8(r, value | value2);
        RETURN_RTS(c);
    }
    uint8_t value3 = RAM8(0x00E8);
    if ((value3 & 4) != 0) {
        SET_A8(r, value3 & 4);
        RETURN_RTS(c);
    }
    uint8_t value4 = RAM8(0x00BC);
    if (value4 != 0) {
        JSR(c, 0xDFE9, 0xC0E058); /* select_directional_map_object_load_window */
        uint16_t a_all = r->a;
        uint8_t value5 = RAM8(0x00BC);
        RAM8(0x000C) = (value5 >> 3) + 1;
        uint8_t value6 = RAM8(0x00BD);
        uint8_t a1;
        bool overflow1;
        if ((uint8_t)((value5 >> 3) + 1 + value6) < value5) {
            a1 = (uint8_t)((value5 >> 3) + 1 + value6);
            overflow1 = (((value5 >> 3) + 1 ^ (uint8_t)((value5 >> 3) + 1 + value6)) & (value6 ^ (uint8_t)((value5 >> 3) + 1 + value6)) & 0x80) != 0;
        } else {
            a1 = (uint8_t)((uint8_t)((value5 >> 3) + 1 + value6) - value5 - ((uint8_t)((value5 >> 3) + 1 + value6) >= value5 ^ 1));
            overflow1 = (((uint8_t)((value5 >> 3) + 1 + value6) ^ value5) & ((uint8_t)((value5 >> 3) + 1 + value6) ^ (uint8_t)((uint8_t)((value5 >> 3) + 1 + value6) - value5 - ((uint8_t)((value5 >> 3) + 1 + value6) >= value5 ^ 1))) & 0x80) != 0;
        }
        RAM8(0x00BD) = a1;
        r->a = (((a_all >> 8 << 8) | a1) & 0xFF) << 1 << 1 << 1 << 1;
        r->y = (((a_all >> 8 << 8) | a1) & 0xFF) << 1 << 1 << 1 << 1;
        r->c = (((a_all >> 8 << 8) | a1) & 0xFF) << 1 << 1 << 1 & 0x8000;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        TAIL_CALL(c, 0xC0DDBE, SOM_RTS); /* scan_map_object_cache_for_creation */
    }
    SET_A8(r, value4);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0DFD4, SOM_RTS, "gen", refill_actor_slot_from_directional_circular_map_cache, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 56, 32)
