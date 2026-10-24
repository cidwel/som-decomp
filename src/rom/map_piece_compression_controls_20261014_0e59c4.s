.setcpu "65816"
.segment "CODE"
.org $59C4
map_control_0e59c4:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
