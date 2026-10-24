#include "som_c.h"

static void upload_menu_title_dma_tail(SomCtx *c);

/* C01D52 upload_menu_title_and_padding   [class D, 69 bytes, 25 instructions]
 * Source: src/rom/upload_menu_title_and_padding.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: nothing.
 */
static void upload_menu_title_and_padding(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0x1D11) &= 0xFB;
    BUS16_SET(c, 0x002116, 0x7440);
    BUS8_SET(c, 0x004370, 1);
    BUS16_SET(c, 0x004372, 0x9400);
    { const uint16_t sp_call = r->sp; JSR_LOCAL(c, 0x1D6F, upload_menu_title_dma_tail); GUARD_JSR(c, sp_call, 0x1D6F); }
    uint8_t db_ret = r->db;
    BUS16_SET(c, (db_ret << 0x10) + 0x2116, 0x7540);
    BUS8_SET(c, (db_ret << 0x10) + 0x4370, 9);
    BUS16_SET(c, (db_ret << 0x10) + 0x4372, 0x9500);
    BUS16_SET(c, (db_ret << 0x10) + 0x4375, 0x0100);
    BUS8_SET(c, (db_ret << 0x10) + 0x4371, 0x18);
    BUS8_SET(c, (db_ret << 0x10) + 0x4374, 0x7E);
    BUS8_SET(c, (db_ret << 0x10) + 0x420B, 0x80);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01D52, SOM_RTS, "gen", upload_menu_title_and_padding, 0, 0, 1, 1, 0, 69, 25)

/* C01D81 upload_menu_title_dma_tail   [class A, 22 bytes, 9 instructions]
 * Source: src/rom/upload_menu_title_and_padding.s
 * Subroutine of upload_menu_title_and_padding, translated in place.
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void upload_menu_title_dma_tail(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    BUS16_SET(c, 0x004375, 0x0100);
    BUS8_SET(c, 0x004371, 0x18);
    BUS8_SET(c, 0x004374, 0x7E);
    BUS8_SET(c, 0x00420B, 0x80);
    SET_A8(r, 0x80);
    r->x = 0x0100;
    r->z = 0;
    r->n = 1;
    RETURN_RTS(c);
}
