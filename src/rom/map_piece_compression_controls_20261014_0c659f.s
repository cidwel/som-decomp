.setcpu "65816"
.segment "CODE"
.org $659F
map_control_0c659f:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
