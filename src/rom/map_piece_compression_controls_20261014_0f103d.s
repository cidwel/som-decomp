.setcpu "65816"
.segment "CODE"
.org $103D
map_control_0f103d:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
