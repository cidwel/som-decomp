.setcpu "65816"
.segment "CODE"
.org $C722
map_control_0ec722:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
