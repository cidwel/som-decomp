#include "som_c.h"

/* C05907 publish_existing_chest_class_notice   [class A, 26 bytes, 13 instructions]
 * Source: src/rom/publish_existing_chest_class_notice.s
 * Documented in docs/event-vm-chest-reward.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void publish_existing_chest_class_notice(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x5909, 0xC05D08); GUARD_JSR(c, sp_call, 0x5909); } /* allocate_reverse_combat_message_slot */
    uint8_t value = RAM8(0xE1C8 + RAM16(BATTLE_DEFENDER_PTR));
    uint16_t value2 = BUS16(c, 0xC05DEB + (uint8_t)(value << 1));
    r->a = value2;
    r->x = value2;
    r->c = value & 0x80;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x591F, 0xC05C2A); GUARD_JSR(c, sp_call, 0x591F); } /* append_rom_message_text */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC05907, SOM_RTL, "gen", publish_existing_chest_class_notice, 0, 0, 1, 1, 0, 26, 13)
