.setcpu "65816"
.segment "CODE"
.org $C8E4
map_control_0fc8e4:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
