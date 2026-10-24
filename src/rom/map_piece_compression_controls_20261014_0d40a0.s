.setcpu "65816"
.segment "CODE"
.org $40A0
map_control_0d40a0:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
