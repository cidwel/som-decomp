.setcpu "65816"
.segment "CODE"
.org $2F02
map_control_0d2f02:
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
