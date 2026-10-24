.setcpu "65816"
.segment "CODE"
.org $F604
map_control_0ff604:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
