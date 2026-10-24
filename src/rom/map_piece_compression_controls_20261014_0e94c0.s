.setcpu "65816"
.segment "CODE"
.org $94C0
map_control_0e94c0:
    .byte $E8 ; backreference distance high bits
    .byte $B5 ; distance low bit/count
