.setcpu "65816"
.segment "CODE"
.org $9162
map_control_0c9162:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
