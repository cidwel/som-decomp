.setcpu "65816"
.segment "CODE"
.org $94BC
map_control_0e94bc:
    .byte $E8 ; backreference distance high bits
    .byte $B5 ; distance low bit/count
