.setcpu "65816"
.segment "CODE"
.org $54A3
map_control_0e54a3:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
