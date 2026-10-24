.setcpu "65816"
.segment "CODE"
.org $C6E9
map_control_0ec6e9:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
