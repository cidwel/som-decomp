#include "som_c.h"

/* C186D1 select_actor_cast_presentation_record   [class B, 54 bytes, 31 instructions]
 * Source: src/rom/select_actor_cast_presentation_record.s
 * Documented in docs/actor-cast-publication.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void select_actor_cast_presentation_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xE111 + x);
    uint8_t value2 = RAM8(0xE170 + x);
    RAM16_SET(0x0018, (((value << 8) | value2) & 0x7F) << 1 << 1 << 1 << 1 << 1 << 1);
    uint8_t a1;
    uint8_t a_hi1;
    bool carry1;
    bool overflow1;
    if (value != 0x88) {
        a1 = (((((uint8_t)((value << 8) | value2) << 8) | value) & 0x0E) << 1 << 1) + 8;
        a_hi1 = 0;
        carry1 = (((((uint8_t)((value << 8) | value2) << 8) | value) & 0x0E) << 1 << 1) + 8 > 0xFFFF;
        overflow1 = (((((((uint8_t)((value << 8) | value2) << 8) | value) & 0x0E) << 1 << 1) ^ (((((uint8_t)((value << 8) | value2) << 8) | value) & 0x0E) << 1 << 1) + 8) & ((((((uint8_t)((value << 8) | value2) << 8) | value) & 0x0E) << 1 << 1) + 8 ^ 8) & 0x8000) != 0;
    } else {
        a1 = 0x30;
        a_hi1 = (uint8_t)((value << 8) | value2);
        carry1 = value >= 0x88;
        overflow1 = overflow;
    }
    r->a = (((a_hi1 << 8) | a1) & 0x3F) | RAM16(0x0018);
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC186D1, SOM_RTS, "gen", select_actor_cast_presentation_record, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 0, 0, 54, 31)
