.setcpu "65816"
.segment "CODE"
.org $641B
map_control_0c641b:
    .byte $E8 ; backreference distance high bits
    .byte $5D ; distance low bit/count
