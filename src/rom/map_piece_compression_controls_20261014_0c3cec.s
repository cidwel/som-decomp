.setcpu "65816"
.segment "CODE"
.org $3CEC
map_control_0c3cec:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
