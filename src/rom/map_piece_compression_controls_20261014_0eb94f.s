.setcpu "65816"
.segment "CODE"
.org $B94F
map_control_0eb94f:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
