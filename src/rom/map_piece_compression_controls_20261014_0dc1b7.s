.setcpu "65816"
.segment "CODE"
.org $C1B7
map_control_0dc1b7:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
