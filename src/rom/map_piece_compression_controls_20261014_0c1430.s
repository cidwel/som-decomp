.setcpu "65816"
.segment "CODE"
.org $1430
map_control_0c1430:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
