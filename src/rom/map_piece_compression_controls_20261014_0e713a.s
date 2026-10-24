.setcpu "65816"
.segment "CODE"
.org $713A
map_control_0e713a:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
