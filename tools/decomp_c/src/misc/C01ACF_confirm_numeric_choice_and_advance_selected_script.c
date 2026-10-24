#include "som_c.h"

/* C01ACF confirm_numeric_choice_and_advance_selected_script   [class A, 34 bytes, 16 instructions]
 * Source: src/rom/confirm_numeric_choice_and_advance_selected_script.s
 * Documented in docs/event-dialogue-numeric-selection.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYV.
 */
static void confirm_numeric_choice_and_advance_selected_script(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool zero = r->z;
    const bool overflow = r->v;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool overflow1;
    if (!zero) {
        a_hi1 = a_hi;
        x1 = x;
        y1 = y;
        overflow1 = overflow;
    } else {
        uint16_t value = RAM16(0xA200);
        uint16_t value2 = RAM16(0xA1D5);
        RAM16_SET(0xA1D5, (uint16_t)(((value & 0xFF) + 1 << 1) + value2));
        RAM16_SET(0x1D01, (uint16_t)(((value & 0xFF) + 1 << 1) + value2));
        RAM8(0xA160)++;
        r->a = (uint16_t)(((value & 0xFF) + 1 << 1) + value2);
        r->c = ((value & 0xFF) + 1 << 1) + value2 > 0xFFFF;
        r->v = ((((value & 0xFF) + 1 << 1) ^ (uint16_t)(((value & 0xFF) + 1 << 1) + value2)) & (value2 ^ (uint16_t)(((value & 0xFF) + 1 << 1) + value2)) & 0x8000) != 0;
        r->sp -= 1;
        JSR(c, 0x1AEE, 0xC01BA5); /* preserve_accumulator_byte_and_request_fixed_local_audio_presets */
        r->sp += 1;
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y_ret;
        overflow1 = overflow_ret;
    }
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->y = y1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01ACF, SOM_RTS, "gen", confirm_numeric_choice_and_advance_selected_script, 0, L_A | L_B | L_X | L_Y | L_V, 1, 1, 0, 34, 16)
