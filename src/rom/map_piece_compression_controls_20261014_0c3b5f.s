.setcpu "65816"
.segment "CODE"
.org $3B5F
map_control_0c3b5f:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
