.setcpu "65816"
.segment "CODE"
.org $7786
map_control_0d7786:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
