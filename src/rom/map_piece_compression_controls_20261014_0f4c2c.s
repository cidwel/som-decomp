.setcpu "65816"
.segment "CODE"
.org $4C2C
map_control_0f4c2c:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
