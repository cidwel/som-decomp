.setcpu "65816"
.segment "CODE"
.org $6A09
map_control_0c6a09:
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
