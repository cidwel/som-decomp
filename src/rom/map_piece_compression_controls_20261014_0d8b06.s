.setcpu "65816"
.segment "CODE"
.org $8B06
map_control_0d8b06:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
