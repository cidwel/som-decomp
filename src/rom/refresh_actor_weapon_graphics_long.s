; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

refresh_object_weapon_graphics_and_palette = $EA19

.segment "CODE"
.org $E9F4
refresh_actor_weapon_graphics_long:
    jsr refresh_object_weapon_graphics_and_palette
    rtl
