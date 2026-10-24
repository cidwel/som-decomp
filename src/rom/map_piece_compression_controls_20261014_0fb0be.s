.setcpu "65816"
.segment "CODE"
.org $B0BE
map_control_0fb0be:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
