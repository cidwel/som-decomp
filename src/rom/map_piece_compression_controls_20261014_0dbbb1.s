.setcpu "65816"
.segment "CODE"
.org $BBB1
map_control_0dbbb1:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
