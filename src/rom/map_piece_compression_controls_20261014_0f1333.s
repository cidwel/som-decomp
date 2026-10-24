.setcpu "65816"
.segment "CODE"
.org $1333
map_control_0f1333:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $59 ; row-distance/count
