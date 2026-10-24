.setcpu "65816"
.segment "CODE"
.org $91AA
map_control_0e91aa:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
    .byte $C3 ; same-value copy count/distance
