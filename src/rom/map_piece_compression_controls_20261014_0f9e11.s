.setcpu "65816"
.segment "CODE"
.org $9E11
map_control_0f9e11:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
