.setcpu "65816"
.segment "CODE"
.org $9685
map_control_0d9685:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
