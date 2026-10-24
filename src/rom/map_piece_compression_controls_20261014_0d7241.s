.setcpu "65816"
.segment "CODE"
.org $7241
map_control_0d7241:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
