.setcpu "65816"
.segment "CODE"
.org $6360
map_control_0d6360:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
