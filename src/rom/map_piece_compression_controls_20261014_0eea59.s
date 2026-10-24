.setcpu "65816"
.segment "CODE"
.org $EA59
map_control_0eea59:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
