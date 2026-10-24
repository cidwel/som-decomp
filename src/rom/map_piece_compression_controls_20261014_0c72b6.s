.setcpu "65816"
.segment "CODE"
.org $72B6
map_control_0c72b6:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
