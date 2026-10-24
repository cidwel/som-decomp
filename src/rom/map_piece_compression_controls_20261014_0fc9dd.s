.setcpu "65816"
.segment "CODE"
.org $C9DD
map_control_0fc9dd:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
