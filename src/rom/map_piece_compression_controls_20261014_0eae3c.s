.setcpu "65816"
.segment "CODE"
.org $AE3C
map_control_0eae3c:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
