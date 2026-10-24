.setcpu "65816"
.segment "CODE"
.org $39C9
map_control_0f39c9:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
