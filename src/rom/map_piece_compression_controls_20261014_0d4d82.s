.setcpu "65816"
.segment "CODE"
.org $4D82
map_control_0d4d82:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
