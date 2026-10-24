.setcpu "65816"
.segment "CODE"
.org $BD7A
map_control_0dbd7a:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
