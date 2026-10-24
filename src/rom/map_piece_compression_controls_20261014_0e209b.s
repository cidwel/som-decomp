.setcpu "65816"
.segment "CODE"
.org $209B
map_control_0e209b:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
