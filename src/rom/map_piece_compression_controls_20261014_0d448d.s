.setcpu "65816"
.segment "CODE"
.org $448D
map_control_0d448d:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
