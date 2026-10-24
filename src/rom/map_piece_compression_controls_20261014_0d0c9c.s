.setcpu "65816"
.segment "CODE"
.org $0C9C
map_control_0d0c9c:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
