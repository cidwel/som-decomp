.setcpu "65816"
.segment "CODE"
.org $4157
map_control_0d4157:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
