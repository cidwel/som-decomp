.setcpu "65816"
.segment "CODE"
.org $447C
map_control_0d447c:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
