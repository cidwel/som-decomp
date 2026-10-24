.setcpu "65816"
.segment "CODE"
.org $0B4C
map_control_0d0b4c:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
