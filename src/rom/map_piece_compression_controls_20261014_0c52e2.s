.setcpu "65816"
.segment "CODE"
.org $52E2
map_control_0c52e2:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
