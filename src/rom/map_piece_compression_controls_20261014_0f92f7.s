.setcpu "65816"
.segment "CODE"
.org $92F7
map_control_0f92f7:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
