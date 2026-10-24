.setcpu "65816"
.segment "CODE"
.org $ABA2
map_control_0faba2:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
