.setcpu "65816"
.segment "CODE"
.org $3C12
map_control_0f3c12:
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
