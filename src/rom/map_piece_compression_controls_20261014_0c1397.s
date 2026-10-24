.setcpu "65816"
.segment "CODE"
.org $1397
map_control_0c1397:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
