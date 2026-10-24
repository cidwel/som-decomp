.setcpu "65816"
.segment "CODE"
.org $4610
map_control_0e4610:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
