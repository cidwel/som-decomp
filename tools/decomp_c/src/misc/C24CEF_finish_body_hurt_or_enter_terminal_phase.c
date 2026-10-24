#include "som_c.h"

/* C24CEF finish_body_hurt_or_enter_terminal_phase   [class B, 49 bytes, 20 instructions]
 * Source: src/rom/finish_body_hurt_or_enter_terminal_phase.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void finish_body_hurt_or_enter_terminal_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4CF3, 0xC234B9); GUARD_JSR(c, sp_call, 0x4CF3); } /* complete_boss_hurt_state_after_timeout_or_released_counter_status */
    uint16_t a_all = r->a;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool negative_ret = r->n;
    uint8_t a3;
    uint8_t a_hi3;
    uint16_t x3;
    bool zero3;
    bool negative3;
    if (!carry_ret) {
        a3 = (uint8_t)a_all;
        a_hi3 = a_all >> 8;
        x3 = value;
        zero3 = zero_ret;
        negative3 = negative_ret;
    } else {
        RAM16_SET(OBJECT_PHASE + value, 6);
        RAM16_SET(0x00BC + value, 6);
        RAM16_SET(OBJECT_AGE + value, 0);
        r->a = 6;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4D04, 0xC234B0); GUARD_JSR(c, sp_call, 0x4D04); } /* test_boss_negative_status_word */
        bool carry_ret2 = r->c;
        uint8_t a2;
        uint8_t a_hi2;
        uint16_t x2;
        bool zero2;
        bool negative2;
        if (carry_ret2) {
            uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
            RAM16_SET(OBJECT_AGE + value2, 0);
            RAM16_SET(OBJECT_PHASE + value2, 9);
            a2 = 9;
            a_hi2 = 0;
            x2 = value2;
            zero2 = 0;
            negative2 = 0;
        } else {
            uint16_t value3 = RAM16(0x00B0 + value);
            uint16_t value4 = RAM16(OBJECT_PHASE + value3);
            uint8_t a1;
            uint8_t a_hi1;
            uint16_t x1;
            bool zero1;
            bool negative1;
            if (value4 != 0x0F) {
                a1 = (uint8_t)value4;
                a_hi1 = value4 >> 8;
                x1 = value3;
                zero1 = value4 == 0x0F;
                negative1 = (uint16_t)(value4 - 0x0F) & 0x8000;
            } else {
                uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
                RAM16_SET(OBJECT_AGE + value5, 0);
                RAM16_SET(OBJECT_PHASE + value5, 9);
                a1 = 9;
                a_hi1 = 0;
                x1 = value5;
                zero1 = 0;
                negative1 = 0;
            }
            a2 = a1;
            a_hi2 = a_hi1;
            x2 = x1;
            zero2 = zero1;
            negative2 = negative1;
        }
        a3 = a2;
        a_hi3 = a_hi2;
        x3 = x2;
        zero3 = zero2;
        negative3 = negative2;
    }
    r->a = (a_hi3 << 8) | a3;
    r->x = x3;
    r->c = 0;
    r->z = zero3;
    r->n = negative3;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24CEF, SOM_RTS, "gen", finish_body_hurt_or_enter_terminal_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 49, 20)
