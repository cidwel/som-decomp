.setcpu "65816"
.segment "CODE"
.org $6980
map_control_0d6980:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
