#include "som_c.h"

/* C8E855 select_caster_magic_stat_and_power   [class A, 57 bytes, 27 instructions]
 * Source: src/rom/select_caster_magic_stat_and_power.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYV.
 */
static void select_caster_magic_stat_and_power(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    BUS8_SET(c, 0x004204, RAM8(0xE170 + y));
    BUS8_SET(c, 0x004205, 0);
    BUS8_SET(c, 0x004206, 6);
    uint8_t value2 = BUS8(c, 0x004216);
    if (value2 < 3) {
        RAM8(0x0391) = RAM8(ACTOR_INTELLIGENCE + y);
        RAM8(0x0396) = RAM8(0xE1FD + y);
        RETURN_RTS(c);
    }
    RAM8(0x0396) = RAM8(0xE1FE + y);
    RAM8(0x0391) = RAM8(ACTOR_WISDOM + y);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8E855, SOM_RTS, "gen", select_caster_magic_stat_and_power, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 57, 27)
