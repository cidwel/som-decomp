.setcpu "65816"
.segment "CODE"
.org $B93C
map_control_0eb93c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
