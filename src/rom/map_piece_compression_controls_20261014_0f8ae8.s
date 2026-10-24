.setcpu "65816"
.segment "CODE"
.org $8AE8
map_control_0f8ae8:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
