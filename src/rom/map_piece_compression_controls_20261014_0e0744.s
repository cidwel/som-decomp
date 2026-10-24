.setcpu "65816"
.segment "CODE"
.org $0744
map_control_0e0744:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
