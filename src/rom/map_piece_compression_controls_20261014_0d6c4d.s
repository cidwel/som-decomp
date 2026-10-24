.setcpu "65816"
.segment "CODE"
.org $6C4D
map_control_0d6c4d:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
