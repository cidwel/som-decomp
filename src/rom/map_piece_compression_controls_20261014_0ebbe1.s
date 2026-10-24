.setcpu "65816"
.segment "CODE"
.org $BBE1
map_control_0ebbe1:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
