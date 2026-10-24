.setcpu "65816"
.segment "CODE"
.org $3A0B
map_control_0f3a0b:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
