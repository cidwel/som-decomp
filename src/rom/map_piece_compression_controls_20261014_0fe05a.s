.setcpu "65816"
.segment "CODE"
.org $E05A
map_control_0fe05a:
    .byte $E9 ; backreference distance high bits
    .byte $12 ; distance low bit/count
