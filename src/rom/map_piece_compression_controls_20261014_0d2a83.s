.setcpu "65816"
.segment "CODE"
.org $2A83
map_control_0d2a83:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
