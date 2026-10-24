.setcpu "65816"
.segment "CODE"
.org $F30B
map_control_0ef30b:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
