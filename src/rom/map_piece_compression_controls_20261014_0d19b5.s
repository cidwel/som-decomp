.setcpu "65816"
.segment "CODE"
.org $19B5
map_control_0d19b5:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
