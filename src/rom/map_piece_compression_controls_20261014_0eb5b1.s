.setcpu "65816"
.segment "CODE"
.org $B5B1
map_control_0eb5b1:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
