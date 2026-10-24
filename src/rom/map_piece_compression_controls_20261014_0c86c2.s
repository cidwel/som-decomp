.setcpu "65816"
.segment "CODE"
.org $86C2
map_control_0c86c2:
    .byte $E8 ; backreference distance high bits
    .byte $25 ; distance low bit/count
