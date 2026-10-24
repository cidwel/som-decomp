#include "som_c.h"

/* C0F025 synchronize_linked_hero_fields_unless_native_byte_positions_differ   [class B, 153 bytes, 62 instructions]
 * Source: src/rom/synchronize_linked_hero_fields_unless_native_byte_positions_differ.s
 * Documented in docs/actor-charge-hero-link.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABYCV.
 *
 * The three byte-position tests are called through JSR when the party-flag byte $F1 has bit 7 set or the hero's
 * $E?2C byte is zero; they can drop their return address (PLA, PLA), which returns to our caller without running
 * the field synchronisation (c->unwound, handled inside JSR).
 */
#define LDA8(val) do { uint8_t v_ = (val); SET_A8(r, v_); r->z = v_ == 0; r->n = v_ & 0x80; } while (0)
#define BIT8(val) do { uint8_t v_ = (val); r->z = (r->a & v_ & 0xFF) == 0; r->n = v_ & 0x80; r->v = v_ & 0x40; } while (0)

/* BIT $F1 / BMI call / LDA flag_byte / BNE skip / call: JSR retpc, target */
#define TEST_AND_CALL(flag_byte, retpc, target) do { \
        BIT8(RAM8(0x00F1)); \
        bool call_ = r->n; \
        if (!call_) { LDA8(RAM8(flag_byte)); call_ = r->z; } \
        if (call_) JSR(c, (retpc), (target)); \
    } while (0)

static void synchronize_linked_hero_fields_unless_native_byte_positions_differ(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0xE067) = 0;
    RAM8(0xE267) = 0;
    RAM8(0xE467) = 0;
    LDA8(RAM8(0x00D5));
    const uint8_t mode = r->a & 0xFF;
    if (mode == 0) {
        TEST_AND_CALL(0xE22C, 0xF03D, 0xC0F0C6);
        TEST_AND_CALL(0xE42C, 0xF049, 0xC0F0E8);
    } else if (mode == 2) {
        r->c = true; /* CMP #$02: A >= 2 */
        TEST_AND_CALL(0xE02C, 0xF05D, 0xC0F0BE);
        TEST_AND_CALL(0xE42C, 0xF069, 0xC0F10A);
    } else {
        r->c = mode >= 2;
        TEST_AND_CALL(0xE02C, 0xF079, 0xC0F0E0);
        TEST_AND_CALL(0xE22C, 0xF085, 0xC0F102);
    }
    RAM8(0x004E) = 0;
    r->xf = 0;
    r->x = RAM16(0x00D4);
    for (int n = 0; n < 3; n++) {
        static const uint16_t field[3] = { 0xE010, 0xE00B, 0xE08E };
        uint8_t v = RAM8(field[n] + r->x);
        RAM8(field[n]) = v;
        RAM8(field[n] + 0x200) = v;
        RAM8(field[n] + 0x400) = v;
        LDA8(v);
    }
    LDA8(RAM8(0x00FF));
    if (r->z) {
        r->mf = 0; /* REP #$20 */
        RAM16_SET(0xE406, 0);
        RAM16_SET(0xE206, 0);
        RAM16_SET(0xE006, 0);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0F025, SOM_RTS, "hand", synchronize_linked_hero_fields_unless_native_byte_positions_differ, 0, L_A | L_B | L_Y | L_C | L_V, 1, 1, 0, 153, 62)
