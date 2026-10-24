.setcpu "65816"
.segment "CODE"
.org $2B14
map_control_0e2b14:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
