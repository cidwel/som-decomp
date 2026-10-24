.setcpu "65816"
.segment "CODE"
.org $C6FD
map_control_0ec6fd:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
