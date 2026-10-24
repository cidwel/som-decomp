.setcpu "65816"
.segment "CODE"
.org $6B5D
map_control_0c6b5d:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
