.setcpu "65816"
.segment "CODE"
.org $4765
map_control_0d4765:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
