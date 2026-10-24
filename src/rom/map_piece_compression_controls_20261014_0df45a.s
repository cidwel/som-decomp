.setcpu "65816"
.segment "CODE"
.org $F45A
map_control_0df45a:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
