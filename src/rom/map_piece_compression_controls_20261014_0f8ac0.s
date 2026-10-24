.setcpu "65816"
.segment "CODE"
.org $8AC0
map_control_0f8ac0:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
