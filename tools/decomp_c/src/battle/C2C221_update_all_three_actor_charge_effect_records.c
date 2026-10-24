#include "som_c.h"

/* C2C221 update_all_three_actor_charge_effect_records   [class B, 75 bytes, 40 instructions]
 * Source: src/rom/update_all_three_actor_charge_effect_records.s
 * Documented in docs/actor-charge-effect-update.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void update_all_three_actor_charge_effect_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    if ((RAM8(0xD000 + (x >> 3)) | RAM8(0xD010 + (x >> 3)) | RAM8(0xD020 + (x >> 3))) == 0) {
        RAM8(0xE061 + x) = 0;
        RAM8(ACTOR_CHARGE_STAGE + x) = 0;
        uint8_t value4 = RAM8(ACTOR_AGILITY + x);
        RAM8(ACTOR_WEAPON_GAUGE + x) = ((uint8_t)(0x64 - value4) >> 1) + 0x32;
        r->a = (r->a & 0x00FF) | ((x >> 3 >> 8) << 8);
        r->y = x >> 3;
        r->c = ((uint8_t)(0x64 - value4) >> 1) + 0x32 > 0xFF;
        r->v = ((((uint8_t)(0x64 - value4) >> 1) ^ ((uint8_t)(0x64 - value4) >> 1) + 0x32) & (((uint8_t)(0x64 - value4) >> 1) + 0x32 ^ 0x32) & 0x80) != 0;
        RETURN_RTL(c);
    }
    if (!(RAM8(0xE060 + x) & 0x80)) {
        r->a = (x >> 3) + 0x10;
        r->y = x >> 3;
        r->c = (x >> 3) + 0x10 > 0xFFFF;
        r->v = (((x >> 3) ^ (x >> 3) + 0x10) & ((x >> 3) + 0x10 ^ 0x10) & 0x8000) != 0;
        r->mf = 0;
        r->sp -= 2;
        JSR(c, 0xC258, 0xC2C26C); /* advance_charge_effect_phase_motion_and_terrain_collision */
        r->sp += 2;
        r->a = (x >> 3) + 0x20;
        r->y = (x >> 3) + 0x10;
        r->c = (x >> 3) + 0x20 > 0xFFFF;
        r->v = (((x >> 3) + 0x10 ^ (x >> 3) + 0x20) & ((x >> 3) + 0x20 ^ 0x10) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 2;
        JSR(c, 0xC264, 0xC2C26C); /* advance_charge_effect_phase_motion_and_terrain_collision */
        r->sp += 2;
        r->y = (x >> 3) + 0x20;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0xC26A, 0xC2C26C); /* advance_charge_effect_phase_motion_and_terrain_collision */
        RETURN_RTL(c);
    }
    RAM8(0xE061 + x) = 0;
    RAM8(ACTOR_CHARGE_STAGE + x) = 0;
    uint8_t value6 = RAM8(ACTOR_AGILITY + x);
    RAM8(ACTOR_WEAPON_GAUGE + x) = ((uint8_t)(0x64 - value6) >> 1) + 0x32;
    r->a = (r->a & 0x00FF) | ((x >> 3 >> 8) << 8);
    r->y = x >> 3;
    r->c = ((uint8_t)(0x64 - value6) >> 1) + 0x32 > 0xFF;
    r->v = ((((uint8_t)(0x64 - value6) >> 1) ^ ((uint8_t)(0x64 - value6) >> 1) + 0x32) & (((uint8_t)(0x64 - value6) >> 1) + 0x32 ^ 0x32) & 0x80) != 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2C221, SOM_RTL, "gen", update_all_three_actor_charge_effect_records, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 75, 40)
