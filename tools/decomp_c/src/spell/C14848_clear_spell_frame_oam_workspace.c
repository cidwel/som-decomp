#include "som_c.h"

/* C14848 clear_spell_frame_oam_workspace   [class B, 74 bytes, 35 instructions]
 * Source: src/rom/clear_spell_frame_oam_workspace.s
 * Documented in docs/map-oam-spell-frames.md
 * Entry: M=8 bit X=16 bit DB=any D=$0000.  Callers read: BYCV.
 */
static void clear_spell_frame_oam_workspace(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = db;
    RAM8(0x0000 + sp0 - 6) = 0;
    RAM16_SET(0x0800, 0xF0F0);
    r->a = 0x5E;
    r->x = 0x0800;
    r->y = 0x0801;
    r->mf = 0;
    r->db = 0;
    r->dp = (uint16_t)(sp0 - 5);
    i_mvn(c, 0x00, 0x00); /* copy up bank $00 to bank $00 */
    RAM16_SET(0x0A00, 0);
    r->a = 4;
    r->x = 0x0A00;
    r->y = 0x0A01;
    i_mvn(c, 0x00, 0x00); /* copy up bank $00 to bank $00 */
    RAM16_SET(0x007C, 0x60);
    RAM16_SET(0x005A, 6);
    uint8_t value3 = RAM8(0x0000 + sp0 - 1);
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->a = (r->a & 0x00FF) | (0 << 8);
    r->mf = 1;
    r->db = db;
    r->dp = (value4 << 8) | value3;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC14848, SOM_RTS, "gen", clear_spell_frame_oam_workspace, 0, L_B | L_Y | L_C | L_V, 7, 1, 0, 74, 35)
