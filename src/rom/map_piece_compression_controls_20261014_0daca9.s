.setcpu "65816"
.segment "CODE"
.org $ACA9
map_control_0daca9:
    .byte $E8 ; backreference distance high bits
    .byte $37 ; distance low bit/count
