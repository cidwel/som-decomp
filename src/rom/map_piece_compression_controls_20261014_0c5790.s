.setcpu "65816"
.segment "CODE"
.org $5790
map_control_0c5790:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
