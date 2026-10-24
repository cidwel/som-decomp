.setcpu "65816"
.segment "CODE"
.org $6CB0
map_control_0e6cb0:
    .byte $E8 ; backreference distance high bits
    .byte $65 ; distance low bit/count
