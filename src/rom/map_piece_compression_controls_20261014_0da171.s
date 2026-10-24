.setcpu "65816"
.segment "CODE"
.org $A171
map_control_0da171:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
