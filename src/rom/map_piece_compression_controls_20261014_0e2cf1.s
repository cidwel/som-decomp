.setcpu "65816"
.segment "CODE"
.org $2CF1
map_control_0e2cf1:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
