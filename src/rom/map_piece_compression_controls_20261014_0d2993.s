.setcpu "65816"
.segment "CODE"
.org $2993
map_control_0d2993:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
