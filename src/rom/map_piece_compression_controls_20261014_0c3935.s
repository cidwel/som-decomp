.setcpu "65816"
.segment "CODE"
.org $3935
map_control_0c3935:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
