.setcpu "65816"
.segment "CODE"
.org $DD26
map_control_0fdd26:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
