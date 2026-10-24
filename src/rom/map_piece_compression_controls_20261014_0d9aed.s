.setcpu "65816"
.segment "CODE"
.org $9AED
map_control_0d9aed:
    .byte $D2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
