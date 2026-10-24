.setcpu "65816"
.segment "CODE"
.org $8867
map_control_0c8867:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
