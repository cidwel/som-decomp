.setcpu "65816"
.segment "CODE"
.org $2B9A
map_control_0c2b9a:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
