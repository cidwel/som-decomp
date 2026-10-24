.setcpu "65816"
.segment "CODE"
.org $72A6
map_control_0d72a6:
    .byte $E8 ; backreference distance high bits
    .byte $96 ; distance low bit/count
