.setcpu "65816"
.segment "CODE"
.org $9A24
map_control_0d9a24:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
