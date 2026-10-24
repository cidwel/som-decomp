.setcpu "65816"
.segment "CODE"
.org $7838
map_control_0d7838:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
