#include "som_c.h"

/* C208F1 derive_actor_manhattan_distance_from_selected_boss   [class B, 44 bytes, 22 instructions]
 * Source: src/rom/derive_actor_manhattan_distance_from_selected_boss.s
 * Documented in docs/boss-descriptor-four.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYV.
 */
static void derive_actor_manhattan_distance_from_selected_boss(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0295, RAM16(0x0002 + x));
    RAM16_SET(0x0297, RAM16(0x0004 + x));
    uint16_t value3 = RAM16(0x0287);
    uint16_t value4 = RAM16(0x002B + value3);
    uint16_t value5 = RAM16(0x0295);
    uint8_t a1;
    uint8_t a_hi1;
    if (!((uint16_t)(value4 - value5) & 0x8000)) {
        a1 = (uint8_t)(value4 - value5);
        a_hi1 = (uint16_t)(value4 - value5) >> 8;
    } else {
        a1 = (uint8_t)(((uint16_t)(value4 - value5) ^ 0xFFFF) + 1);
        a_hi1 = (uint16_t)(((uint16_t)(value4 - value5) ^ 0xFFFF) + 1) >> 8;
    }
    RAM16_SET(0x0295, (a_hi1 << 8) | a1);
    uint16_t value6 = RAM16(0x0032 + value3);
    uint16_t value7 = RAM16(0x0297);
    uint8_t a2;
    uint8_t a_hi2;
    if (!((uint16_t)(value6 - value7) & 0x8000)) {
        a2 = (uint8_t)(value6 - value7);
        a_hi2 = (uint16_t)(value6 - value7) >> 8;
    } else {
        a2 = (uint8_t)(((uint16_t)(value6 - value7) ^ 0xFFFF) + 1);
        a_hi2 = (uint16_t)(((uint16_t)(value6 - value7) ^ 0xFFFF) + 1) >> 8;
    }
    RAM16_SET(0x0297, (a_hi2 << 8) | a2);
    uint16_t value8 = RAM16(0x0295);
    r->a = (uint16_t)(((a_hi2 << 8) | a2) + value8);
    r->x = value3;
    r->v = ((((a_hi2 << 8) | a2) ^ (uint16_t)(((a_hi2 << 8) | a2) + value8)) & (value8 ^ (uint16_t)(((a_hi2 << 8) | a2) + value8)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC208F1, SOM_RTS, "gen", derive_actor_manhattan_distance_from_selected_boss, 0, L_A | L_B | L_X | L_Y | L_V, 1, 0, 0, 44, 22)
