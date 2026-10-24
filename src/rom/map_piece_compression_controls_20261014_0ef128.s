.setcpu "65816"
.segment "CODE"
.org $F128
map_control_0ef128:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
