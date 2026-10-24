.setcpu "65816"
.segment "CODE"
.org $7B9F
map_control_0f7b9f:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
