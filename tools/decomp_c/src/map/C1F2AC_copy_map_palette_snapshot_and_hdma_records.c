#include "som_c.h"

/* C1F2AC copy_map_palette_snapshot_and_hdma_records   [class B, 61 bytes, 23 instructions]
 * Source: src/rom/copy_map_palette_snapshot_and_hdma_records.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=any D=$0000.  Callers read: BXYCV.
 */
static void copy_map_palette_snapshot_and_hdma_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t db = r->db;
    uint16_t value = BUS16(c, (db << 0x10) + 0x0602);
    BUS16_SET(c, (db << 0x10) + 0xDE02, value);
    uint16_t value2 = BUS16(c, (db << 0x10) + 0x0604);
    BUS16_SET(c, (db << 0x10) + 0xDE04, value2);
    uint16_t value3 = BUS16(c, (db << 0x10) + 0x0606);
    BUS16_SET(c, (db << 0x10) + 0xDE06, value3);
    uint16_t value4 = BUS16(c, (db << 0x10) + 0x0608);
    BUS16_SET(c, (db << 0x10) + 0xDE08, value4);
    uint16_t value5 = BUS16(c, (db << 0x10) + 0x060A);
    BUS16_SET(c, (db << 0x10) + 0xDE0A, value5);
    uint16_t value6 = BUS16(c, (db << 0x10) + 0x060C);
    BUS16_SET(c, (db << 0x10) + 0xDE0C, value6);
    uint16_t value7 = BUS16(c, (db << 0x10) + 0x060E);
    BUS16_SET(c, (db << 0x10) + 0xDE0E, value7);
    r->a = 0x27;
    r->x = 0xF3C9;
    r->y = 0x05D0;
    r->mf = 0;
    i_mvn(c, 0x01, 0x7E); /* copy up bank $01 to bank $7E */
    r->db = db;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F2AC, SOM_RTS, "gen", copy_map_palette_snapshot_and_hdma_records, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 61, 23)
