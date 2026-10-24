.setcpu "65816"
.segment "CODE"
.org $7EF3
map_control_0f7ef3:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
