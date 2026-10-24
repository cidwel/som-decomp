.setcpu "65816"
.segment "CODE"
.org $CB8A
map_control_0dcb8a:
    .byte $E8 ; backreference distance high bits
    .byte $2C ; distance low bit/count
