.setcpu "65816"
.segment "CODE"
.org $CE62
map_control_0ece62:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
