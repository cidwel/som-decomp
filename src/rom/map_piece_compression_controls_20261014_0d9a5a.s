.setcpu "65816"
.segment "CODE"
.org $9A5A
map_control_0d9a5a:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
