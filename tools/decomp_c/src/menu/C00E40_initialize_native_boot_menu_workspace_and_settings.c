#include "som_c.h"

/* C00E40 initialize_native_boot_menu_workspace_and_settings   [class B, 77 bytes, 40 instructions]
 * Source: src/rom/initialize_native_boot_menu_workspace_and_settings.s
 * Documented in docs/ui-native-boot-menu-workspace.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
#define ABSX(off) ((((uint32_t)r->db << 16) + (off) + r->x) & 0xFFFFFF)
#define ABS(off) ((((uint32_t)r->db << 16) + (off)) & 0xFFFFFF)

static void initialize_native_boot_menu_workspace_and_settings(SomCtx *c)
{
    Cpu *r = &c->cpu;
    i_php(c);
    i_sep(r, 0x20);
    i_rep(r, 0x10);
    i_phb(c);
    a_lda(r, 0x00);
    i_pha(c);
    i_plb(c);
    a_lda(r, 0x30);
    a_lda(r, 0x00);
    do {                                   /* clear 256 bytes from $1D00+X */
        BUS8_SET(c, ABSX(0x1D00), 0);
        i_inx(r);
        i_deca(r);
    } while (!r->z);
    a_lda(r, 0x01);
    BUS8_SET(c, ABS(0x1D1A), r->a);
    a_lda(r, 0x7E);
    i_pha(c);
    i_plb(c);
    a_ldy(r, 0x1260);
    a_ldx(r, 0x0000);
    do {                                   /* clear $1260 bytes of the settings workspace */
        BUS8_SET(c, ABSX(0x9000), 0);
        i_inx(r);
        i_dey(r);
    } while (!r->z);
    { const uint16_t sp_call = r->sp; JSR(c, 0x0E6D, 0xC00E8D); GUARD_JSR_DB(c, sp_call, 0x0E6D, 0x7E); } /* load_eight_native_boot_settings_presets_from_real_tables */
    if (!r->mf || r->xf) { c->fail = 3; return; }   /* the code below is assembled for an 8-bit accumulator and 16-bit index */
    a_ldx(r, 0x9C00);
    BUS16_SET(c, ABS(0xA19B), r->x);
    a_lda(r, 0x01);
    BUS8_SET(c, ABS(0xA1C6), r->a);
    a_lda(r, 0x06);
    BUS8_SET(c, ABS(0xA161), r->a);
    a_ldx(r, 0x0008);
    a_lda(r, 0x07);
    do {
        BUS8_SET(c, ABSX(0xA24E), r->a);
        i_deca(r);
        i_dex(r);
    } while (!r->z);
    i_plb(c);
    hand_plp(c);
    RETURN_RTL(c);
}
SOM_REGISTER(0xC00E40, SOM_RTL, "hand", initialize_native_boot_menu_workspace_and_settings, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 1, 0, 77, 40)
