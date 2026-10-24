#include "som_c.h"

/* C04B7D apply_three_armor_attribute_flags   [class B, 19 bytes, 8 instructions]
 * Source: src/rom/apply_three_armor_attribute_flags.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXY.
 */
static void apply_three_armor_attribute_flags(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value;
    BUS8_OK(c, (RAM8(0x03CB) << 0x10) + RAM16(0x03C9) + 0x3ED0, value);
    r->a = (a_hi << 8) | value;
    r->y = 0x3ED0;
    JSR(c, 0x4B84, 0xC04B90); /* apply_single_armor_attribute_flags */
    uint16_t a_all = r->a;
    uint8_t value2;
    BUS8_OK(c, (RAM8(0x03C8) << 0x10) + RAM16(0x03C6) + 0x3ED0, value2);
    r->a = (a_all >> 8 << 8) | value2;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x4B89, 0xC04B90); /* apply_single_armor_attribute_flags */
    uint16_t a_all2 = r->a;
    uint8_t value3;
    BUS8_OK(c, (RAM8(0x03C5) << 0x10) + RAM16(0x03C3) + 0x3ED0, value3);
    r->a = (a_all2 >> 8 << 8) | value3;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x4B8E, 0xC04B90); /* apply_single_armor_attribute_flags */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04B7D, SOM_RTS, "hand", apply_three_armor_attribute_flags, 0, L_B | L_X | L_Y, 1, 1, 0, 19, 8)
