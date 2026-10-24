.setcpu "65816"
.segment "CODE"
.org $9C36
map_control_0d9c36:
    .byte $E8 ; backreference distance high bits
    .byte $96 ; distance low bit/count
