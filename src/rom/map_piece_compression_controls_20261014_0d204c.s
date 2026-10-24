.setcpu "65816"
.segment "CODE"
.org $204C
map_control_0d204c:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
