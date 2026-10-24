#include "som_c.h"

/* C11C24 actor_script_command_c1_from_velocity_and_native_mask   [class B, 106 bytes, 51 instructions]
 * Source: src/rom/actor_script_command_c1_from_velocity_and_native_mask.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_command_c1_from_velocity_and_native_mask(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 4) + 0x80 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0001 + (uint16_t)(sp0 - 4)) = 0;
    uint8_t value = RAM8(0x0006 + y);
    bool overflow1;
    if (value == 0) {
        overflow1 = overflow;
    } else {
        uint8_t value2 = RAM8(0x0080 + (uint16_t)(sp0 - 4));
        if ((value & value2) == 0) {
            RAM8(0x0001 + (uint16_t)(sp0 - 4)) = 1;
        } else {
            RAM8(0x0001 + (uint16_t)(sp0 - 4)) = 2;
        }
        overflow1 = value2 & 0x40;
    }
    uint8_t value3 = RAM8(0x0007 + y);
    bool overflow2;
    if (value3 == 0) {
        overflow2 = overflow1;
    } else {
        uint8_t value4 = RAM8(0x0080 + (uint16_t)(sp0 - 4));
        if ((value3 & value4) == 0) {
            RAM8(0x0001 + (uint16_t)(sp0 - 4)) |= 4;
        } else {
            RAM8(0x0001 + (uint16_t)(sp0 - 4)) |= 8;
        }
        overflow2 = value4 & 0x40;
    }
    uint8_t value7 = RAM8(0x0001 + (uint16_t)(sp0 - 4));
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t direct_page;
    if (value7 != 0) {
        x_flag = 0;
        a1 = value7;
        a_hi1 = (uint16_t)(sp0 - 4) >> 8;
        direct_page = (uint16_t)(sp0 - 4);
    } else {
        r->a = ((uint16_t)(sp0 - 4) >> 8 << 8) | value7;
        r->z = value7 == 0;
        r->n = value7 & 0x80;
        r->v = overflow2;
        r->dp = (uint16_t)(sp0 - 4);
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1C5F, 0xC10502); GUARD_JSR(c, sp_call, 0x1C5F); } /* read_actor_facing_direction_code */
        r->sp += 4;
        uint16_t dp_ret = r->dp;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        x_flag = x_ret;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        direct_page = dp_ret;
    }
    RAM8(0x0141 + y) = a1;
    RAM8(0x0140 + y) = 0xC1;
    if (x_flag) {
        uint8_t value8 = RAM8(0x0144 + (uint8_t)y);
        uint8_t value9 = BUS8(c, 0xD04F16 + value8);
        RAM8(0x0142 + (uint8_t)y) = value9;
        uint8_t value10 = BUS8(c, 0xD04F17 + value8);
        RAM8(0x0143 + (uint8_t)y) = value10;
        RAM16_SET(0x0144 + (uint8_t)y, value8 + 3);
        RAM8(0x0000 + sp0 - 3) = 0;
        uint8_t value11 = RAM8(0x0000 + sp0 - 3);
        uint8_t value12 = RAM8(0x0000 + sp0 - 2);
        uint8_t value13 = RAM8(0x0000 + sp0 - 1);
        uint8_t value14 = RAM8(0x0000 + sp0);
        r->a = value11;
        r->x = value8;
        r->y = (uint8_t)y;
        r->c = value12 & 0x01;
        r->z = ((value14 << 8) | value13) == 0;
        r->n = ((value14 << 8) | value13) & 0x8000;
        r->v = value12 & 0x40;
        r->mf = value12 & 0x20;
        r->xf = value12 & 0x10;
        r->dp = (value14 << 8) | value13;
        r->i = value12 & 0x04;
        r->d = value12 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value15 = RAM16(0x0144 + y);
        uint8_t value16 = BUS8(c, 0xD04F16 + value15);
        RAM8(0x0142 + y) = value16;
        uint8_t value17 = BUS8(c, 0xD04F17 + value15);
        RAM8(0x0143 + y) = value17;
        RAM16_SET(0x0144 + y, (uint16_t)(value15 + 3));
        RAM8(0x0000 + sp0 - 3) = 0;
        uint8_t value18 = RAM8(0x0000 + sp0 - 3);
        uint8_t value19 = RAM8(0x0000 + sp0 - 2);
        uint8_t value20 = RAM8(0x0000 + sp0 - 1);
        uint8_t value21 = RAM8(0x0000 + sp0);
        r->a = value18;
        r->x = value15;
        r->c = value19 & 0x01;
        r->z = ((value21 << 8) | value20) == 0;
        r->n = ((value21 << 8) | value20) & 0x8000;
        r->v = value19 & 0x40;
        r->mf = value19 & 0x20;
        r->xf = value19 & 0x10;
        r->dp = (value21 << 8) | value20;
        r->i = value19 & 0x04;
        r->d = value19 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC11C24, SOM_RTS, "gen", actor_script_command_c1_from_velocity_and_native_mask, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 4, 1, 0, 106, 51)
