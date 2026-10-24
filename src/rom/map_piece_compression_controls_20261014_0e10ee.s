.setcpu "65816"
.segment "CODE"
.org $10EE
map_control_0e10ee:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
