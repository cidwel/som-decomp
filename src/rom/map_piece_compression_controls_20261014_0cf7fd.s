.setcpu "65816"
.segment "CODE"
.org $F7FD
map_control_0cf7fd:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
