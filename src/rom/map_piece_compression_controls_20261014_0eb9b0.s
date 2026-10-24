.setcpu "65816"
.segment "CODE"
.org $B9B0
map_control_0eb9b0:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
