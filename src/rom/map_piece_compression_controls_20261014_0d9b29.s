.setcpu "65816"
.segment "CODE"
.org $9B29
map_control_0d9b29:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
