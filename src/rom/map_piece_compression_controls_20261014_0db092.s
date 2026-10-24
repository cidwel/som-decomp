.setcpu "65816"
.segment "CODE"
.org $B092
map_control_0db092:
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
