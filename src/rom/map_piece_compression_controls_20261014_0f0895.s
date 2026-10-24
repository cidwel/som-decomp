.setcpu "65816"
.segment "CODE"
.org $0895
map_control_0f0895:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
