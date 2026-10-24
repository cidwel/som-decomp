; Sparse typed weapon resource headers; pointed graphics/frame data excluded.
.setcpu "65816"
.segment "CODE"
.org $C018
.macro weapon_resource tile_unit_index, frame_index_near_pointer
    .word tile_unit_index, frame_index_near_pointer
.endmacro
weapon_resource_selector_06:
    weapon_resource $0130, $3BE2
