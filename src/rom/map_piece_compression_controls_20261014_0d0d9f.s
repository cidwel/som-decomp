.setcpu "65816"
.segment "CODE"
.org $0D9F
map_control_0d0d9f:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
