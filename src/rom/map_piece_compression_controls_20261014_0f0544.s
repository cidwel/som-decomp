.setcpu "65816"
.segment "CODE"
.org $0544
map_control_0f0544:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
