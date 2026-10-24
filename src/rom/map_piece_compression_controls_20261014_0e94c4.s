.setcpu "65816"
.segment "CODE"
.org $94C4
map_control_0e94c4:
    .byte $E8 ; backreference distance high bits
    .byte $B5 ; distance low bit/count
