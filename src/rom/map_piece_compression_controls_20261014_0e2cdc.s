.setcpu "65816"
.segment "CODE"
.org $2CDC
map_control_0e2cdc:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
