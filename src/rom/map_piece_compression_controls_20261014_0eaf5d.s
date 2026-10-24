.setcpu "65816"
.segment "CODE"
.org $AF5D
map_control_0eaf5d:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
