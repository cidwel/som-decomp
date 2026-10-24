.setcpu "65816"
.segment "CODE"
.org $E695
map_control_0fe695:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
