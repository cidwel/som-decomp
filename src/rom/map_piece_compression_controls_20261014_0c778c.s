.setcpu "65816"
.segment "CODE"
.org $778C
map_control_0c778c:
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
