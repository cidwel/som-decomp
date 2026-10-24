.setcpu "65816"
.segment "CODE"
.org $1898
map_control_0d1898:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
