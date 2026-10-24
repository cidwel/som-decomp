.setcpu "65816"
.segment "CODE"
.org $2610
map_control_0d2610:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
