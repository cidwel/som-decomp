.setcpu "65816"
.segment "CODE"
.org $B95B
map_control_0eb95b:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
