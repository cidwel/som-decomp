.setcpu "65816"
.segment "CODE"
.org $B89D
map_control_0eb89d:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
