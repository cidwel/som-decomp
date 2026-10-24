.setcpu "65816"
.segment "CODE"
.org $81EB
map_control_0c81eb:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
