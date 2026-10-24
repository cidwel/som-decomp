.setcpu "65816"
.segment "CODE"
.org $6664
map_control_0c6664:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
