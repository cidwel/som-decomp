.setcpu "65816"
.segment "CODE"
.org $94B0
map_control_0e94b0:
    .byte $E8 ; backreference distance high bits
    .byte $B5 ; distance low bit/count
