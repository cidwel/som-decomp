.setcpu "65816"
.segment "CODE"
.org $AC2C
map_control_0dac2c:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
