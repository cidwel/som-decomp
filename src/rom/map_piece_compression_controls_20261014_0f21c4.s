.setcpu "65816"
.segment "CODE"
.org $21C4
map_control_0f21c4:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D6 ; same-value copy count/distance
