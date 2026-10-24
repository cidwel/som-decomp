#include "som_c.h"

/* C1950D upload_complete_actor_frame_tiles   [class D, 59 bytes, 27 instructions]
 * Source: src/rom/upload_complete_actor_frame_tiles.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: CV.
 */
static void upload_complete_actor_frame_tiles(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    BUS8_SET(c, 0x004346, 0);
    BUS8_SET(c, 0x004356, 0);
    BUS8_SET(c, 0x004366, 0);
    BUS8_SET(c, 0x004376, 0);
    BUS16_SET(c, 0x004340, 0x1801);
    BUS16_SET(c, 0x004350, 0x1801);
    BUS16_SET(c, 0x004360, 0x1801);
    BUS16_SET(c, 0x004370, 0x1801);
    BUS8_SET(c, 0x002115, 0x80);
    uint16_t value = RAM16(0x0056);
    uint8_t value2 = RAM8(0x00ED);
    if (value2 != 0) {
        uint8_t value3 = RAM8(0x005C);
        if (!(value3 & 0x80)) {
            RAM8(0x0000 + sp0) = 0;
            RAM8(0x0000 + sp0 - 1) = 0;
            r->a = (uint16_t)(value << 1);
            r->x = (uint8_t)(value << 1);
            r->y = value3;
            r->c = value & 0x8000;
            r->z = value3 == 0;
            r->n = value3 & 0x80;
            r->mf = 0;
            r->dp = 0x4300;
            switch ((uint8_t)(value << 1)) {
            case 0x0000: TAIL_CALL_FRAME(c, 0xC19D7F, SOM_RTL, 2); /* upload_first_boss_normal_tiles */
            case 0x0002: TAIL_CALL_FRAME(c, 0xC1A185, SOM_RTL, 2); /* upload_second_boss_normal_tiles */
            case 0x0004: TAIL_CALL_FRAME(c, 0xC1A58B, SOM_RTL, 2); /* upload_third_boss_normal_tiles */
            case 0x0006: TAIL_CALL_FRAME(c, 0xC195BC, SOM_RTL, 2); /* upload_three_hero_normal_tile_tables */
            case 0x0008: TAIL_CALL_FRAME(c, 0xC199CB, SOM_RTL, 2); /* upload_second_hero_auxiliary_tiles */
            case 0x000A: TAIL_CALL_FRAME(c, 0xC19566, SOM_RTL, 2); /* select_first_boss_auxiliary_tiles */
            case 0x000C: TAIL_CALL_FRAME(c, 0xC1956D, SOM_RTL, 2); /* select_second_boss_auxiliary_tiles */
            case 0x000E: TAIL_CALL_FRAME(c, 0xC19574, SOM_RTL, 2); /* select_third_boss_auxiliary_tiles */
            case 0x0010: TAIL_CALL_FRAME(c, 0xC195BC, SOM_RTL, 2); /* upload_three_hero_normal_tile_tables */
            case 0x0012: TAIL_CALL_FRAME(c, 0xC199CB, SOM_RTL, 2); /* upload_second_hero_auxiliary_tiles */
            case 0x0014: TAIL_CALL_FRAME(c, 0xC1A991, SOM_RTL, 2); /* upload_low_monster_normal_tile_tables */
            case 0x0016: TAIL_CALL_FRAME(c, 0xC1ABC7, SOM_RTL, 2); /* upload_middle_monster_normal_tile_tables */
            case 0x0018: TAIL_CALL_FRAME(c, 0xC1ADFD, SOM_RTL, 2); /* upload_high_monster_normal_tile_tables */
            case 0x001A: TAIL_CALL_FRAME(c, 0xC195BC, SOM_RTL, 2); /* upload_three_hero_normal_tile_tables */
            case 0x001C: TAIL_CALL_FRAME(c, 0xC199CB, SOM_RTL, 2); /* upload_second_hero_auxiliary_tiles */
            default: TAIL_CALL_FRAME(c, 0xC10000 | BUS16(c, 0xC10000 + (uint16_t)(0x9548 + ((uint8_t)(value << 1)))), SOM_RTL, 2);
            }
        }
        RAM8(0x0000 + sp0) = 0;
        RAM8(0x0000 + sp0 - 1) = 0;
        r->a = (uint16_t)(value << 1);
        r->x = (uint8_t)(value << 1);
        r->y = value3;
        r->c = value & 0x8000;
        r->z = value3 == 0;
        r->n = value3 & 0x80;
        r->mf = 0;
        r->dp = 0x4300;
        switch ((uint8_t)(value << 1)) {
        case 0x0000: TAIL_CALL_FRAME(c, 0xC19566, SOM_RTL, 2); /* select_first_boss_auxiliary_tiles */
        case 0x0002: TAIL_CALL_FRAME(c, 0xC1956D, SOM_RTL, 2); /* select_second_boss_auxiliary_tiles */
        case 0x0004: TAIL_CALL_FRAME(c, 0xC19574, SOM_RTL, 2); /* select_third_boss_auxiliary_tiles */
        case 0x0006: TAIL_CALL_FRAME(c, 0xC195BC, SOM_RTL, 2); /* upload_three_hero_normal_tile_tables */
        case 0x0008: TAIL_CALL_FRAME(c, 0xC199CB, SOM_RTL, 2); /* upload_second_hero_auxiliary_tiles */
        case 0x000A: TAIL_CALL_FRAME(c, 0xC1A991, SOM_RTL, 2); /* upload_low_monster_normal_tile_tables */
        case 0x000C: TAIL_CALL_FRAME(c, 0xC1ABC7, SOM_RTL, 2); /* upload_middle_monster_normal_tile_tables */
        case 0x000E: TAIL_CALL_FRAME(c, 0xC1ADFD, SOM_RTL, 2); /* upload_high_monster_normal_tile_tables */
        case 0x0010: TAIL_CALL_FRAME(c, 0xC195BC, SOM_RTL, 2); /* upload_three_hero_normal_tile_tables */
        case 0x0012: TAIL_CALL_FRAME(c, 0xC199CB, SOM_RTL, 2); /* upload_second_hero_auxiliary_tiles */
        default: TAIL_CALL_FRAME(c, 0xC10000 | BUS16(c, 0xC10000 + (uint16_t)(0x9552 + ((uint8_t)(value << 1)))), SOM_RTL, 2);
        }
    }
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    r->a = (uint16_t)(value << 1);
    r->x = (uint8_t)(value << 1);
    r->y = value2;
    r->c = value & 0x8000;
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    r->mf = 0;
    r->dp = 0x4300;
    switch ((uint8_t)(value << 1)) {
    case 0x0000: TAIL_CALL_FRAME(c, 0xC1A991, SOM_RTL, 2); /* upload_low_monster_normal_tile_tables */
    case 0x0002: TAIL_CALL_FRAME(c, 0xC1ABC7, SOM_RTL, 2); /* upload_middle_monster_normal_tile_tables */
    case 0x0004: TAIL_CALL_FRAME(c, 0xC1ADFD, SOM_RTL, 2); /* upload_high_monster_normal_tile_tables */
    case 0x0006: TAIL_CALL_FRAME(c, 0xC195BC, SOM_RTL, 2); /* upload_three_hero_normal_tile_tables */
    case 0x0008: TAIL_CALL_FRAME(c, 0xC199CB, SOM_RTL, 2); /* upload_second_hero_auxiliary_tiles */
    default: TAIL_CALL_FRAME(c, 0xC10000 | BUS16(c, 0xC10000 + (uint16_t)(0x955C + ((uint8_t)(value << 1)))), SOM_RTL, 2);
    }
}
SOM_REGISTER(0xC1950D, SOM_RTL, "gen", upload_complete_actor_frame_tiles, 0, L_C | L_V, 2, 1, 1, 59, 27)
