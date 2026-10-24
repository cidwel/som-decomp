.setcpu "65816"
.segment "CODE"
.org $9710
map_control_0d9710:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
