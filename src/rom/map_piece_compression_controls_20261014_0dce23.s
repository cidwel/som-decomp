.setcpu "65816"
.segment "CODE"
.org $CE23
map_control_0dce23:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
