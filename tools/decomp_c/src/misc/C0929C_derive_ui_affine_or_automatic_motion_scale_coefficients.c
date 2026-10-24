#include "som_c.h"

static void multiply_world_map_ui_direction_by_native_byte_scale(SomCtx *c);

/* C0929C derive_ui_affine_or_automatic_motion_scale_coefficients   [class B, 150 bytes, 80 instructions]
 * Source: src/rom/derive_ui_affine_or_automatic_motion_scale_coefficients.s
 * Documented in docs/ui-native-ui-frame-hdma.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void derive_ui_affine_or_automatic_motion_scale_coefficients(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0x0000) = 0;
    RAM8(0x0001) = 0;
    if (RAM8(0x008C) == 0) {
        uint8_t value2 = RAM8(0x00FE);
        uint8_t a2;
        if ((value2 & 0x3F) != 0) {
            uint8_t a1;
            if (value2 & 0x40) {
                a1 = (value2 & 0x3F) ^ 0x3F;
            } else {
                RAM8(0x0002) = ((value2 & 0x3F) ^ 0x3F) >> 2;
                a1 = (uint8_t)((((value2 & 0x3F) ^ 0x3F) >> 3) + RAM8(0x0002) + 1);
            }
            a2 = a1;
        } else {
            a2 = (uint8_t)(RAM8(0x00F8) + 4);
        }
        BUS8_SET(c, 0x004202, a2);
        BUS8_SET(c, 0x004203, RAM8(0x0032));
        if (RAM8(0x0033) != 0) {
            RAM8(0x0000) = a2;
        }
        uint8_t value7 = BUS8(c, 0x004217);
        BUS8_SET(c, 0x004203, RAM8(0x0030));
        uint16_t value9 = RAM16(0x0000);
        uint16_t value10 = RAM16(0x004B);
        uint8_t a3;
        uint8_t a_hi1;
        if (!(value10 & 0x8000)) {
            a3 = (uint8_t)(value7 + value9);
            a_hi1 = (uint16_t)(value7 + value9) >> 8;
        } else {
            a3 = (uint8_t)(((uint16_t)(value7 + value9) ^ 0xFFFF) + 1);
            a_hi1 = (uint16_t)(((uint16_t)(value7 + value9) ^ 0xFFFF) + 1) >> 8;
        }
        RAM16_SET(0x0036, (uint16_t)(((a_hi1 << 8) | a3) << 1));
        RAM8(0x0000) = 0;
        if (RAM8(0x0031) != 0) {
            RAM8(0x0000) = a2;
        }
        uint8_t value12 = BUS8(c, 0x004217);
        uint16_t value13 = RAM16(0x0000);
        uint8_t a4;
        uint8_t a_hi2;
        if (value10 & 0x4000) {
            a4 = (uint8_t)(value12 + value13);
            a_hi2 = (uint16_t)(value12 + value13) >> 8;
        } else {
            a4 = (uint8_t)(((uint16_t)(value12 + value13) ^ 0xFFFF) + 1);
            a_hi2 = (uint16_t)(((uint16_t)(value12 + value13) ^ 0xFFFF) + 1) >> 8;
        }
        RAM16_SET(0x0038, (uint16_t)(((a_hi2 << 8) | a4) << 1));
        RAM8(0x0060) = 0x80;
        r->a = (uint16_t)(((a_hi2 << 8) | a4) << 1);
        r->x = 0x80;
        r->y = a2;
        r->c = ((a_hi2 << 8) | a4) & 0x8000;
        r->v = value10 & 0x4000;
        r->mf = 0;
        RETURN_RTS(c);
    }
    if ((RAM8(0x00E3) & 6) != 0) {
        uint8_t value15 = RAM8(0x00FE);
        uint8_t a6;
        if ((value15 & 0x3F) != 0) {
            uint8_t a5;
            if (value15 & 0x40) {
                a5 = (value15 & 0x3F) ^ 0x3F;
            } else {
                RAM8(0x0002) = ((value15 & 0x3F) ^ 0x3F) >> 2;
                a5 = (uint8_t)((((value15 & 0x3F) ^ 0x3F) >> 3) + RAM8(0x0002) + 1);
            }
            a6 = a5;
        } else {
            a6 = (uint8_t)(RAM8(0x00F8) + 4);
        }
        BUS8_SET(c, 0x004202, a6);
        BUS8_SET(c, 0x004203, RAM8(0x0032));
        if (RAM8(0x0033) != 0) {
            RAM8(0x0000) = a6;
        }
        uint8_t value20 = BUS8(c, 0x004217);
        BUS8_SET(c, 0x004203, RAM8(0x0030));
        uint16_t value22 = RAM16(0x0000);
        uint16_t value23 = RAM16(0x004B);
        uint8_t a7;
        uint8_t a_hi3;
        if (!(value23 & 0x8000)) {
            a7 = (uint8_t)(value20 + value22);
            a_hi3 = (uint16_t)(value20 + value22) >> 8;
        } else {
            a7 = (uint8_t)(((uint16_t)(value20 + value22) ^ 0xFFFF) + 1);
            a_hi3 = (uint16_t)(((uint16_t)(value20 + value22) ^ 0xFFFF) + 1) >> 8;
        }
        RAM16_SET(0x0036, (uint16_t)(((a_hi3 << 8) | a7) << 1));
        RAM8(0x0000) = 0;
        if (RAM8(0x0031) != 0) {
            RAM8(0x0000) = a6;
        }
        uint8_t value25 = BUS8(c, 0x004217);
        uint16_t value26 = RAM16(0x0000);
        uint8_t a8;
        uint8_t a_hi4;
        if (value23 & 0x4000) {
            a8 = (uint8_t)(value25 + value26);
            a_hi4 = (uint16_t)(value25 + value26) >> 8;
        } else {
            a8 = (uint8_t)(((uint16_t)(value25 + value26) ^ 0xFFFF) + 1);
            a_hi4 = (uint16_t)(((uint16_t)(value25 + value26) ^ 0xFFFF) + 1) >> 8;
        }
        RAM16_SET(0x0038, (uint16_t)(((a_hi4 << 8) | a8) << 1));
        RAM8(0x0060) = 0x80;
        r->a = (uint16_t)(((a_hi4 << 8) | a8) << 1);
        r->x = 0x80;
        r->y = a6;
        r->c = ((a_hi4 << 8) | a8) & 0x8000;
        r->v = value23 & 0x4000;
        r->mf = 0;
        RETURN_RTS(c);
    }
    r->a = RAM8(0x0090);
    { const uint16_t sp_call = r->sp; JSR_LOCAL(c, 0x92B3, multiply_world_map_ui_direction_by_native_byte_scale); GUARD_JSR(c, sp_call, 0x92B3); }
    uint16_t dp_ret = r->dp;
    uint16_t value28 = RAM16(0x0036 + dp_ret);
    RAM16_SET(0x0036 + dp_ret, (uint16_t)(((value28 >> 1) | ((value28 >= 0x8000) << 0x0F)) + value28 + (value28 & 1)));
    uint16_t value29 = RAM16(0x0038 + dp_ret);
    RAM16_SET(0x0038 + dp_ret, (uint16_t)(((value29 >> 1) | ((value29 >= 0x8000) << 0x0F)) + value29 + (value29 & 1)));
    r->a = (uint16_t)(((value29 >> 1) | ((value29 >= 0x8000) << 0x0F)) + value29 + (value29 & 1));
    r->c = ((value29 >> 1) | ((value29 >= 0x8000) << 0x0F)) + value29 + (value29 & 1) > 0xFFFF;
    r->v = ((((value29 >> 1) | ((value29 >= 0x8000) << 0x0F)) ^ (uint16_t)(((value29 >> 1) | ((value29 >= 0x8000) << 0x0F)) + value29 + (value29 & 1))) & (value29 ^ (uint16_t)(((value29 >> 1) | ((value29 >= 0x8000) << 0x0F)) + value29 + (value29 & 1))) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0929C, SOM_RTS, "gen", derive_ui_affine_or_automatic_motion_scale_coefficients, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 150, 80)

/* C092E8 multiply_world_map_ui_direction_by_native_byte_scale   [class A, 74 bytes, 39 instructions]
 * Source: src/rom/derive_ui_affine_or_automatic_motion_scale_coefficients.s
 * Subroutine of derive_ui_affine_or_automatic_motion_scale_coefficients, translated in place.
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void multiply_world_map_ui_direction_by_native_byte_scale(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    BUS8_SET(c, 0x004202, (uint8_t)((a_hi << 8) | a));
    BUS8_SET(c, 0x004203, RAM8(0x0032));
    if (RAM8(0x0033) != 0) {
        RAM8(0x0000) = (uint8_t)((a_hi << 8) | a);
    }
    uint8_t value3 = BUS8(c, 0x004217);
    BUS8_SET(c, 0x004203, RAM8(0x0030));
    uint16_t value5 = RAM16(0x0000);
    uint16_t value6 = RAM16(0x004B);
    uint8_t a1;
    uint8_t a_hi1;
    if (!(value6 & 0x8000)) {
        a1 = (uint8_t)(((a_hi << 8) | value3) + value5);
        a_hi1 = (uint16_t)(((a_hi << 8) | value3) + value5) >> 8;
    } else {
        a1 = (uint8_t)(((uint16_t)(((a_hi << 8) | value3) + value5) ^ 0xFFFF) + 1);
        a_hi1 = (uint16_t)(((uint16_t)(((a_hi << 8) | value3) + value5) ^ 0xFFFF) + 1) >> 8;
    }
    RAM16_SET(0x0036, (uint16_t)(((a_hi1 << 8) | a1) << 1));
    RAM8(0x0000) = 0;
    if (RAM8(0x0031) != 0) {
        RAM8(0x0000) = (uint8_t)((a_hi << 8) | a);
    }
    uint8_t value8 = BUS8(c, 0x004217);
    uint16_t value9 = RAM16(0x0000);
    uint8_t a2;
    uint8_t a_hi2;
    if (value6 & 0x4000) {
        a2 = (uint8_t)(value8 + value9);
        a_hi2 = (uint16_t)(value8 + value9) >> 8;
    } else {
        a2 = (uint8_t)(((uint16_t)(value8 + value9) ^ 0xFFFF) + 1);
        a_hi2 = (uint16_t)(((uint16_t)(value8 + value9) ^ 0xFFFF) + 1) >> 8;
    }
    RAM16_SET(0x0038, (uint16_t)(((a_hi2 << 8) | a2) << 1));
    RAM8(0x0060) = 0x80;
    r->a = (uint16_t)(((a_hi2 << 8) | a2) << 1);
    r->x = 0x80;
    r->y = (uint8_t)((a_hi << 8) | a);
    r->c = ((a_hi2 << 8) | a2) & 0x8000;
    r->z = 0;
    r->n = 1;
    r->v = value6 & 0x4000;
    r->mf = 0;
    RETURN_RTS(c);
}
