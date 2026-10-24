.setcpu "65816"
.segment "CODE"
.org $1D43
map_control_0f1d43:
    .byte $C7 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
