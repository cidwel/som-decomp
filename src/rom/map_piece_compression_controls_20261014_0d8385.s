.setcpu "65816"
.segment "CODE"
.org $8385
map_control_0d8385:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $46 ; distance low bit/count
