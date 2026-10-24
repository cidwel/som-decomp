#include "som_c.h"
#include "som_hand.h"

/* D3EE18 release_temporary_spell_sprite_object   [class B, 68 bytes, 39 instructions]
 * Source: src/rom/release_temporary_spell_sprite_object.s
 * Documented in docs/actor-cast-entity-sprite-objects.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 *
 * X points at a table of ten 8-byte records whose first word is the sprite instance id.  Each one is released through
 * C12E88, then the table owner (X) is released through C12E7C.  The routine keeps its variables in a frame it makes
 * the direct page: $01 records left, $03 table pointer X, $05 current record pointer.
 */
static void release_temporary_spell_sprite_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t frame = sp0 - 9;
    const uint16_t table = r->x;

    /* PHD, PHP, REP #$20, TSC, SEC, SBC #$0006, TCD, TCS, SEP #$20, PHB, LDA #$7E, PHA, PLB */
    RAM8(sp0) = r->dp >> 8;
    RAM8(sp0 - 1) = (uint8_t)r->dp;
    RAM8(sp0 - 2) = hand_p_byte(r);
    RAM8(frame) = r->db;
    RAM8(frame - 1) = 0x7E;
    r->db = 0x7E;
    r->dp = frame;
    r->sp = sp0 - 10;
    r->mf = 0;
    RAM16_SET(frame + 3, table);
    RAM16_SET(frame + 1, 10);

    uint16_t record = table;
    r->c = 0;
    r->v = 0;
    do {
        RAM16_SET(frame + 5, record);
        const uint32_t id_addr = ((uint32_t)r->db << 16) + record;
        if (!hand_rd_ok(id_addr) || !hand_rd_ok((id_addr + 1) & 0xFFFFFF)) { c->fail = 3; return; }
        const uint16_t id = BUS16(c, id_addr & 0xFFFFFF);
        r->a = record;
        r->x = id;
        r->y = record;
        r->z = id == 0;
        r->n = id & 0x8000;
        r->mf = 0;
        r->xf = 0;
        JSL(c, 0xEE41, 0xC12E88); /* release_spell_sprite_instance_long */
        if (r->mf || r->xf) { c->fail = 3; return; }
        record = (uint16_t)(RAM16(frame + 5) + 8);
        RAM16_SET(frame + 1, (uint16_t)(RAM16(frame + 1) - 1));
        r->c = RAM16(frame + 5) + 8 > 0xFFFF;
        r->v = (((RAM16(frame + 5) ^ record) & (record ^ 8)) & 0x8000) != 0;
    } while (RAM16(frame + 1) != 0);

    const uint16_t owner = RAM16(frame + 3);
    r->a = record;
    r->x = owner;
    r->z = owner == 0;
    r->n = owner & 0x8000;
    JSL(c, 0xEE51, 0xC12E7C); /* release_spell_entity_heap_bank_long */
    hand_plb(c);
    r->sp += 6;
    hand_plp(c);
    hand_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3EE18, SOM_RTS, "hand", release_temporary_spell_sprite_object, 0, 0, 11, 1, 0, 68, 39)
