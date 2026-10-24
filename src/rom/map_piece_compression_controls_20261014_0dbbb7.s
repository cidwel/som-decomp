.setcpu "65816"
.segment "CODE"
.org $BBB7
map_control_0dbbb7:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
