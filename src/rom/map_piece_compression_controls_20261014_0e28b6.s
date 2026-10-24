.setcpu "65816"
.segment "CODE"
.org $28B6
map_control_0e28b6:
    .byte $E9 ; backreference distance high bits
    .byte $0F ; distance low bit/count
