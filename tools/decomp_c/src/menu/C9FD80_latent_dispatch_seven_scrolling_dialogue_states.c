#include "som_c.h"

/* C9FD80 latent_dispatch_seven_scrolling_dialogue_states   [class C, 29 bytes, 16 instructions]
 * Source: src/rom/latent_dispatch_seven_scrolling_dialogue_states.s
 * Documented in docs/source-recovery-parallel-latent-scroll-flow.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void latent_dispatch_seven_scrolling_dialogue_states(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    RAM8(0x0000 + sp0) = 0x7E;
    RAM8(0x0000 + sp0 - 1) = 0x7E;
    RAM8(0xA170) = 0x7D;
    RAM8(0x1D11) = 1;
    uint8_t value = RAM8(0xA161);
    r->a = (uint8_t)(value << 1);
    r->x = (uint8_t)(value << 1);
    r->c = value & 0x80;
    r->z = (uint8_t)(value << 1) == 0;
    r->n = (uint8_t)(value << 1) & 0x8000;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp;
    switch ((uint8_t)(value << 1)) {
    case 0x0000: JSR(c, 0xFD9A, 0xC9FD9D); GUARD_JSR(c, sp_call, 0xFD9A); break; /* latent_initialize_scrolling_dialogue_graphics_and_script */
    case 0x0002: JSR(c, 0xFD9A, 0xC9FDDC); GUARD_JSR(c, sp_call, 0xFD9A); break; /* latent_clear_scrolling_dialogue_rows_and_initialize_registers */
    case 0x0004: JSR(c, 0xFD9A, 0xC9FE17); GUARD_JSR(c, sp_call, 0xFD9A); break; /* latent_parse_scrolling_dialogue_line_commands */
    case 0x0006: JSR(c, 0xFD9A, 0xC9FEAB); GUARD_JSR(c, sp_call, 0xFD9A); break; /* latent_tick_scrolling_dialogue_line_delay */
    case 0x0008: JSR(c, 0xFD9A, 0xC9FECD); GUARD_JSR(c, sp_call, 0xFD9A); break; /* latent_tick_scrolling_dialogue_final_ring_clear */
    case 0x000A: JSR(c, 0xFD9A, 0xC9FF05); GUARD_JSR(c, sp_call, 0xFD9A); break; /* finish_latent_scrolling_dialogue_register_state */
    case 0x000C: JSR(c, 0xFD9A, 0xC9FF21); GUARD_JSR(c, sp_call, 0xFD9A); break; /* latent_publish_scrolling_dialogue_sprite_graphics */
    case 0x000E: JSR(c, 0xFD9A, 0xC9FE4D); GUARD_JSR(c, sp_call, 0xFD9A); break; /* set_latent_scrolling_dialogue_line_indentation */
    case 0x0010: JSR(c, 0xFD9A, 0xC9FE62); GUARD_JSR(c, sp_call, 0xFD9A); break; /* latent_reset_scrolling_dialogue_line_delay */
    case 0x0012: JSR(c, 0xFD9A, 0xC9FE68); GUARD_JSR(c, sp_call, 0xFD9A); break; /* latent_begin_scrolling_dialogue_end_sequence */
    case 0x0014: JSR(c, 0xFD9A, 0xC9FE74); GUARD_JSR(c, sp_call, 0xFD9A); break; /* latent_advance_scrolling_dialogue_line */
    case 0x0016: JSR(c, 0xFD9A, 0xC9FE7A); GUARD_JSR(c, sp_call, 0xFD9A); break; /* latent_write_scrolling_dialogue_character_tile */
    default: JSR(c, 0xFD9A, 0xC90000 | BUS16(c, 0xC90000 + (uint16_t)(0xFFE1 + ((uint8_t)(value << 1))))); GUARD_JSR(c, sp_call, 0xFD9A);
    }
    }
    r->sp += 1;
    uint8_t value2 = RAM8(0x0000 + sp0);
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    r->db = value2;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC9FD80, SOM_RTL, "gen", latent_dispatch_seven_scrolling_dialogue_states, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 29, 16)
