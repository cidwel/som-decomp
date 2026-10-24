.setcpu "65816"
.segment "CODE"
.org $0AAB
map_control_0d0aab:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
