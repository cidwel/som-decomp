.setcpu "65816"
.segment "CODE"
.org $6BF1
map_control_0c6bf1:
    .byte $E1 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
