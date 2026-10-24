.setcpu "65816"
.segment "CODE"
.org $FC61
map_control_0dfc61:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
