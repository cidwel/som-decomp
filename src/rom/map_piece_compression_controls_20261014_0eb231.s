.setcpu "65816"
.segment "CODE"
.org $B231
map_control_0eb231:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
