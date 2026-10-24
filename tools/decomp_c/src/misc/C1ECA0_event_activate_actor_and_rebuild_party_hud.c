#include "som_c.h"

/* C1ECA0 event_activate_actor_and_rebuild_party_hud   [class B, 97 bytes, 38 instructions]
 * Source: src/rom/event_activate_actor_and_rebuild_party_hud.s
 * Documented in docs/event-vm-party-actors.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void event_activate_actor_and_rebuild_party_hud(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value2 = RAM16(0x0004);
    RAM16_SET(0xE000 + ((value2 & 0x0F00) << 1), 1);
    uint16_t value3 = RAM16(0x003A);
    RAM16_SET(0xE002 + ((value2 & 0x0F00) << 1), RAM16(0xE002 + value3));
    RAM16_SET(0xE004 + ((value2 & 0x0F00) << 1), RAM16(0xE004 + value3));
    RAM16_SET(0xE006 + ((value2 & 0x0F00) << 1), 0);
    RAM16_SET(0xE008 + ((value2 & 0x0F00) << 1), 0);
    uint16_t value6 = RAM16(0x00D4);
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    RAM8(0xE00B + ((value2 & 0x0F00) << 1)) = RAM8(0xE00B + value6);
    RAM8(0xE08E + ((value2 & 0x0F00) << 1)) = RAM8(0xE08E + value6);
    RAM8(0xE04C + ((value2 & 0x0F00) << 1)) = RAM8(0xE04C + value6);
    uint8_t value10 = RAM8(0xE010 + value6);
    uint8_t a1;
    if (value10 < 2) {
        a1 = value10 ^ 1;
    } else {
        a1 = value10 ^ 0x80;
    }
    RAM8(0xE010 + ((value2 & 0x0F00) << 1)) = a1;
    RAM8(0xE030 + ((value2 & 0x0F00) << 1)) = 0xFF;
    uint8_t value11 = RAM8(0xE180 + ((value2 & 0x0F00) << 1));
    r->a = value11;
    r->x = (value2 & 0x0F00) << 1;
    r->y = value6;
    r->c = value10 >= 2;
    r->z = value11 == 0;
    r->n = value11 & 0x80;
    r->xf = 0;
    JSL(c, 0xECFD, 0xC10020); /* set_actor_program_long */
    r->mf = 1;
    r->xf = 0;
    TAIL_CALL(c, 0xC1E0DB, SOM_RTS); /* restore_party_hud_across_two_native_frames */
}
SOM_REGISTER(0xC1ECA0, SOM_RTS, "gen", event_activate_actor_and_rebuild_party_hud, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 97, 38)
