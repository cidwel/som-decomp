.setcpu "65816"
.segment "CODE"
.org $F7AB
map_control_0df7ab:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
