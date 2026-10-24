.setcpu "65816"
.segment "CODE"
.org $8C12
map_control_0f8c12:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
