.setcpu "65816"
.segment "CODE"
.org $2877
map_control_0d2877:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
