.setcpu "65816"
.segment "CODE"
.org $0B07
map_control_0e0b07:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
