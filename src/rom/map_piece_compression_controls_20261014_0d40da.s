.setcpu "65816"
.segment "CODE"
.org $40DA
map_control_0d40da:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
