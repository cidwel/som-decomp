.setcpu "65816"
.segment "CODE"
.org $63C4
map_control_0d63c4:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
