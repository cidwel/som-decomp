.setcpu "65816"
.segment "CODE"
.org $AC02
map_control_0dac02:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
