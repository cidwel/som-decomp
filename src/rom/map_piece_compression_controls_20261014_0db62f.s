.setcpu "65816"
.segment "CODE"
.org $B62F
map_control_0db62f:
    .byte $C4 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
