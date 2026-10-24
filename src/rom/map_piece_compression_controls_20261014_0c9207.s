.setcpu "65816"
.segment "CODE"
.org $9207
map_control_0c9207:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
