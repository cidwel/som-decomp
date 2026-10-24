.setcpu "65816"
.segment "CODE"
.org $7A62
map_control_0e7a62:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
