.setcpu "65816"
.segment "CODE"
.org $F55B
map_control_0cf55b:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
