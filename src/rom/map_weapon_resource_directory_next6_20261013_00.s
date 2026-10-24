; Sparse typed weapon resource headers; pointed graphics/frame data excluded.
.setcpu "65816"
.segment "CODE"
.org $C000
.macro weapon_resource tile_unit_index, frame_index_near_pointer
    .word tile_unit_index, frame_index_near_pointer
.endmacro
weapon_resource_selector_00:
    weapon_resource $0000, $3000
weapon_resource_selector_01:
    weapon_resource $0030, $31E2
