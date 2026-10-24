.setcpu "65816"
.segment "CODE"
.org $5D14
map_control_0d5d14:
    .byte $E1 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
