.setcpu "65816"
.segment "CODE"
.org $94F0
map_control_0e94f0:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
