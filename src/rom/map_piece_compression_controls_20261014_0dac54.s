.setcpu "65816"
.segment "CODE"
.org $AC54
map_control_0dac54:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
