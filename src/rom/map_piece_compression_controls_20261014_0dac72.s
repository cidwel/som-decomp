.setcpu "65816"
.segment "CODE"
.org $AC72
map_control_0dac72:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
