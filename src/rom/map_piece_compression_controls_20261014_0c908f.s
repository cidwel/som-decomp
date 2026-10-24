.setcpu "65816"
.segment "CODE"
.org $908F
map_control_0c908f:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
