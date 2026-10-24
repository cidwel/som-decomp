.setcpu "65816"
.segment "CODE"
.org $9C33
map_control_0d9c33:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
