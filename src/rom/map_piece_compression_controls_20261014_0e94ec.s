.setcpu "65816"
.segment "CODE"
.org $94EC
map_control_0e94ec:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
