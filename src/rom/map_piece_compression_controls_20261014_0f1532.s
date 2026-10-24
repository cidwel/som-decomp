.setcpu "65816"
.segment "CODE"
.org $1532
map_control_0f1532:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
