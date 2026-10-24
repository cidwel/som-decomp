#include "som_c.h"

/* C24B27 initialize_native54_body_identity67_attack1e   [class B, 88 bytes, 32 instructions]
 * Source: src/rom/initialize_native54_body_identity67_attack1e.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_native54_body_identity67_attack1e(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x0000 + value, 1);
    RAM16_SET(0x00A5 + value, 0);
    RAM16_SET(0x0022 + value, RAM16(0x0032 + value));
    RAM16_SET(OBJECT_PHASE + value, 3);
    r->a = 0;
    r->x = value;
    r->z = 1;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4B43, 0xC21394); GUARD_JSR(c, sp_call, 0x4B43); } /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x001E + value, 2);
    RAM16_SET(0x0092 + value, 0x3000);
    RAM16_SET(0x0066 + value, 0);
    RAM16_SET(0x003C + value, 0);
    RAM16_SET(0x0040 + value, 0);
    RAM8(0x0046 + value) = 0;
    RAM8(0x0047 + value) = 0;
    RAM8(0x0074 + value) = 0;
    RAM8(0x0010 + value) = 1;
    r->a = 0x67;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x4B71, 0xC0003F); GUARD_JSL(c, sp_call, 0x4B71); } /* change_actor_identity_public_jump */
    uint16_t dp_ret = r->dp;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t y_ret = r->y;
    if (x_ret) {
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        r->a = 0x1E;
        r->x = value3;
        r->y = (uint8_t)y_ret;
        r->z = 0;
        r->n = 0;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x4B7A, 0xC0006C); GUARD_JSL(c, sp_call, 0x4B7A); } /* boss_attack_row_public_jump */
        bool x_ret3 = r->xf;
        uint16_t y_ret2 = r->y;
        if (x_ret3) {
            uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->x = value4;
            r->y = (uint8_t)y_ret2;
            r->c = 0;
            r->z = value4 == 0;
            r->n = value4 & 0x80;
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->x = value5;
            r->c = 0;
            r->z = value5 == 0;
            r->n = value5 & 0x8000;
            r->xf = 0;
            RETURN_RTS(c);
        }
    } else {
        uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        r->a = 0x1E;
        r->x = value6;
        r->z = 0;
        r->n = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x4B7A, 0xC0006C); GUARD_JSL(c, sp_call, 0x4B7A); } /* boss_attack_row_public_jump */
        bool x_ret5 = r->xf;
        uint16_t y_ret3 = r->y;
        if (x_ret5) {
            uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->x = value7;
            r->y = (uint8_t)y_ret3;
            r->c = 0;
            r->z = value7 == 0;
            r->n = value7 & 0x80;
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->x = value8;
            r->c = 0;
            r->z = value8 == 0;
            r->n = value8 & 0x8000;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC24B27, SOM_RTS, "gen", initialize_native54_body_identity67_attack1e, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 88, 32)
