.setcpu "65816"
.segment "CODE"
.org $92EF
map_control_0c92ef:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
