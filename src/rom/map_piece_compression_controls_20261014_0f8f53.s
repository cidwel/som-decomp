.setcpu "65816"
.segment "CODE"
.org $8F53
map_control_0f8f53:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
