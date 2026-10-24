.setcpu "65816"
.segment "CODE"
.org $FC2F
map_control_0dfc2f:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
