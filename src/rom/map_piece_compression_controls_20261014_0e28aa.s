.setcpu "65816"
.segment "CODE"
.org $28AA
map_control_0e28aa:
    .byte $E9 ; backreference distance high bits
    .byte $0F ; distance low bit/count
