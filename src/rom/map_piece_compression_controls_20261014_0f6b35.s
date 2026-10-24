.setcpu "65816"
.segment "CODE"
.org $6B35
map_control_0f6b35:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
