.setcpu "65816"
.segment "CODE"
.org $E81B
map_control_0de81b:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
