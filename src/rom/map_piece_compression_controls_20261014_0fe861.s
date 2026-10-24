.setcpu "65816"
.segment "CODE"
.org $E861
map_control_0fe861:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
