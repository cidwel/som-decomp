#include "som_c.h"

/* C27110 dispatch_descriptor_seven_variant_action   [class C, 23 bytes, 12 instructions]
 * Source: src/rom/dispatch_descriptor_seven_variant_action.s
 * Documented in docs/boss-descriptor-seven.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_descriptor_seven_variant_action(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x7112, 0xC27303); GUARD_JSR(c, sp_call, 0x7112); } /* select_alive_hero_nearest_on_vertical_axis */
    uint16_t x_ret = r->x;
    uint16_t value = RAM16(0x00A9 + x_ret);
    RAM16_SET(0x0295, (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
    uint16_t value2 = RAM16(0x0042 + x_ret);
    r->a = (uint16_t)(value2 << 1);
    r->x = (uint16_t)(value2 << 1);
    r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
    r->c = value2 & 0x8000;
    r->z = (uint16_t)(value2 << 1) == 0;
    r->n = (uint16_t)(value2 << 1) & 0x8000;
    r->v = (((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    switch ((uint16_t)(value2 << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC2712D, SOM_RTS); /* choose_descriptor_seven_variant_zero_action */
    case 0x0002: TAIL_CALL_DYN(c, 0xC27172, SOM_RTS); /* choose_descriptor_seven_variant_one_action */
    case 0x0004: TAIL_CALL_DYN(c, 0xC271F3, SOM_RTS); /* choose_descriptor_seven_variant_two_action */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x7127 + ((uint16_t)(value2 << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC27110, SOM_RTS, "gen", dispatch_descriptor_seven_variant_action, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 23, 12)
