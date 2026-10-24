.setcpu "65816"
.segment "CODE"
.org $22FD
map_control_0e22fd:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
