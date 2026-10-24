.setcpu "65816"
.segment "CODE"
.org $40B3
map_control_0d40b3:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
