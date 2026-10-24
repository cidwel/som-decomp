.setcpu "65816"
.segment "CODE"
.org $6EB6
map_control_0d6eb6:
    .byte $EC ; backreference distance high bits
    .byte $0C ; distance low bit/count
