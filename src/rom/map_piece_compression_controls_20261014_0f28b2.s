.setcpu "65816"
.segment "CODE"
.org $28B2
map_control_0f28b2:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
