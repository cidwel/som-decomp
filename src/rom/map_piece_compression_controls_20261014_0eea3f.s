.setcpu "65816"
.segment "CODE"
.org $EA3F
map_control_0eea3f:
    .byte $E8 ; backreference distance high bits
    .byte $76 ; distance low bit/count
