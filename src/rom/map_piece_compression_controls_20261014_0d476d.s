.setcpu "65816"
.segment "CODE"
.org $476D
map_control_0d476d:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
