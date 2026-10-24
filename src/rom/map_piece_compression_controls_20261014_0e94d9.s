.setcpu "65816"
.segment "CODE"
.org $94D9
map_control_0e94d9:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
