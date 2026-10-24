.setcpu "65816"
.segment "CODE"
.org $63FA
map_control_0c63fa:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $50 ; distance low bit/count
