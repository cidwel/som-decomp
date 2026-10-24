.setcpu "65816"
.segment "CODE"
.org $0802
map_control_0e0802:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
