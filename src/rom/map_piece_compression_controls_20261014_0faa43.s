.setcpu "65816"
.segment "CODE"
.org $AA43
map_control_0faa43:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
