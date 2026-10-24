.setcpu "65816"
.segment "CODE"
.org $86EC
map_control_0d86ec:
    .byte $E8 ; backreference distance high bits
    .byte $5E ; distance low bit/count
