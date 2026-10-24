.setcpu "65816"
.segment "CODE"
.org $3B8F
map_control_0e3b8f:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
