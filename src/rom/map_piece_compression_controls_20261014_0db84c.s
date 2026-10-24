.setcpu "65816"
.segment "CODE"
.org $B84C
map_control_0db84c:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
