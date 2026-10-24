.setcpu "65816"
.segment "CODE"
.org $1176
map_control_0c1176:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
