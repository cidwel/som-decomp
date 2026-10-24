.setcpu "65816"
.segment "CODE"
.org $C50F
map_control_0dc50f:
    .byte $E4 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
