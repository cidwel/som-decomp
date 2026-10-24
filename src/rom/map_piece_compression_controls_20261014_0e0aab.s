.setcpu "65816"
.segment "CODE"
.org $0AAB
map_control_0e0aab:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
