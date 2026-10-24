#include "som_c.h"

/* C28295 dispatch_right_attack_by_variant_and_order   [class C, 15 bytes, 9 instructions]
 * Source: src/rom/dispatch_right_attack_by_variant_and_order.s
 * Documented in docs/boss-native58-grandchildren.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void dispatch_right_attack_by_variant_and_order(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    RAM8(0x0295) = (uint8_t)(a << 1);
    uint8_t value = RAM8(0x0042 + x);
    uint8_t value2 = RAM8(0x0295);
    r->a = (a_hi << 8) | (uint8_t)((uint8_t)(value << 2) + value2);
    r->x = (a_hi << 8) | (uint8_t)((uint8_t)(value << 2) + value2);
    r->c = (uint8_t)(value << 2) + value2 > 0xFF;
    r->z = ((a_hi << 8) | (uint8_t)((uint8_t)(value << 2) + value2)) == 0;
    r->n = ((a_hi << 8) | (uint8_t)((uint8_t)(value << 2) + value2)) & 0x8000;
    r->v = (((uint8_t)(value << 2) ^ (uint8_t)((uint8_t)(value << 2) + value2)) & (value2 ^ (uint8_t)((uint8_t)(value << 2) + value2)) & 0x80) != 0;
    switch ((a_hi << 8) | (uint8_t)((uint8_t)(value << 2) + value2)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC282A4, SOM_RTS); /* cast_right_spell08_variant_zero */
    case 0x0002: TAIL_CALL_DYN(c, 0xC282AB, SOM_RTS); /* cast_right_spell06 */
    case 0x0004: TAIL_CALL_DYN(c, 0xC282B2, SOM_RTS); /* cast_right_spell13 */
    case 0x0006: TAIL_CALL_DYN(c, 0xC282B9, SOM_RTS); /* cast_right_spell08_variant_one */
    case 0x0008: TAIL_CALL_DYN(c, 0xC281B9, SOM_RTS); /* prepare_left_projectile17 */
    case 0x000A: TAIL_CALL_DYN(c, 0xC281C7, SOM_RTS); /* prepare_left_projectile0a */
    case 0x000C: TAIL_CALL_DYN(c, 0xC281D5, SOM_RTS); /* cast_spell0b_from_linked_parent_and_execute_success */
    case 0x000E: c->fail = 3; return;   /* C20000 is the JSL entry of the boss loader: its RTL pops three bytes of this JSR-called routine's frame, so the original returns to a wild address */
    case 0x0010: TAIL_CALL_DYN(c, 0xC281B9, SOM_RTS); /* prepare_left_projectile17 */
    case 0x0012: TAIL_CALL_DYN(c, 0xC2820D, SOM_RTS); /* prepare_left_projectile10 */
    case 0x0014: TAIL_CALL_DYN(c, 0xC281D5, SOM_RTS); /* cast_spell0b_from_linked_parent_and_execute_success */
    case 0x0016: c->fail = 3; return;   /* same as index 0x0E */
    default: c->fail = 3; return;   /* the jump table has twelve entries; any other index is a wild jump */
    }
}
SOM_REGISTER(0xC28295, SOM_RTS, "hand", dispatch_right_attack_by_variant_and_order, SOM_UNWINDS, 0, 1, 1, 0, 15, 9)
