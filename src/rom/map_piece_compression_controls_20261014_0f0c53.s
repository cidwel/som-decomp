.setcpu "65816"
.segment "CODE"
.org $0C53
map_control_0f0c53:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
