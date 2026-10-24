.setcpu "65816"
.segment "CODE"
.org $0935
map_control_0f0935:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
