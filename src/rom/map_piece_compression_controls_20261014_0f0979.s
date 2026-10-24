.setcpu "65816"
.segment "CODE"
.org $0979
map_control_0f0979:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
