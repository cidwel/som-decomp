.setcpu "65816"
.segment "CODE"
.org $81EE
map_control_0c81ee:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
