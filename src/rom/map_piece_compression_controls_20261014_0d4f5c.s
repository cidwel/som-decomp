.setcpu "65816"
.segment "CODE"
.org $4F5C
map_control_0d4f5c:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
