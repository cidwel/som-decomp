.setcpu "65816"
.segment "CODE"
.org $0B18
map_control_0e0b18:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
