.setcpu "65816"
.segment "CODE"
.org $6CF9
map_control_0f6cf9:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
