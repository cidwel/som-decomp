.setcpu "65816"
.segment "CODE"
.org $94B8
map_control_0e94b8:
    .byte $E8 ; backreference distance high bits
    .byte $B5 ; distance low bit/count
