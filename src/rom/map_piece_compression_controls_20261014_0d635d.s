.setcpu "65816"
.segment "CODE"
.org $635D
map_control_0d635d:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
