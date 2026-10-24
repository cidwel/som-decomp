.setcpu "65816"
.segment "CODE"
.org $C8C7
map_control_0fc8c7:
    .byte $C4 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
