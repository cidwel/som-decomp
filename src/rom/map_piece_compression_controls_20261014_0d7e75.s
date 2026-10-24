.setcpu "65816"
.segment "CODE"
.org $7E75
map_control_0d7e75:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0E ; distance low bit/count
