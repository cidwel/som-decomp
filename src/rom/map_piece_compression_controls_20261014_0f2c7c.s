.setcpu "65816"
.segment "CODE"
.org $2C7C
map_control_0f2c7c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
