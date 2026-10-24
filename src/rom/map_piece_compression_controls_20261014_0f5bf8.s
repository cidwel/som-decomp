.setcpu "65816"
.segment "CODE"
.org $5BF8
map_control_0f5bf8:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
