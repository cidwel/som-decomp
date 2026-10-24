#include "som_c.h"

/* C11B0E actor_script_command_c1_current_forward_high_code   [class B, 67 bytes, 27 instructions]
 * Source: src/rom/actor_script_command_c1_current_forward_high_code.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_command_c1_current_forward_high_code(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t y = r->y;
    uint8_t a_1b50 = 0;
    uint8_t a_hi_1b50 = 0;
    uint8_t x_1b50 = 0;
    uint8_t y_1b50 = 0;
    bool carry_1b50 = 0;
    bool zero_1b50 = 0;
    bool negative_1b50 = 0;
    bool overflow_1b50 = 0;
    uint16_t direct_page_1b50 = 0;
    uint8_t a_1b502 = 0;
    uint8_t a_hi_1b502 = 0;
    uint16_t x_1b502 = 0;
    uint16_t y_1b502 = 0;
    bool carry_1b502 = 0;
    bool zero_1b502 = 0;
    bool negative_1b502 = 0;
    bool overflow_1b502 = 0;
    uint16_t direct_page_1b502 = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1B10, 0xC105A5); GUARD_JSR(c, sp_call, 0x1B10); } /* resolve_visible_current_actor_target */
    uint16_t dp_ret = r->dp;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    bool zero_ret = r->z;
    if (!zero_ret) {
        uint16_t value = RAM16(0x0144 + y);
        RAM16_SET(0x0144 + y, (uint16_t)(value + 3));
        if (x_ret) {
            a_1b50 = 0xFF;
            a_hi_1b50 = 0xFF;
            x_1b50 = (uint8_t)x_ret2;
            y_1b50 = (uint8_t)y;
            carry_1b50 = value + 3 > 0xFFFF;
            zero_1b50 = 0;
            negative_1b50 = 1;
            overflow_1b50 = ((value ^ (uint16_t)(value + 3)) & ((uint16_t)(value + 3) ^ 3) & 0x8000) != 0;
            direct_page_1b50 = dp_ret;
            goto shared_1B50;
        } else {
            a_1b502 = 0xFF;
            a_hi_1b502 = 0xFF;
            x_1b502 = x_ret2;
            y_1b502 = y;
            carry_1b502 = value + 3 > 0xFFFF;
            zero_1b502 = 0;
            negative_1b502 = 1;
            overflow_1b502 = ((value ^ (uint16_t)(value + 3)) & ((uint16_t)(value + 3) ^ 3) & 0x8000) != 0;
            direct_page_1b502 = dp_ret;
            goto shared_1B50_1;
        }
    }
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1B15, 0xC10404); GUARD_JSR(c, sp_call, 0x1B15); } /* calculate_actor_direction_codes */
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret3 = r->xf;
    uint16_t a_all2 = r->a;
    RAM8(0x0141 + y) = (a_all2 >> 8) & 0x0F;
    RAM8(0x0140 + y) = 0xC1;
    if (x_ret3) {
        uint8_t value2 = RAM8(0x0144 + (uint8_t)y);
        uint8_t value3 = BUS8(c, 0xD04F16 + value2);
        RAM8(0x0142 + (uint8_t)y) = value3;
        uint8_t value4 = BUS8(c, 0xD04F17 + value2);
        RAM8(0x0143 + (uint8_t)y) = value4;
        RAM16_SET(0x0144 + (uint8_t)y, value2 + 3);
        a_1b50 = 0;
        a_hi_1b50 = 0;
        x_1b50 = value2;
        y_1b50 = (uint8_t)y;
        carry_1b50 = value2 + 3 > 0xFFFF;
        zero_1b50 = 1;
        negative_1b50 = 0;
        overflow_1b50 = ((value2 ^ value2 + 3) & (value2 + 3 ^ 3) & 0x8000) != 0;
        direct_page_1b50 = dp_ret;
        goto shared_1B50;
    } else {
        uint16_t value5 = RAM16(0x0144 + y);
        uint8_t value6 = BUS8(c, 0xD04F16 + value5);
        RAM8(0x0142 + y) = value6;
        uint8_t value7 = BUS8(c, 0xD04F17 + value5);
        RAM8(0x0143 + y) = value7;
        RAM16_SET(0x0144 + y, (uint16_t)(value5 + 3));
        a_1b502 = 0;
        a_hi_1b502 = 0;
        x_1b502 = value5;
        y_1b502 = y;
        carry_1b502 = value5 + 3 > 0xFFFF;
        zero_1b502 = 1;
        negative_1b502 = 0;
        overflow_1b502 = ((value5 ^ (uint16_t)(value5 + 3)) & ((uint16_t)(value5 + 3) ^ 3) & 0x8000) != 0;
        direct_page_1b502 = dp_ret;
        goto shared_1B50_1;
    }
    shared_1B50:;
    r->a = (a_hi_1b50 << 8) | a_1b50;
    r->x = x_1b50;
    r->y = y_1b50;
    r->c = carry_1b50;
    r->z = zero_1b50;
    r->n = negative_1b50;
    r->v = overflow_1b50;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = direct_page_1b50;
    RETURN_RTS(c);
    shared_1B50_1:;
    r->a = (a_hi_1b502 << 8) | a_1b502;
    r->x = x_1b502;
    r->y = y_1b502;
    r->c = carry_1b502;
    r->z = zero_1b502;
    r->n = negative_1b502;
    r->v = overflow_1b502;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = direct_page_1b502;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC11B0E, SOM_RTS, "gen", actor_script_command_c1_current_forward_high_code, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 67, 27)
