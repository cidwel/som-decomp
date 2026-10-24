.setcpu "65816"
.segment "CODE"
.org $B899
map_control_0eb899:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
