.setcpu "65816"
.segment "CODE"
.org $AC63
map_control_0dac63:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
