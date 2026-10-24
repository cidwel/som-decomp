.setcpu "65816"
.segment "CODE"
.org $4E2C
map_control_0c4e2c:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
