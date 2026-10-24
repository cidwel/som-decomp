; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_object_weapon_graphics_resources = $EA41

.segment "CODE"
.org $EA3D
prepare_object_weapon_graphics_resources_entry:
    jsr prepare_object_weapon_graphics_resources
    rtl
