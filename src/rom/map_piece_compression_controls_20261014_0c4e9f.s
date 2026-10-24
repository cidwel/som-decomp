.setcpu "65816"
.segment "CODE"
.org $4E9F
map_control_0c4e9f:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
