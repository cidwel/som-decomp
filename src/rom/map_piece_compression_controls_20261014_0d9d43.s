.setcpu "65816"
.segment "CODE"
.org $9D43
map_control_0d9d43:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
