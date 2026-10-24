; Sparse typed weapon resource headers; pointed graphics/frame data excluded.
.setcpu "65816"
.segment "CODE"
.org $C05C
.macro weapon_resource tile_unit_index, frame_index_near_pointer
    .word tile_unit_index, frame_index_near_pointer
.endmacro
weapon_resource_selector_17:
    weapon_resource $0158, $3BE2
weapon_resource_selector_18:
    weapon_resource $00FF, $48C8
weapon_resource_selector_19:
    weapon_resource $01FF, $415C
weapon_resource_selector_1a:
    weapon_resource $01F6, $418E
weapon_resource_selector_1b:
    weapon_resource $01C2, $41F4
weapon_resource_selector_1c:
    weapon_resource $01FF, $4216
weapon_resource_selector_1d:
    weapon_resource $0336, $4230
weapon_resource_selector_1e:
    weapon_resource $01FF, $4264
