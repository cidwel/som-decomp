.setcpu "65816"
.segment "CODE"
.org $5BBD
map_control_0e5bbd:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
