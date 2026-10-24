; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-effect-graphics.md.
.setcpu "65816"
.smart
.a8
.i16

load_actor_cast_secondary_graphics = $8634
load_object_weapon_palette_from_field_04f = $85D8

.segment "CODE"
.org $864D
load_actor_secondary_graphics_and_palette_long:
    jsr load_actor_cast_secondary_graphics
    jsr load_object_weapon_palette_from_field_04f
    rtl
