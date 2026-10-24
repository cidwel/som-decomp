.setcpu "65816"
.segment "CODE"
.org $58D0
map_control_0c58d0:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
