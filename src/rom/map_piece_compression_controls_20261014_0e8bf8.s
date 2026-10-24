.setcpu "65816"
.segment "CODE"
.org $8BF8
map_control_0e8bf8:
    .byte $E8 ; backreference distance high bits
    .byte $2E ; distance low bit/count
