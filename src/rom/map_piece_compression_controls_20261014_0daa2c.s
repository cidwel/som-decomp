.setcpu "65816"
.segment "CODE"
.org $AA2C
map_control_0daa2c:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
