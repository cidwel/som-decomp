.setcpu "65816"
.segment "CODE"
.org $A743
map_control_0ea743:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
