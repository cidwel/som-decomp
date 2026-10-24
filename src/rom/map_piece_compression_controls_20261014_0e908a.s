.setcpu "65816"
.segment "CODE"
.org $908A
map_control_0e908a:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
