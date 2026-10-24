.setcpu "65816"
.segment "CODE"
.org $4DBC
map_control_0f4dbc:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
