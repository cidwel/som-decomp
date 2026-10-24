.setcpu "65816"
.segment "CODE"
.org $E3F4
map_control_0fe3f4:
    .byte $E8 ; backreference distance high bits
    .byte $4C ; distance low bit/count
