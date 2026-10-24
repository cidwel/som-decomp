#include "som_c.h"

/* C00FFA request_dialogue_transfer_and_conditional_window_flags   [class A, 42 bytes, 23 instructions]
 * Source: src/rom/request_dialogue_transfer_and_conditional_window_flags.s
 * Documented in docs/event-dialogue-render-publication.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void request_dialogue_transfer_and_conditional_window_flags(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    RAM8(0x1D12) |= a;
    uint8_t value2 = RAM8(0x1D05);
    uint8_t a_hi3;
    if (value2 == 7) {
        RAM8(0x1D04) |= a;
        a_hi3 = value2;
    } else {
        uint8_t value4 = RAM8(0xA187);
        uint8_t a_hi2;
        if ((value4 & 1) != 0) {
            RAM8(0x1D04) |= a;
            a_hi2 = value4;
        } else {
            uint8_t value6 = RAM8(0xA162);
            uint8_t a_hi1;
            if (value6 == 1) {
                a_hi1 = a;
            } else {
                RAM8(0x1D04) |= a;
                a_hi1 = value6;
            }
            a_hi2 = a_hi1;
        }
        a_hi3 = a_hi2;
    }
    r->a = (r->a & 0x00FF) | (a_hi3 << 8);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00FFA, SOM_RTS, "gen", request_dialogue_transfer_and_conditional_window_flags, 0, L_B | L_X | L_Y | L_V, 2, 1, 0, 42, 23)
