.setcpu "65816"
.segment "CODE"
.org $F7BE
map_control_0df7be:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
