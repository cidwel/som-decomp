.setcpu "65816"
.segment "CODE"
.org $5452
map_control_0f5452:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
