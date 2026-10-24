.setcpu "65816"
.segment "CODE"
.org $3DB4
map_control_0d3db4:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
