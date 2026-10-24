.setcpu "65816"
.segment "CODE"
.org $42B3
map_control_0d42b3:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
