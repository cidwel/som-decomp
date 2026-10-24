.setcpu "65816"
.segment "CODE"
.org $2C72
map_control_0e2c72:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
