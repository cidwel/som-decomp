.setcpu "65816"
.segment "CODE"
.org $44E9
map_control_0d44e9:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
