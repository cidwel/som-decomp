.setcpu "65816"
.segment "CODE"
.org $F695
map_control_0ef695:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
