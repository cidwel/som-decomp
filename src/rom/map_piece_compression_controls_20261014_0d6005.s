.setcpu "65816"
.segment "CODE"
.org $6005
map_control_0d6005:
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
