.setcpu "65816"
.segment "CODE"
.org $272C
map_control_0d272c:
    .byte $E8 ; backreference distance high bits
    .byte $B1 ; distance low bit/count
