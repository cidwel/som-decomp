#include "som_c.h"

/* C2867A consume_native59_known_action_spell_or_report_unrecognized   [class B, 43 bytes, 22 instructions]
 * Source: src/rom/consume_native59_known_action_spell_or_report_unrecognized.s
 * Documented in docs/boss-native59-actions.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void consume_native59_known_action_spell_or_report_unrecognized_m16x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x000A + x);
    RAM8(0x0295) = (uint8_t)value;
    uint8_t a_hi1 = value >> 8;
    uint8_t x1 = 0;
    for (;;) {
        uint8_t value2 = BUS8(c, 0xC286A5 + x1);
        if (value2 == RAM8(0x0295)) {
            uint16_t value4 = RAM16(0x0287);
            RAM8(0x000A + value4) = 0xFF;
            r->a = (a_hi1 << 8) | RAM8(0x0295);
            r->x = value4;
            r->y = (uint8_t)y;
            r->c = 0;
            r->v = overflow;
            RETURN_RTS(c);
        }
        if ((uint8_t)(x1 + 1) < 0x0A) {
            x1 = (uint8_t)(x1 + 1);
            continue;
        }
        uint16_t value6 = RAM16(0x0287);
        r->a = (a_hi1 << 8) | value2;
        r->x = value6;
        r->y = (uint8_t)y;
        r->c = 1;
        r->v = overflow;
        RETURN_RTS(c);
    }
}

/* C2867A consume_native59_known_action_spell_or_report_unrecognized   [class B, 43 bytes, 22 instructions]
 * Source: src/rom/consume_native59_known_action_spell_or_report_unrecognized.s
 * Documented in docs/boss-native59-actions.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void consume_native59_known_action_spell_or_report_unrecognized_m8x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    RAM8(0x0295) = RAM8(0x000A + x);
    uint8_t a_hi1 = a_hi;
    uint8_t x1 = 0;
    for (;;) {
        uint8_t value2 = BUS8(c, 0xC286A5 + x1);
        if (value2 == RAM8(0x0295)) {
            uint16_t value4 = RAM16(0x0287);
            RAM8(0x000A + value4) = 0xFF;
            r->a = (a_hi1 << 8) | RAM8(0x0295);
            r->x = value4;
            r->y = (uint8_t)y;
            r->c = 0;
            r->v = overflow;
            r->mf = 0;
            RETURN_RTS(c);
        }
        if ((uint8_t)(x1 + 1) < 0x0A) {
            x1 = (uint8_t)(x1 + 1);
            continue;
        }
        uint16_t value6 = RAM16(0x0287);
        r->a = (a_hi1 << 8) | value2;
        r->x = value6;
        r->y = (uint8_t)y;
        r->c = 1;
        r->v = overflow;
        r->mf = 0;
        RETURN_RTS(c);
    }
}

/* Entered with M16/X16, M8/X16 accumulator/index widths: one body per width pair. */
static void consume_native59_known_action_spell_or_report_unrecognized(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (r->mf == 0 && r->xf == 0) { consume_native59_known_action_spell_or_report_unrecognized_m16x16(c); return; }
    if (r->mf == 1 && r->xf == 0) { consume_native59_known_action_spell_or_report_unrecognized_m8x16(c); return; }
    c->fail = 3;
}
SOM_REGISTER(0xC2867A, SOM_RTS, "gen", consume_native59_known_action_spell_or_report_unrecognized, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, -1, -1, 43, 22)
