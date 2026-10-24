.setcpu "65816"
.segment "CODE"
.org $7FC0
map_control_0d7fc0:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
