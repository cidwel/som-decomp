#include "som_c.h"

/* CC0900 dispatch_seven_scrolling_dialogue_states   [class C, 29 bytes, 16 instructions]
 * Source: src/rom/dispatch_seven_scrolling_dialogue_states.s
 * Documented in docs/event-dialogue-scroll.md
 * Entry: M=8 bit X=16 bit DB=$CA D=$0000.  Callers read: BXY.
 */
static void dispatch_seven_scrolling_dialogue_states(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0xCA, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0xA170) = 0x7D;
    RAM8(0x1D11) = 1;
    uint8_t value = RAM8(0xA161);
    r->a = (uint8_t)(value << 1);
    r->x = (uint8_t)(value << 1);
    r->c = value & 0x80;
    r->z = (uint8_t)(value << 1) == 0;
    r->n = (uint8_t)(value << 1) & 0x8000;
    r->db = 0x7E;
    r->sp -= 1;
    switch ((uint8_t)(value << 1)) {
    case 0x0000: JSR(c, 0x091A, 0xCC091D); break; /* initialize_scrolling_dialogue_graphics_and_script */
    case 0x0002: JSR(c, 0x091A, 0xCC095C); break; /* clear_scrolling_dialogue_rows_and_initialize_registers */
    case 0x0004: JSR(c, 0x091A, 0xCC0997); break; /* parse_scrolling_dialogue_line_commands */
    case 0x0006: JSR(c, 0x091A, 0xCC0A2B); break; /* tick_scrolling_dialogue_line_delay */
    case 0x0008: JSR(c, 0x091A, 0xCC0A4D); break; /* tick_scrolling_dialogue_final_ring_clear */
    case 0x000A: JSR(c, 0x091A, 0xCC0A85); break; /* finish_scrolling_dialogue_register_state */
    case 0x000C: JSR(c, 0x091A, 0xCC0AA1); break; /* publish_scrolling_dialogue_sprite_graphics */
    case 0x000E: JSR(c, 0x091A, 0xCC09CD); break; /* set_scrolling_dialogue_line_indentation */
    case 0x0010: JSR(c, 0x091A, 0xCC09E2); break; /* reset_scrolling_dialogue_line_delay */
    case 0x0012: JSR(c, 0x091A, 0xCC09E8); break; /* begin_scrolling_dialogue_end_sequence */
    case 0x0014: JSR(c, 0x091A, 0xCC09F4); break; /* advance_scrolling_dialogue_line */
    case 0x0016: JSR(c, 0x091A, 0xCC09FA); break; /* write_scrolling_dialogue_character_tile */
    default: JSR(c, 0x091A, 0xCC0000 | BUS16(c, 0xCC0000 + (uint16_t)(0x0B61 + ((uint8_t)(value << 1)))));
    }
    r->sp += 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0xCA;
    RETURN_RTL(c);
}
SOM_REGISTER(0xCC0900, SOM_RTL, "gen", dispatch_seven_scrolling_dialogue_states, 0, L_B | L_X | L_Y, 2, 1, 0, 29, 16)
