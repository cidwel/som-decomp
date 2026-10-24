#include "som_c.h"

/* C11A82 actor_script_command_c1_current_reverse_low_nibble   [class B, 70 bytes, 30 instructions]
 * Source: src/rom/actor_script_command_c1_current_reverse_low_nibble.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_command_c1_current_reverse_low_nibble(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t y = r->y;
    uint8_t a_1ac7 = 0;
    uint8_t a_hi_1ac7 = 0;
    uint8_t x_1ac7 = 0;
    uint8_t y_1ac7 = 0;
    bool carry_1ac7 = 0;
    bool zero_1ac7 = 0;
    bool negative_1ac7 = 0;
    bool overflow_1ac7 = 0;
    uint16_t direct_page_1ac7 = 0;
    uint8_t a_1ac72 = 0;
    uint8_t a_hi_1ac72 = 0;
    uint16_t x_1ac72 = 0;
    uint16_t y_1ac72 = 0;
    bool carry_1ac72 = 0;
    bool zero_1ac72 = 0;
    bool negative_1ac72 = 0;
    bool overflow_1ac72 = 0;
    uint16_t direct_page_1ac72 = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x1A84, 0xC105A5); GUARD_JSR(c, sp_call, 0x1A84); } /* resolve_visible_current_actor_target */
    uint16_t dp_ret = r->dp;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    bool zero_ret = r->z;
    if (!zero_ret) {
        uint16_t value = RAM16(0x0144 + y);
        RAM16_SET(0x0144 + y, (uint16_t)(value + 3));
        if (x_ret) {
            a_1ac7 = 0xFF;
            a_hi_1ac7 = 0xFF;
            x_1ac7 = (uint8_t)x_ret2;
            y_1ac7 = (uint8_t)y;
            carry_1ac7 = value + 3 > 0xFFFF;
            zero_1ac7 = 0;
            negative_1ac7 = 1;
            overflow_1ac7 = ((value ^ (uint16_t)(value + 3)) & ((uint16_t)(value + 3) ^ 3) & 0x8000) != 0;
            direct_page_1ac7 = dp_ret;
            goto shared_1AC7;
        } else {
            a_1ac72 = 0xFF;
            a_hi_1ac72 = 0xFF;
            x_1ac72 = x_ret2;
            y_1ac72 = y;
            carry_1ac72 = value + 3 > 0xFFFF;
            zero_1ac72 = 0;
            negative_1ac72 = 1;
            overflow_1ac72 = ((value ^ (uint16_t)(value + 3)) & ((uint16_t)(value + 3) ^ 3) & 0x8000) != 0;
            direct_page_1ac72 = dp_ret;
            goto shared_1AC7_1;
        }
    }
    if (x_ret) {
        RAM8(0x0000 + sp0) = (uint8_t)x_ret2;
        r->x = (uint8_t)y;
        r->y = (uint8_t)x_ret2;
        r->z = (uint8_t)x_ret2 == 0;
        r->n = (uint8_t)x_ret2 & 0x80;
        r->mf = 1;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1A8C, 0xC10404); GUARD_JSR(c, sp_call, 0x1A8C); } /* calculate_actor_direction_codes */
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret3 = r->xf;
        uint16_t a_all2 = r->a;
        if (x_ret3) {
            RAM8(0x0141 + (uint8_t)y) = (uint8_t)a_all2 & 0x0F;
            RAM8(0x0140 + (uint8_t)y) = 0xC1;
            uint8_t value2 = RAM8(0x0144 + (uint8_t)y);
            uint8_t value3 = BUS8(c, 0xD04F16 + value2);
            RAM8(0x0142 + (uint8_t)y) = value3;
            uint8_t value4 = BUS8(c, 0xD04F17 + value2);
            RAM8(0x0143 + (uint8_t)y) = value4;
            RAM16_SET(0x0144 + (uint8_t)y, value2 + 3);
            a_1ac7 = 0;
            a_hi_1ac7 = 0;
            x_1ac7 = value2;
            y_1ac7 = (uint8_t)y;
            carry_1ac7 = value2 + 3 > 0xFFFF;
            zero_1ac7 = 1;
            negative_1ac7 = 0;
            overflow_1ac7 = ((value2 ^ value2 + 3) & (value2 + 3 ^ 3) & 0x8000) != 0;
            direct_page_1ac7 = dp_ret;
            goto shared_1AC7;
        } else {
            RAM8(0x0141 + (uint8_t)y) = (uint8_t)a_all2 & 0x0F;
            RAM8(0x0140 + (uint8_t)y) = 0xC1;
            uint16_t value5 = RAM16(0x0144 + (uint8_t)y);
            uint8_t value6 = BUS8(c, 0xD04F16 + value5);
            RAM8(0x0142 + (uint8_t)y) = value6;
            uint8_t value7 = BUS8(c, 0xD04F17 + value5);
            RAM8(0x0143 + (uint8_t)y) = value7;
            RAM16_SET(0x0144 + (uint8_t)y, (uint16_t)(value5 + 3));
            a_1ac72 = 0;
            a_hi_1ac72 = 0;
            x_1ac72 = value5;
            y_1ac72 = (uint8_t)y;
            carry_1ac72 = value5 + 3 > 0xFFFF;
            zero_1ac72 = 1;
            negative_1ac72 = 0;
            overflow_1ac72 = ((value5 ^ (uint16_t)(value5 + 3)) & ((uint16_t)(value5 + 3) ^ 3) & 0x8000) != 0;
            direct_page_1ac72 = dp_ret;
            goto shared_1AC7_1;
        }
    } else {
        RAM8(0x0000 + sp0) = x_ret2 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x_ret2;
        r->x = y;
        r->y = x_ret2;
        r->z = x_ret2 == 0;
        r->n = x_ret2 & 0x8000;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1A8C, 0xC10404); GUARD_JSR(c, sp_call, 0x1A8C); } /* calculate_actor_direction_codes */
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret4 = r->xf;
        uint16_t a_all3 = r->a;
        if (x_ret4) {
            RAM8(0x0141 + (uint8_t)y) = (uint8_t)a_all3 & 0x0F;
            RAM8(0x0140 + (uint8_t)y) = 0xC1;
            uint8_t value8 = RAM8(0x0144 + (uint8_t)y);
            uint8_t value9 = BUS8(c, 0xD04F16 + value8);
            RAM8(0x0142 + (uint8_t)y) = value9;
            uint8_t value10 = BUS8(c, 0xD04F17 + value8);
            RAM8(0x0143 + (uint8_t)y) = value10;
            RAM16_SET(0x0144 + (uint8_t)y, value8 + 3);
            a_1ac7 = 0;
            a_hi_1ac7 = 0;
            x_1ac7 = value8;
            y_1ac7 = (uint8_t)y;
            carry_1ac7 = value8 + 3 > 0xFFFF;
            zero_1ac7 = 1;
            negative_1ac7 = 0;
            overflow_1ac7 = ((value8 ^ value8 + 3) & (value8 + 3 ^ 3) & 0x8000) != 0;
            direct_page_1ac7 = dp_ret;
            goto shared_1AC7;
        } else {
            RAM8(0x0141 + y) = (uint8_t)a_all3 & 0x0F;
            RAM8(0x0140 + y) = 0xC1;
            uint16_t value11 = RAM16(0x0144 + y);
            uint8_t value12 = BUS8(c, 0xD04F16 + value11);
            RAM8(0x0142 + y) = value12;
            uint8_t value13 = BUS8(c, 0xD04F17 + value11);
            RAM8(0x0143 + y) = value13;
            RAM16_SET(0x0144 + y, (uint16_t)(value11 + 3));
            a_1ac72 = 0;
            a_hi_1ac72 = 0;
            x_1ac72 = value11;
            y_1ac72 = y;
            carry_1ac72 = value11 + 3 > 0xFFFF;
            zero_1ac72 = 1;
            negative_1ac72 = 0;
            overflow_1ac72 = ((value11 ^ (uint16_t)(value11 + 3)) & ((uint16_t)(value11 + 3) ^ 3) & 0x8000) != 0;
            direct_page_1ac72 = dp_ret;
            goto shared_1AC7_1;
        }
    }
    shared_1AC7:;
    r->a = (a_hi_1ac7 << 8) | a_1ac7;
    r->x = x_1ac7;
    r->y = y_1ac7;
    r->c = carry_1ac7;
    r->z = zero_1ac7;
    r->n = negative_1ac7;
    r->v = overflow_1ac7;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = direct_page_1ac7;
    RETURN_RTS(c);
    shared_1AC7_1:;
    r->a = (a_hi_1ac72 << 8) | a_1ac72;
    r->x = x_1ac72;
    r->y = y_1ac72;
    r->c = carry_1ac72;
    r->z = zero_1ac72;
    r->n = negative_1ac72;
    r->v = overflow_1ac72;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = direct_page_1ac72;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC11A82, SOM_RTS, "gen", actor_script_command_c1_current_reverse_low_nibble, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 70, 30)
