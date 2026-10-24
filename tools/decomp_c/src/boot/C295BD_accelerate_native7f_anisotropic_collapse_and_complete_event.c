#include "som_c.h"

/* C295BD accelerate_native7f_anisotropic_collapse_and_complete_event   [class B, 142 bytes, 58 instructions]
 * Source: src/rom/accelerate_native7f_anisotropic_collapse_and_complete_event.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void accelerate_native7f_anisotropic_collapse_and_complete_event(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value2 = RAM16(0x00BC + value);
    uint8_t a1;
    uint8_t a_hi1;
    if ((uint16_t)(value2 + 3) < 0x20) {
        a1 = (uint8_t)(value2 + 3);
        a_hi1 = (uint16_t)(value2 + 3) >> 8;
    } else {
        a1 = 0x20;
        a_hi1 = 0;
    }
    RAM16_SET(0x00BC + value, (a_hi1 << 8) | a1);
    RAM16_SET(0x00B4 + value, (uint16_t)(RAM16(0x00B4 + value) + RAM16(0x00BC + value)));
    if (RAM16(0x00B6 + value) != 0) {
        uint16_t value6 = RAM16(0x00B8 + value);
        RAM16_SET(0x00B8 + value, (uint16_t)(value6 + 3));
        uint16_t value7 = RAM16(0x00B0 + value);
        if ((uint16_t)((uint16_t)(value6 + 3) + value7) < 0x1000) {
            RAM16_SET(0x00B0 + value, (uint16_t)((uint16_t)(value6 + 3) + value7));
            r->a = (uint16_t)((uint16_t)(value6 + 3) + value7);
            r->x = value;
            r->c = (uint16_t)((uint16_t)(value6 + 3) + value7) >= 0x1000;
            r->z = (uint16_t)((uint16_t)(value6 + 3) + value7) == 0x1000;
            r->n = (uint16_t)((uint16_t)((uint16_t)(value6 + 3) + value7) - 0x1000) & 0x8000;
            r->v = (((uint16_t)(value6 + 3) ^ (uint16_t)((uint16_t)(value6 + 3) + value7)) & (value7 ^ (uint16_t)((uint16_t)(value6 + 3) + value7)) & 0x8000) != 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9648, 0xC297FD); GUARD_JSR(c, sp_call, 0x9648); } /* derive_anisotropic_native7f_mode7_matrix_from_two_scales_and_angle */
            r->c = 0;
            r->mf = 0;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        RAM16_SET(0x00B0 + value, 0x8000);
        uint16_t value8 = RAM16(0x0072 + value);
        r->a = value8;
        r->x = value;
        r->c = (uint16_t)((uint16_t)(value6 + 3) + value7) >= 0x1000;
        r->z = value8 == 0;
        r->n = value8 & 0x8000;
        r->v = (((uint16_t)(value6 + 3) ^ (uint16_t)((uint16_t)(value6 + 3) + value7)) & (value7 ^ (uint16_t)((uint16_t)(value6 + 3) + value7)) & 0x8000) != 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x963B, 0xC20C11); GUARD_JSR(c, sp_call, 0x963B); } /* mark_controller_and_request_numeric_boss_death_event */
        uint16_t dp_ret = r->dp;
        bool x_ret3 = r->xf;
        uint16_t y_ret = r->y;
        if (x_ret3) {
            uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->x = value9;
            r->y = (uint8_t)y_ret;
            r->z = value9 == 0;
            r->n = value9 & 0x80;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9640, 0xC297FD); GUARD_JSR(c, sp_call, 0x9640); } /* derive_anisotropic_native7f_mode7_matrix_from_two_scales_and_angle */
            r->c = 1;
            r->mf = 0;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->x = value10;
            r->z = value10 == 0;
            r->n = value10 & 0x8000;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9640, 0xC297FD); GUARD_JSR(c, sp_call, 0x9640); } /* derive_anisotropic_native7f_mode7_matrix_from_two_scales_and_angle */
            r->c = 1;
            r->mf = 0;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
    RAM16_SET(0x00B8 + value, 1);
    uint16_t value11 = RAM16(0x00B0 + value);
    uint16_t value12 = RAM16(0x00B8 + value);
    uint8_t a2;
    uint8_t a_hi2;
    if (!((uint16_t)(value11 - value12) & 0x8000)) {
        a2 = (uint8_t)(value11 - value12);
        a_hi2 = (uint16_t)(value11 - value12) >> 8;
    } else {
        uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp + 0xC5));
        a2 = (uint8_t)value13;
        a_hi2 = value13 >> 8;
    }
    RAM16_SET(0x00B0 + value, (a_hi2 << 8) | a2);
    RAM16_SET(0x00BA + value, (uint16_t)(RAM16(0x00BA + value) + 3));
    uint16_t value15 = RAM16(0x00B2 + value);
    uint16_t value16 = RAM16(0x00BA + value);
    RAM16_SET(0x00B2 + value, (uint16_t)(value15 + value16));
    uint8_t a3;
    uint8_t a_hi3;
    bool zero1;
    bool negative1;
    if ((uint16_t)(value15 + value16) < 0x1000) {
        a3 = (uint8_t)(value15 + value16);
        a_hi3 = (uint16_t)(value15 + value16) >> 8;
        zero1 = (uint16_t)(value15 + value16) == 0x1000;
        negative1 = (uint16_t)((uint16_t)(value15 + value16) - 0x1000) & 0x8000;
    } else {
        uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp + 0xC7));
        RAM16_SET(0x00B6 + value, value17);
        RAM16_SET(0x00B8 + value, 0);
        RAM16_SET(0x00B2 + value, 0x8000);
        a3 = 0;
        a_hi3 = 0x80;
        zero1 = 0;
        negative1 = 1;
    }
    r->a = (a_hi3 << 8) | a3;
    r->x = value;
    r->c = (uint16_t)(value15 + value16) >= 0x1000;
    r->z = zero1;
    r->n = negative1;
    r->v = ((value15 ^ (uint16_t)(value15 + value16)) & (value16 ^ (uint16_t)(value15 + value16)) & 0x8000) != 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9648, 0xC297FD); GUARD_JSR(c, sp_call, 0x9648); } /* derive_anisotropic_native7f_mode7_matrix_from_two_scales_and_angle */
    r->c = 0;
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC295BD, SOM_RTS, "gen", accelerate_native7f_anisotropic_collapse_and_complete_event, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 142, 58)
