; Hero status-produced numeric weapon metadata; no pointed payload.
.setcpu "65816"
.segment "CODE"
.org $C020
map_weapon_control_next9_20261013_status_resource_headers:
.macro weapon_resource tile_unit_index, frame_index_near_pointer
    .word tile_unit_index, frame_index_near_pointer
.endmacro
    weapon_resource $01B2, $3E08 ; status-produced selector 8
    weapon_resource $0553, $4050 ; status-produced selector 9
    weapon_resource $0553, $3E6A ; status-produced selector 10
    weapon_resource $01A0, $4036 ; status-produced selector 11
    weapon_resource $01A0, $3FDC ; status-produced selector 12
    weapon_resource $01FF, $4006 ; status-produced selector 13
    weapon_resource $0429, $3EE2 ; status-produced selector 14
    weapon_resource $0429, $3EBE ; status-produced selector 15
    weapon_resource $0429, $3E9A ; status-produced selector 16
