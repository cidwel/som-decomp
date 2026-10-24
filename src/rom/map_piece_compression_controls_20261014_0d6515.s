.setcpu "65816"
.segment "CODE"
.org $6515
map_control_0d6515:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
