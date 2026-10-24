.setcpu "65816"
.segment "CODE"
.org $9811
map_control_0e9811:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
