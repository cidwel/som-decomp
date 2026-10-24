.setcpu "65816"
.segment "CODE"
.org $46B0
map_control_0d46b0:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
