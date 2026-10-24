.setcpu "65816"
.segment "CODE"
.org $0DCF
map_control_0c0dcf:
    .byte $E9 ; backreference distance high bits
    .byte $89 ; distance low bit/count
