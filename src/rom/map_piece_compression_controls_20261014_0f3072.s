.setcpu "65816"
.segment "CODE"
.org $3072
map_control_0f3072:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
