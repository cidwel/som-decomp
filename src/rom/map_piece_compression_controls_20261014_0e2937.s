.setcpu "65816"
.segment "CODE"
.org $2937
map_control_0e2937:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
