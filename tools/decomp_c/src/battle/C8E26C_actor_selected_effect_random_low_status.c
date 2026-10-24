#include "som_c.h"

/* C8E26C actor_selected_effect_random_low_status   [class B, 42 bytes, 18 instructions]
 * Source: src/rom/actor_selected_effect_random_low_status.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void actor_selected_effect_random_low_status(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSL(c, 0xE26F, 0xC0389C); GUARD_JSL(c, sp_call, 0xE26F); } /* random_byte_long_wrapper */
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    BUS8_SET(c, 0x004202, (uint8_t)a_all);
    BUS8_SET(c, 0x004203, 3);
    uint8_t value = BUS8(c, 0x004217);
    if (x_ret) {
        uint16_t value2 = BUS16(c, 0xC8E296 + (uint8_t)(value << 1));
        uint8_t battle_defender_ptr = RAM8(BATTLE_DEFENDER_PTR);
        uint16_t value3 = RAM16(ACTOR_STATUS + battle_defender_ptr);
        RAM16_SET(ACTOR_STATUS + battle_defender_ptr, value2 | value3);
        r->a = value2 | value3;
        r->x = battle_defender_ptr;
        r->y = (uint8_t)y_ret;
        r->c = value & 0x80;
        r->z = (value2 | value3) == 0;
        r->n = (value2 | value3) & 0x8000;
        r->xf = 1;
        RETURN_RTS(c);
    } else {
        uint16_t value4 = BUS16(c, 0xC8E296 + (uint8_t)(value << 1));
        uint16_t battle_defender_ptr2 = RAM16(BATTLE_DEFENDER_PTR);
        uint16_t value5 = RAM16(ACTOR_STATUS + battle_defender_ptr2);
        RAM16_SET(ACTOR_STATUS + battle_defender_ptr2, value4 | value5);
        r->a = value4 | value5;
        r->x = battle_defender_ptr2;
        r->c = value & 0x80;
        r->z = (value4 | value5) == 0;
        r->n = (value4 | value5) & 0x8000;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC8E26C, SOM_RTS, "gen", actor_selected_effect_random_low_status, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 42, 18)
