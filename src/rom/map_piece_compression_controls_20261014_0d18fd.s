.setcpu "65816"
.segment "CODE"
.org $18FD
map_control_0d18fd:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
