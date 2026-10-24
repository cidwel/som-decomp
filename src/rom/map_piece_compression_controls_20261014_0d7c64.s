.setcpu "65816"
.segment "CODE"
.org $7C64
map_control_0d7c64:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
