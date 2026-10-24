.setcpu "65816"
.segment "CODE"
.org $7C1F
map_control_0e7c1f:
    .byte $E5 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
