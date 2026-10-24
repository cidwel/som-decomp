#include "som_c.h"

/* C06B0A test_available_living_menu_actor_mask   [class C, 60 bytes, 29 instructions]
 * Source: src/rom/test_available_living_menu_actor_mask.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCZV.
 */
static void test_available_living_menu_actor_mask(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t x = r->x;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6B0C, 0xC06B03); GUARD_JSR(c, sp_call, 0x6B0C); } /* read_union_of_party_controller_bindings */
    uint16_t a_all = r->a;
    uint8_t value = BUS8(c, 0xC06B46 + x);
    if ((((uint8_t)a_all ^ 0xFF) & value) == 0) {
        SET_A8(r, 0);
        r->z = 1;
        r->mf = 1;
        r->xf = 1;
        RETURN_RTS(c);
    }
    RAM8(0x0000 + sp0) = ((uint8_t)a_all ^ 0xFF) & value;
    RAM8(0x0000 + sp0 - 1) = x;
    uint16_t value2 = RAM16(0x0000 + (uint16_t)(((((a_all >> 8 << 8 | (((uint8_t)a_all ^ 0xFF) & value)) & 6) << 8) | 0) + 0xE000));
    uint16_t value3 = RAM16(0x0190 + (uint16_t)(((((a_all >> 8 << 8 | (((uint8_t)a_all ^ 0xFF) & value)) & 6) << 8) | 0) + 0xE000));
    RAM16_SET(0x1820, value3 & 0x8000);
    if ((uint8_t)value2 != 1) {
        r->a = ((value3 & 0x8000) >> 8 << 8) | 0;
        r->y = (uint8_t)value2;
        r->c = (uint8_t)value2 >= 1;
        r->z = 1;
        r->v = ((((((a_all >> 8 << 8 | (((uint8_t)a_all ^ 0xFF) & value)) & 6) << 8) | 0) ^ (uint16_t)(((((a_all >> 8 << 8 | (((uint8_t)a_all ^ 0xFF) & value)) & 6) << 8) | 0) + 0xE000)) & ((uint16_t)(((((a_all >> 8 << 8 | (((uint8_t)a_all ^ 0xFF) & value)) & 6) << 8) | 0) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 1;
        RETURN_RTS(c);
    }
    uint8_t value4 = RAM8(0x1821);
    if (value4 != 0) {
        r->a = ((value3 & 0x8000) >> 8 << 8) | 0;
        r->y = value4;
        r->c = value4 >= 0;
        r->z = 1;
        r->v = ((((((a_all >> 8 << 8 | (((uint8_t)a_all ^ 0xFF) & value)) & 6) << 8) | 0) ^ (uint16_t)(((((a_all >> 8 << 8 | (((uint8_t)a_all ^ 0xFF) & value)) & 6) << 8) | 0) + 0xE000)) & ((uint16_t)(((((a_all >> 8 << 8 | (((uint8_t)a_all ^ 0xFF) & value)) & 6) << 8) | 0) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 1;
        RETURN_RTS(c);
    }
    r->a = (value3 & 0x8000) >> 8 << 8 | (((uint8_t)a_all ^ 0xFF) & value);
    r->y = value4;
    r->c = value4 >= 0;
    r->z = (((uint8_t)a_all ^ 0xFF) & value) == 0;
    r->v = ((((((a_all >> 8 << 8 | (((uint8_t)a_all ^ 0xFF) & value)) & 6) << 8) | 0) ^ (uint16_t)(((((a_all >> 8 << 8 | (((uint8_t)a_all ^ 0xFF) & value)) & 6) << 8) | 0) + 0xE000)) & ((uint16_t)(((((a_all >> 8 << 8 | (((uint8_t)a_all ^ 0xFF) & value)) & 6) << 8) | 0) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06B0A, SOM_RTS, "gen", test_available_living_menu_actor_mask, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 2, 1, 1, 60, 29)
