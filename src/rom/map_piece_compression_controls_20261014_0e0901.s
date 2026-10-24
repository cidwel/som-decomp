.setcpu "65816"
.segment "CODE"
.org $0901
map_control_0e0901:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
