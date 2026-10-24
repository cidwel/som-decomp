.setcpu "65816"
.segment "CODE"
.org $2891
map_control_0e2891:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
