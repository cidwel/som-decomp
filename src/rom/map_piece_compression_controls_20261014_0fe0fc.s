.setcpu "65816"
.segment "CODE"
.org $E0FC
map_control_0fe0fc:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
