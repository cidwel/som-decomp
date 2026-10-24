#include "som_c.h"

/* C1213A actor_script_byte_field_set   [class A, 18 bytes, 7 instructions]
 * Source: src/rom/actor_script_byte_field_set.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$01E1.  Callers read: ABXYCZNV.
 */
static void actor_script_byte_field_set(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01E1) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t y = r->y;
    { const uint16_t sp_call = r->sp; JSR(c, 0x213C, 0xC11FEB); GUARD_JSR(c, sp_call, 0x213C); } /* resolve_actor_script_field_reference */
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    if (x_ret) {
        RAM8(0x0000 + sp0) = (uint8_t)x_ret2;
        uint8_t value = RAM8(0x0144 + (uint8_t)y);
        if (m_ret) {
            uint8_t value2 = BUS8(c, 0xD04F18 + value);
            RAM8(0x0180 + (uint8_t)x_ret2) = value2;
            r->a = (a_all >> 8 << 8) | value2;
            r->x = (uint8_t)x_ret2;
            r->y = (uint8_t)y;
            r->z = (uint8_t)x_ret2 == 0;
            r->n = (uint8_t)x_ret2 & 0x80;
            r->mf = 1;
            r->xf = 1;
            TAIL_CALL(c, 0xC1014B, SOM_RTS); /* advance_actor_script_4_bytes */
        } else {
            uint16_t value3 = BUS16(c, 0xD04F18 + value);
            RAM16_SET(0x0180 + (uint8_t)x_ret2, value3);
            r->a = value3;
            r->x = (uint8_t)x_ret2;
            r->y = (uint8_t)y;
            r->z = (uint8_t)x_ret2 == 0;
            r->n = (uint8_t)x_ret2 & 0x80;
            r->mf = 0;
            r->xf = 1;
            TAIL_CALL(c, 0xC1014B, SOM_RTS); /* advance_actor_script_4_bytes */
        }
    } else {
        RAM8(0x0000 + sp0) = x_ret2 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x_ret2;
        uint16_t value4 = RAM16(0x0144 + y);
        if (m_ret) {
            uint8_t value5 = BUS8(c, 0xD04F18 + value4);
            RAM8(0x0180 + x_ret2) = value5;
            r->a = (a_all >> 8 << 8) | value5;
            r->z = x_ret2 == 0;
            r->n = x_ret2 & 0x8000;
            r->mf = 1;
            r->xf = 0;
            TAIL_CALL(c, 0xC1014B, SOM_RTS); /* advance_actor_script_4_bytes */
        } else {
            uint16_t value6 = BUS16(c, 0xD04F18 + value4);
            RAM16_SET(0x0180 + x_ret2, value6);
            r->a = value6;
            r->z = x_ret2 == 0;
            r->n = x_ret2 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            TAIL_CALL(c, 0xC1014B, SOM_RTS); /* advance_actor_script_4_bytes */
        }
    }
}
SOM_REGISTER(0xC1213A, SOM_RTS, "gen", actor_script_byte_field_set, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 18, 7)
