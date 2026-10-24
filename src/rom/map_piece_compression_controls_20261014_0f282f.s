.setcpu "65816"
.segment "CODE"
.org $282F
map_control_0f282f:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
