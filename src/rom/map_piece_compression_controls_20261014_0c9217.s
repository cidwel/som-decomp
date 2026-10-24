.setcpu "65816"
.segment "CODE"
.org $9217
map_control_0c9217:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
