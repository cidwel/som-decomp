.setcpu "65816"
.segment "CODE"
.org $55C6
map_control_0f55c6:
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
