#include "som_c.h"

/* C0281E construct_native_menu_graphics_and_install_nmi_vector   [class D, 136 bytes, 48 instructions]
 * Source: src/rom/construct_native_menu_graphics_and_install_nmi_vector.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BCV.
 */
static void construct_native_menu_graphics_and_install_nmi_vector(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x0000 + sp0) = a;
    RAM8(0x0000 + sp0 - 1) = 0x7E;
    BUS8_SET(c, 0x004200, 1);
    BUS8_SET(c, 0x00420C, 0);
    RAM8(0xA20B) = 0;
    RAM8(0xA20A) = 0;
    RAM8(0xA211) = 0;
    RAM8(0xA17B) = 0;
    RAM8(0x1D05) = 5;
    RAM8(0x1D04) = 0;
    RAM8(0x1D12) = 0;
    RAM8(0x1D00) = 0;
    RAM8(0xA212) |= 0x10;
    BUS8_SET(c, 0x002100, 0x80);
    BUS8_SET(c, 0x002115, 0x80);
    r->a = (a_hi << 8) | 0x80;
    r->z = 0;
    r->n = 1;
    r->db = 0x7E;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2860, 0xC01F97); GUARD_JSR(c, sp_call, 0x2860); } /* initialize_native_menu_frame_tiles_and_palette */
    r->sp += 1;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2863, 0xC027E0); GUARD_JSR(c, sp_call, 0x2863); } /* configure_native_menu_background_and_scroll_ports */
    r->sp += 1;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2866, 0xC021BE); GUARD_JSR(c, sp_call, 0x2866); } /* seed_native_menu_grid_from_actual_rom */
    r->sp += 1;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2869, 0xC02169); GUARD_JSR(c, sp_call, 0x2869); } /* expand_native_menu_glyph_grid_to_two_bitplanes */
    r->sp += 1;
    if (r->xf != 0) { c->fail = 3; return; }
    RAM16_SET(0xA191, 0x0420);
    RAM16_SET(0xA18C, 0x6000);
    r->x = 0x6000;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2878, 0xC023BA); GUARD_JSR(c, sp_call, 0x2878); } /* upload_native_menu_assembled_text_tiles */
    r->sp += 1;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x287B, 0xC02010); GUARD_JSR(c, sp_call, 0x287B); } /* upload_native_menu_actor_tiles_and_palette */
    r->sp += 1;
    uint16_t a_all6 = r->a;
    uint8_t value2 = RAM8(0x0000 + sp0);
    r->a = (a_all6 >> 8 << 8) | value2;
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x287F, 0xC020E4); GUARD_JSR(c, sp_call, 0x287F); } /* initialize_native_menu_page_palette */
    RAM16_SET(0xA21D, RAM16(0x0102));
    RAM16_SET(0xA21B, RAM16(0x0100));
    RAM16_SET(0x0101, 0x20A7);
    RAM8(0x0103) = 0xC0;
    RAM8(0x0100) = 0x5C;
    r->a = (r->a & 0x00FF) | (0x20 << 8);
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0281E, SOM_RTS, "gen", construct_native_menu_graphics_and_install_nmi_vector, 0, L_B | L_C | L_V, 2, 1, 0, 136, 48)
