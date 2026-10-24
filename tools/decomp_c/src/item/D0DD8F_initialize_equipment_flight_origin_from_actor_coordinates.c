#include "som_c.h"

/* D0DD8F initialize_equipment_flight_origin_from_actor_coordinates   [class A, 33 bytes, 14 instructions]
 * Source: src/rom/initialize_equipment_flight_origin_from_actor_coordinates.s
 * Documented in docs/event-menu-equipment-flight.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: BYCV.
 */
static void initialize_equipment_flight_origin_from_actor_coordinates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    BUS8_SET(c, (db << 0x10) + y, (uint8_t)(RAM8(0xE020 + x) - 8));
    uint8_t value2 = RAM8(0xE022 + x);
    BUS8_SET(c, (db << 0x10) + 1 + y, (uint8_t)(value2 - 0x18));
    BUS8_SET(c, (db << 0x10) + 2 + y, 0);
    BUS8_SET(c, (db << 0x10) + 3 + y, 0x50);
    r->c = value2 >= 0x18;
    r->v = ((value2 ^ 0x18) & (value2 ^ (uint8_t)(value2 - 0x18)) & 0x80) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0DD8F, SOM_RTS, "gen", initialize_equipment_flight_origin_from_actor_coordinates, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 33, 14)
