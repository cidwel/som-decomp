.setcpu "65816"
.segment "CODE"
.org $21B7
map_control_0e21b7:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
