.setcpu "65816"
.segment "CODE"
.org $3E6C
map_control_0d3e6c:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
