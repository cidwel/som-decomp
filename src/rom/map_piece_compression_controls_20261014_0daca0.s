.setcpu "65816"
.segment "CODE"
.org $ACA0
map_control_0daca0:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
