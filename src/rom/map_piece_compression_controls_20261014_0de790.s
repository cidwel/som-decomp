.setcpu "65816"
.segment "CODE"
.org $E790
map_control_0de790:
    .byte $D6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
