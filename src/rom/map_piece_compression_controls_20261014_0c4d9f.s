.setcpu "65816"
.segment "CODE"
.org $4D9F
map_control_0c4d9f:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
