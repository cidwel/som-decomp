#include "som_c.h"

/* C05AFD queue_cast_spell_level_message   [class B, 35 bytes, 15 instructions]
 * Source: src/rom/queue_cast_spell_level_message.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXY.
 */
static void queue_cast_spell_level_message(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    JSR(c, 0x5AFF, 0xC05D08); /* allocate_reverse_combat_message_slot */
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    RAM8(0xFE00 + y_ret) = 0x56;
    uint8_t value = RAM8(0xE170 + RAM16(BATTLE_ATTACKER_PTR));
    RAM8(0xFE00 + (uint16_t)(y_ret + 1)) = value;
    r->a = (a_all >> 8 << 8) | value;
    r->x = 0x6251;
    r->y = (uint16_t)(y_ret + 2);
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x5B14, 0xC05C2A); /* append_rom_message_text */
    uint16_t a_all2 = r->a;
    r->a = (a_all2 >> 8 << 8) | RAM8(0x039D);
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x5B19, 0xC05C38); /* append_message_byte_decimal */
    uint16_t y_ret3 = r->y;
    RAM8(0xFE00 + y_ret3) = 0;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC05AFD, SOM_RTL, "gen", queue_cast_spell_level_message, 0, L_B | L_X | L_Y, 1, 1, 0, 35, 15)
