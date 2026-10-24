.setcpu "65816"
.segment "CODE"
.org $314A
map_control_0d314a:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
