.setcpu "65816"
.segment "CODE"
.org $9D84
map_control_0e9d84:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
