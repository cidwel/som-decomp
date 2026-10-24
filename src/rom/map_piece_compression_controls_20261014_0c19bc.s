.setcpu "65816"
.segment "CODE"
.org $19BC
map_control_0c19bc:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
