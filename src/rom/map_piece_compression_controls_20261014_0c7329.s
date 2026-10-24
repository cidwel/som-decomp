.setcpu "65816"
.segment "CODE"
.org $7329
map_control_0c7329:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
