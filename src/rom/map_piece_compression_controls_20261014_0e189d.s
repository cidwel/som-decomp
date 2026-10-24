.setcpu "65816"
.segment "CODE"
.org $189D
map_control_0e189d:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
