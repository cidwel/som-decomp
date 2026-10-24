.setcpu "65816"
.segment "CODE"
.org $5761
map_control_0e5761:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
