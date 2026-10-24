.setcpu "65816"
.segment "CODE"
.org $5661
map_control_0e5661:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
