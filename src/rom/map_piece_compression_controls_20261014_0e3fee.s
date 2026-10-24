.setcpu "65816"
.segment "CODE"
.org $3FEE
map_control_0e3fee:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
