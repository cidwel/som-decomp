.setcpu "65816"
.segment "CODE"
.org $0AC0
map_control_0e0ac0:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
