.setcpu "65816"
.segment "CODE"
.org $CE57
map_control_0ece57:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
