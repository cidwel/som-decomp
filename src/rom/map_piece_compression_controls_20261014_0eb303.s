.setcpu "65816"
.segment "CODE"
.org $B303
map_control_0eb303:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
