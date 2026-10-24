.setcpu "65816"
.segment "CODE"
.org $71B0
map_control_0d71b0:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
