.setcpu "65816"
.segment "CODE"
.org $9FBC
map_control_0d9fbc:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
