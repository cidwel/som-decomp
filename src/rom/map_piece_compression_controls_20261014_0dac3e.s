.setcpu "65816"
.segment "CODE"
.org $AC3E
map_control_0dac3e:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
