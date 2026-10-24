.setcpu "65816"
.segment "CODE"
.org $AC0D
map_control_0dac0d:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
