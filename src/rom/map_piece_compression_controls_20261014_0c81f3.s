.setcpu "65816"
.segment "CODE"
.org $81F3
map_control_0c81f3:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
