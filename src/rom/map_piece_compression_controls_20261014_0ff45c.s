.setcpu "65816"
.segment "CODE"
.org $F45C
map_control_0ff45c:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
