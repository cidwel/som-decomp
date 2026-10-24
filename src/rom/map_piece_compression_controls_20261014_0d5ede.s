.setcpu "65816"
.segment "CODE"
.org $5EDE
map_control_0d5ede:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
