#include "som_c.h"

/* C0126F complete_dialogue_line_and_select_next_render_phase   [class A, 79 bytes, 31 instructions]
 * Source: src/rom/complete_dialogue_line_and_select_next_render_phase.s
 * Documented in docs/event-dialogue-line-completion.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void complete_dialogue_line_and_select_next_render_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool carry = r->c;
    RAM8(0xA15D) = 0;
    RAM8(0xA16D) = 0;
    RAM16_SET(0xA189, 0x9000);
    uint8_t value = RAM8(0x1D00);
    uint8_t a5;
    bool carry3;
    bool zero5;
    bool negative5;
    if ((value & 0x80) != 0) {
        RAM8(0xA15D) = 9;
        a5 = 9;
        carry3 = carry;
        zero5 = 0;
        negative5 = 0;
    } else {
        uint8_t a4;
        bool carry2;
        bool zero4;
        bool negative4;
        if ((value & 1) == 0) {
            RAM8(0xA170) = 0;
            uint8_t value2 = RAM8(0x1D05);
            uint8_t a1;
            bool zero1;
            bool negative1;
            if (value2 != 7) {
                a1 = value2;
                zero1 = value2 == 7;
                negative1 = (uint8_t)(value2 - 7) & 0x80;
            } else {
                RAM8(0xA15D) = 9;
                RAM8(0xA170) = 0x53;
                a1 = 0x53;
                zero1 = 0;
                negative1 = 0;
            }
            a4 = a1;
            carry2 = value2 >= 7;
            zero4 = zero1;
            negative4 = negative1;
        } else {
            RAM8(0x1D00) = value & 0xFE;
            uint8_t value3 = RAM8(0xA16B);
            uint8_t value4 = RAM8(0xA180);
            uint8_t a3;
            bool carry1;
            bool zero3;
            bool negative3;
            if ((uint8_t)((value3 >> 1) - 1) != value4) {
                RAM8(0xA180)++;
                RAM8(0xA170) = 0;
                uint8_t value5 = RAM8(0x1D05);
                uint8_t a2;
                bool zero2;
                bool negative2;
                if (value5 != 7) {
                    a2 = value5;
                    zero2 = value5 == 7;
                    negative2 = (uint8_t)(value5 - 7) & 0x80;
                } else {
                    RAM8(0xA15D) = 9;
                    RAM8(0xA170) = 0x53;
                    a2 = 0x53;
                    zero2 = 0;
                    negative2 = 0;
                }
                a3 = a2;
                carry1 = value5 >= 7;
                zero3 = zero2;
                negative3 = negative2;
            } else {
                RAM8(0xA180) = (uint8_t)((value3 >> 1) - 1);
                RAM8(0xA15D) = 9;
                a3 = 9;
                carry1 = (uint8_t)((value3 >> 1) - 1) >= value4;
                zero3 = 0;
                negative3 = 0;
            }
            a4 = a3;
            carry2 = carry1;
            zero4 = zero3;
            negative4 = negative3;
        }
        a5 = a4;
        carry3 = carry2;
        zero5 = zero4;
        negative5 = negative4;
    }
    SET_A8(r, a5);
    r->x = 0x9000;
    r->c = carry3;
    r->z = zero5;
    r->n = negative5;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0126F, SOM_RTS, "gen", complete_dialogue_line_and_select_next_render_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 79, 31)
