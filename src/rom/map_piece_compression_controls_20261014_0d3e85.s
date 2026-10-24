.setcpu "65816"
.segment "CODE"
.org $3E85
map_control_0d3e85:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
