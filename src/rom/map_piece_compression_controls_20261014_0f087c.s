.setcpu "65816"
.segment "CODE"
.org $087C
map_control_0f087c:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
