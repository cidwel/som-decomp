#include "som_c.h"

/* C1214D actor_script_if_saved_position_same   [class B, 27 bytes, 11 instructions]
 * Source: src/rom/actor_script_if_saved_position_same.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_if_saved_position_same(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0020 + y);
    uint16_t value2 = RAM16(0x0148 + y);
    uint8_t a2;
    uint8_t a_hi2;
    uint16_t x2;
    bool carry2;
    bool zero2;
    bool negative2;
    bool overflow2;
    if (value != value2) {
        r->a = value;
        r->c = value >= value2;
        r->mf = 0;
        JSR(c, 0x2166, 0xC10213); /* skip_actor_script_after_1_bytes */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        bool carry_ret = r->c;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        bool overflow_ret = r->v;
        a2 = (uint8_t)a_all;
        a_hi2 = a_all >> 8;
        x2 = x_ret;
        carry2 = carry_ret;
        zero2 = zero_ret;
        negative2 = negative_ret;
        overflow2 = overflow_ret;
    } else {
        r->c = value >= value2;
        r->z = value == value2;
        r->n = (uint16_t)(value - value2) & 0x8000;
        r->mf = 0;
        JSR(c, 0x2159, 0xC1032E); /* read_actor_y_minus_height_y */
        uint16_t a_all2 = r->a;
        uint16_t value3 = RAM16(0x014A + y);
        uint8_t a1;
        uint8_t a_hi1;
        uint16_t x1;
        bool carry1;
        bool zero1;
        bool negative1;
        bool overflow1;
        if (a_all2 != value3) {
            r->c = a_all2 >= value3;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x2166, 0xC10213); /* skip_actor_script_after_1_bytes */
            uint16_t a_all3 = r->a;
            uint16_t x_ret2 = r->x;
            bool carry_ret3 = r->c;
            bool zero_ret3 = r->z;
            bool negative_ret3 = r->n;
            bool overflow_ret3 = r->v;
            a1 = (uint8_t)a_all3;
            a_hi1 = a_all3 >> 8;
            x1 = x_ret2;
            carry1 = carry_ret3;
            zero1 = zero_ret3;
            negative1 = negative_ret3;
            overflow1 = overflow_ret3;
        } else {
            r->c = a_all2 >= value3;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x2161, 0xC10285); /* jump_actor_script_after_1_bytes */
            uint16_t a_all4 = r->a;
            uint16_t x_ret3 = r->x;
            bool carry_ret4 = r->c;
            bool zero_ret4 = r->z;
            bool negative_ret4 = r->n;
            bool overflow_ret4 = r->v;
            a1 = (uint8_t)a_all4;
            a_hi1 = a_all4 >> 8;
            x1 = x_ret3;
            carry1 = carry_ret4;
            zero1 = zero_ret4;
            negative1 = negative_ret4;
            overflow1 = overflow_ret4;
        }
        a2 = a1;
        a_hi2 = a_hi1;
        x2 = x1;
        carry2 = carry1;
        zero2 = zero1;
        negative2 = negative1;
        overflow2 = overflow1;
    }
    r->a = (a_hi2 << 8) | a2;
    r->x = x2;
    r->c = carry2;
    r->z = zero2;
    r->n = negative2;
    r->v = overflow2;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1214D, SOM_RTS, "gen", actor_script_if_saved_position_same, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 27, 11)
