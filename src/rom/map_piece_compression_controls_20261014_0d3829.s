.setcpu "65816"
.segment "CODE"
.org $3829
map_control_0d3829:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
