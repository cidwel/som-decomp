.setcpu "65816"
.segment "CODE"
.org $5215
map_control_0c5215:
    .byte $E9 ; backreference distance high bits
    .byte $89 ; distance low bit/count
