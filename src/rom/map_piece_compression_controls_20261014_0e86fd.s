.setcpu "65816"
.segment "CODE"
.org $86FD
map_control_0e86fd:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
