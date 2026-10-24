.setcpu "65816"
.segment "CODE"
.org $4364
map_control_0e4364:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
