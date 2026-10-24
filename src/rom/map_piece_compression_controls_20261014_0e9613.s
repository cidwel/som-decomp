.setcpu "65816"
.segment "CODE"
.org $9613
map_control_0e9613:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
