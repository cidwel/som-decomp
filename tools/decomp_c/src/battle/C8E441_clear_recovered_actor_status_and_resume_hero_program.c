#include "som_c.h"

/* C8E441 clear_recovered_actor_status_and_resume_hero_program   [class B, 70 bytes, 34 instructions]
 * Source: src/rom/clear_recovered_actor_status_and_resume_hero_program.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: XY.
 */
static void clear_recovered_actor_status_and_resume_hero_program(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM16_SET(0x0398, 0);
    RAM16_SET(ACTOR_STATUS + x, 0);
    RAM16_SET(0x03B0, 0);
    RAM16_SET(ACTOR_PENDING_HP_DAMAGE + x, 0);
    RAM16_SET(ACTOR_PENDING_MP_DAMAGE + x, 0);
    if (RAM8(ACTOR_KIND_FLAGS + x) & 0x80) {
        uint8_t value2 = RAM8(0x0381);
        uint8_t a1;
        if ((uint8_t)(value2 + 1) != 3) {
            a1 = (uint8_t)(value2 + 1);
        } else {
            a1 = (uint8_t)(value2 + 2);
        }
        RAM8(BATTLE_TEMP_AC) = a1;
        uint8_t battle_temp_ac = RAM8(BATTLE_TEMP_AC);
        uint16_t x3;
        uint16_t y3;
        if (battle_temp_ac == 1) {
            x3 = x;
            y3 = y;
        } else {
            uint16_t x2;
            uint16_t y2;
            if (battle_temp_ac == 2) {
                x2 = x;
                y2 = y;
            } else {
                uint16_t x1;
                uint16_t y1;
                if (battle_temp_ac == 3) {
                    x1 = x;
                    y1 = y;
                } else {
                    r->a = (uint8_t)(value2 + 0x80);
                    r->c = value2 + 0x80 > 0xFF;
                    r->z = (uint8_t)(value2 + 0x80) == 0;
                    r->n = (uint8_t)(value2 + 0x80) & 0x80;
                    r->v = ((value2 ^ (uint8_t)(value2 + 0x80)) & ((uint8_t)(value2 + 0x80) ^ 0x80) & 0x80) != 0;
                    r->mf = 1;
                    JSL(c, 0xE483, 0xC10020); /* set_actor_program_long */
                    uint16_t y_ret = r->y;
                    x1 = RAM16(BATTLE_DEFENDER_PTR);
                    y1 = y_ret;
                }
                x2 = x1;
                y2 = y1;
            }
            x3 = x2;
            y3 = y2;
        }
        r->x = x3;
        r->y = y3;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8E441, SOM_RTS, "gen", clear_recovered_actor_status_and_resume_hero_program, 0, L_X | L_Y, 1, 0, 0, 70, 34)
