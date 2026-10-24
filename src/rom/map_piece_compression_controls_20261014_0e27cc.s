.setcpu "65816"
.segment "CODE"
.org $27CC
map_control_0e27cc:
    .byte $C4 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
