#include "som_c.h"

/* C20F59 apply_boss_contact_class_eight_or_nine_control_reaction   [class B, 42 bytes, 19 instructions]
 * Source: src/rom/apply_boss_contact_class_eight_or_nine_control_reaction.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BYCV.
 */
static void apply_boss_contact_class_eight_or_nine_control_reaction(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint16_t value = RAM16(0x0256);
    bool carry2;
    if (((((uint8_t)value << 8) | (value >> 8)) & 0xFF) == 8) {
        uint16_t value2 = RAM16(0x0287);
        uint8_t value3 = RAM8(0x0034 + value2);
        RAM8(0x0034 + value2) = ((value3 & 0x70) << 1) | 1 | value3;
        RAM8(0x0100 + value2) = 0xC0;
        carry2 = value3 & 0x70 & 0x80;
    } else {
        bool carry1;
        if (((((uint8_t)value << 8) | (value >> 8)) & 0xFF) != 9) {
            carry1 = ((((uint8_t)value << 8) | (value >> 8)) & 0xFF) >= 9;
        } else {
            uint16_t value4 = RAM16(0x0287);
            uint8_t value5 = RAM8(0x0034 + value4);
            RAM8(0x0034 + value4) = ((value5 & 0x70) << 1) | 1 | value5;
            RAM8(0x0100 + value4) = 0xC0;
            carry1 = value5 & 0x70 & 0x80;
        }
        carry2 = carry1;
    }
    r->a = (uint8_t)a;
    r->c = carry2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20F59, SOM_RTS, "gen", apply_boss_contact_class_eight_or_nine_control_reaction, 0, L_B | L_Y | L_C | L_V, 1, 0, 0, 42, 19)
