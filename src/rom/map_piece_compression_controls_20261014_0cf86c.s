.setcpu "65816"
.segment "CODE"
.org $F86C
map_control_0cf86c:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
