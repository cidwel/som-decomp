#include "som_c.h"

/* C058DB publish_successful_chest_inventory_notice   [class A, 22 bytes, 10 instructions]
 * Source: src/rom/publish_successful_chest_inventory_notice.s
 * Documented in docs/event-vm-chest-reward.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void publish_successful_chest_inventory_notice(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x58DD, 0xC05CCF); GUARD_JSR(c, sp_call, 0x58DD); } /* allocate_message_queue_line */
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    RAM8(0xFE00 + y_ret) = 0x55;
    uint8_t battle_temp_a6 = RAM8(BATTLE_TEMP_A6);
    RAM8(0xFE00 + (uint16_t)(y_ret + 1)) = battle_temp_a6;
    r->a = (a_all >> 8 << 8) | battle_temp_a6;
    r->x = 0x62A0;
    r->y = (uint16_t)(y_ret + 2);
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x58EF, 0xC05C2A); GUARD_JSR(c, sp_call, 0x58EF); } /* append_rom_message_text */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC058DB, SOM_RTL, "gen", publish_successful_chest_inventory_notice, 0, 0, 1, 1, 0, 22, 10)
