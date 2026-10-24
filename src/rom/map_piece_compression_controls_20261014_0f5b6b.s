.setcpu "65816"
.segment "CODE"
.org $5B6B
map_control_0f5b6b:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
