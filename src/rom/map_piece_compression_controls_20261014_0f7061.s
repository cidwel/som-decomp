.setcpu "65816"
.segment "CODE"
.org $7061
map_control_0f7061:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
