.setcpu "65816"
.segment "CODE"
.org $1617
map_control_0d1617:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
