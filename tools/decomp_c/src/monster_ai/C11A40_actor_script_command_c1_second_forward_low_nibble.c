#include "som_c.h"

/* C11A40 actor_script_command_c1_second_forward_low_nibble   [class B, 66 bytes, 26 instructions]
 * Source: src/rom/actor_script_command_c1_second_forward_low_nibble.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$01E3.  Callers read: ABXYCZNV.
 */
static void actor_script_command_c1_second_forward_low_nibble(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01E3) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint8_t a_1a81 = 0;
    uint8_t a_hi_1a81 = 0;
    uint8_t x_1a81 = 0;
    uint8_t y_1a81 = 0;
    bool carry_1a81 = 0;
    bool zero_1a81 = 0;
    bool negative_1a81 = 0;
    bool overflow_1a81 = 0;
    uint16_t direct_page_1a81 = 0;
    uint8_t a_1a812 = 0;
    uint8_t a_hi_1a812 = 0;
    uint16_t x_1a812 = 0;
    uint16_t y_1a812 = 0;
    bool carry_1a812 = 0;
    bool zero_1a812 = 0;
    bool negative_1a812 = 0;
    bool overflow_1a812 = 0;
    uint16_t direct_page_1a812 = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1A42, 0xC105BA); GUARD_JSR(c, sp_call, 0x1A42); } /* resolve_visible_second_actor_target */
    uint16_t dp_ret = r->dp;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    bool zero_ret = r->z;
    if (!zero_ret) {
        uint16_t value = RAM16(0x0144 + y);
        RAM16_SET(0x0144 + y, (uint16_t)(value + 3));
        if (x_ret) {
            a_1a81 = 0xFF;
            a_hi_1a81 = 0xFF;
            x_1a81 = (uint8_t)x_ret2;
            y_1a81 = (uint8_t)y;
            carry_1a81 = value + 3 > 0xFFFF;
            zero_1a81 = 0;
            negative_1a81 = 1;
            overflow_1a81 = ((value ^ (uint16_t)(value + 3)) & ((uint16_t)(value + 3) ^ 3) & 0x8000) != 0;
            direct_page_1a81 = dp_ret;
            goto shared_1A81;
        } else {
            a_1a812 = 0xFF;
            a_hi_1a812 = 0xFF;
            x_1a812 = x_ret2;
            y_1a812 = y;
            carry_1a812 = value + 3 > 0xFFFF;
            zero_1a812 = 0;
            negative_1a812 = 1;
            overflow_1a812 = ((value ^ (uint16_t)(value + 3)) & ((uint16_t)(value + 3) ^ 3) & 0x8000) != 0;
            direct_page_1a812 = dp_ret;
            goto shared_1A81_1;
        }
    }
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1A47, 0xC10404); GUARD_JSR(c, sp_call, 0x1A47); } /* calculate_actor_direction_codes */
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret3 = r->xf;
    uint16_t a_all2 = r->a;
    RAM8(0x0141 + y) = (uint8_t)a_all2 & 0x0F;
    RAM8(0x0140 + y) = 0xC1;
    if (x_ret3) {
        uint8_t value2 = RAM8(0x0144 + (uint8_t)y);
        uint8_t value3 = BUS8(c, 0xD04F16 + value2);
        RAM8(0x0142 + (uint8_t)y) = value3;
        uint8_t value4 = BUS8(c, 0xD04F17 + value2);
        RAM8(0x0143 + (uint8_t)y) = value4;
        RAM16_SET(0x0144 + (uint8_t)y, value2 + 3);
        a_1a81 = 0;
        a_hi_1a81 = 0;
        x_1a81 = value2;
        y_1a81 = (uint8_t)y;
        carry_1a81 = value2 + 3 > 0xFFFF;
        zero_1a81 = 1;
        negative_1a81 = 0;
        overflow_1a81 = ((value2 ^ value2 + 3) & (value2 + 3 ^ 3) & 0x8000) != 0;
        direct_page_1a81 = dp_ret;
        goto shared_1A81;
    } else {
        uint16_t value5 = RAM16(0x0144 + y);
        uint8_t value6 = BUS8(c, 0xD04F16 + value5);
        RAM8(0x0142 + y) = value6;
        uint8_t value7 = BUS8(c, 0xD04F17 + value5);
        RAM8(0x0143 + y) = value7;
        RAM16_SET(0x0144 + y, (uint16_t)(value5 + 3));
        a_1a812 = 0;
        a_hi_1a812 = 0;
        x_1a812 = value5;
        y_1a812 = y;
        carry_1a812 = value5 + 3 > 0xFFFF;
        zero_1a812 = 1;
        negative_1a812 = 0;
        overflow_1a812 = ((value5 ^ (uint16_t)(value5 + 3)) & ((uint16_t)(value5 + 3) ^ 3) & 0x8000) != 0;
        direct_page_1a812 = dp_ret;
        goto shared_1A81_1;
    }
    shared_1A81:;
    r->a = (a_hi_1a81 << 8) | a_1a81;
    r->x = x_1a81;
    r->y = y_1a81;
    r->c = carry_1a81;
    r->z = zero_1a81;
    r->n = negative_1a81;
    r->v = overflow_1a81;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = direct_page_1a81;
    RETURN_RTS(c);
    shared_1A81_1:;
    r->a = (a_hi_1a812 << 8) | a_1a812;
    r->x = x_1a812;
    r->y = y_1a812;
    r->c = carry_1a812;
    r->z = zero_1a812;
    r->n = negative_1a812;
    r->v = overflow_1a812;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = direct_page_1a812;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC11A40, SOM_RTS, "gen", actor_script_command_c1_second_forward_low_nibble, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 66, 26)
