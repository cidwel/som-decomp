.setcpu "65816"
.segment "CODE"
.org $B1C5
map_control_0eb1c5:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
