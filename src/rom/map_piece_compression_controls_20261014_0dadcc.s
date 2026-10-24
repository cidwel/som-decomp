.setcpu "65816"
.segment "CODE"
.org $ADCC
map_control_0dadcc:
    .byte $E4 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
