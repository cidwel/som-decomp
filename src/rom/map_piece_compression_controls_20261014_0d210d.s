.setcpu "65816"
.segment "CODE"
.org $210D
map_control_0d210d:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
