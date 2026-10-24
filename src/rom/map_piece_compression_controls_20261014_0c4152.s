.setcpu "65816"
.segment "CODE"
.org $4152
map_control_0c4152:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
