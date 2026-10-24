.setcpu "65816"
.segment "CODE"
.org $0BEF
map_control_0f0bef:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
