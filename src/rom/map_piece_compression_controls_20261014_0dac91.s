.setcpu "65816"
.segment "CODE"
.org $AC91
map_control_0dac91:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
