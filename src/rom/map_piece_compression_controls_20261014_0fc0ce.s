.setcpu "65816"
.segment "CODE"
.org $C0CE
map_control_0fc0ce:
    .byte $C6 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
