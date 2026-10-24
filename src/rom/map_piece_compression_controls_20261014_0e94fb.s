.setcpu "65816"
.segment "CODE"
.org $94FB
map_control_0e94fb:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
