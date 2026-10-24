.setcpu "65816"
.segment "CODE"
.org $EA19
map_control_0eea19:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
