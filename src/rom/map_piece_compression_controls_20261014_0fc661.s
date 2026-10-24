.setcpu "65816"
.segment "CODE"
.org $C661
map_control_0fc661:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
