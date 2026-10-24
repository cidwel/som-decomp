.setcpu "65816"
.segment "CODE"
.org $12A2
map_control_0f12a2:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
