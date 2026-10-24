.setcpu "65816"
.segment "CODE"
.org $C0AC
map_control_0fc0ac:
    .byte $E6 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
