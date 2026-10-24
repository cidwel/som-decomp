.setcpu "65816"
.segment "CODE"
.org $6E5D
map_control_0d6e5d:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
