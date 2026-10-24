#include "som_c.h"

/* C11FEB resolve_actor_script_field_reference   [class B, 87 bytes, 48 instructions]
 * Source: src/rom/resolve_actor_script_field_reference.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: XYCV.
 */
static void resolve_actor_script_field_reference(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0144 + y);
    uint16_t value2 = BUS16(c, 0xD04F17 + value);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), value2 & 0xFF);
    uint8_t value3 = BUS8(c, 0xD04F16 + value);
    uint8_t a4;
    uint8_t a_hi4;
    if (value3 < 0x80) {
        a4 = (uint8_t)((((uint8_t)(value3 << 1) << 8) | 0) + 0xE000);
        a_hi4 = (uint16_t)((((uint8_t)(value3 << 1) << 8) | 0) + 0xE000) >> 8;
    } else {
        uint8_t a3;
        uint8_t a_hi3;
        if (value3 == 0x80) {
            a3 = (uint8_t)y;
            a_hi3 = y >> 8;
        } else {
            uint8_t a2;
            uint8_t a_hi2;
            if (value3 < 0x82) {
                uint8_t value4 = RAM8(0x01AC + y);
                a2 = (uint8_t)((((uint8_t)(value4 << 1) << 8) | 0) + 0xE000);
                a_hi2 = (uint16_t)((((uint8_t)(value4 << 1) << 8) | 0) + 0xE000) >> 8;
            } else {
                uint8_t a1;
                uint8_t a_hi1;
                if (value3 == 0x82) {
                    uint8_t value5 = RAM8(0x01AD + y);
                    a1 = (uint8_t)((((uint8_t)(value5 << 1) << 8) | 0) + 0xE000);
                    a_hi1 = (uint16_t)((((uint8_t)(value5 << 1) << 8) | 0) + 0xE000) >> 8;
                } else {
                    a1 = (uint8_t)((((uint8_t)((y & 0x0600) >> 1) << 8) | ((y & 0x0600) >> 1 >> 8)) + 0xCA80);
                    a_hi1 = (uint16_t)((((uint8_t)((y & 0x0600) >> 1) << 8) | ((y & 0x0600) >> 1 >> 8)) + 0xCA80) >> 8;
                }
                a2 = a1;
                a_hi2 = a_hi1;
            }
            a3 = a2;
            a_hi3 = a_hi2;
        }
        a4 = a3;
        a_hi4 = a_hi3;
    }
    r->x = (uint16_t)(((a_hi4 << 8) | a4) + RAM16(0x0001 + (uint16_t)(sp0 - 5)));
    RETURN_RTS(c);
}
SOM_REGISTER(0xC11FEB, SOM_RTS, "gen", resolve_actor_script_field_reference, 0, L_X | L_Y | L_C | L_V, 5, -1, 0, 87, 48)
