.setcpu "65816"
.segment "CODE"
.org $D02A
map_control_0ed02a:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
