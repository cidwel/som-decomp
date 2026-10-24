#include "som_c.h"

/* C209B4 compute_capped_boss_maximum_over_current_hp_ratio   [class B, 34 bytes, 15 instructions]
 * Source: src/rom/compute_capped_boss_maximum_over_current_hp_ratio.s
 * Documented in docs/boss-descriptor-five.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYV.
 */
static void compute_capped_boss_maximum_over_current_hp_ratio(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    if (!(RAM16(0x0190 + value) & 0x8000)) {
        RAM16_SET(0x024E, RAM16(0x0182 + value));
        uint16_t value4 = RAM16(0x0184 + value);
        RAM16_SET(0x0246, value4);
        r->a = value4;
        r->x = value;
        JSR(c, 0x09CA, 0xC22CBF); /* divide_unsigned_word_by_word_in_software */
        uint16_t value5 = RAM16(0x0256);
        uint8_t a1;
        uint8_t a_hi1;
        if (value5 < 4) {
            a1 = (uint8_t)value5;
            a_hi1 = value5 >> 8;
        } else {
            a1 = 4;
            a_hi1 = 0;
        }
        r->a = (a_hi1 << 8) | a1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = RAM16(0x02C5);
    r->x = value;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC209B4, SOM_RTS, "gen", compute_capped_boss_maximum_over_current_hp_ratio, 0, L_A | L_B | L_X | L_Y | L_V, 1, 0, 0, 34, 15)
